#include <bits/stdc++.h>
typedef long long lint;
typedef long double llf;
using namespace std;
typedef pair<int, int> pi;

struct intv{
	int s, e, x;
};

struct segnode{
	int val, dis, pos, frm;
	bool operator<(const segnode &s)const{
		return val < s.val;
	}
};

struct seg{
    multiset<segnode> dm[100005];
	segnode tree[270000];
	int lim;
	void init(int n){
		fill(tree, tree + 270000, (segnode){-987654321, 0, 0, 0});
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int x, segnode s){
		dm[x].insert(s);
		tree[x + lim] = *dm[x].rbegin();
		x += lim;
		while(x > 1){
			x >>= 1;
			tree[x] = max(tree[2*x], tree[2*x+1]);
		}
	}
	segnode query(int s, int e){
		s += lim;
		e += lim;
		segnode ret = {-987654321, 0, 0, 0};
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
	void rem(int x){
		dm[x].erase(--dm[x].end());
		tree[x + lim] = {-987654321, 0, 0, 0};
		if(dm[x].size()) tree[x + lim] = *dm[x].rbegin();
		x += lim;
		while(x > 1){
			x >>= 1;
			tree[x] = max(tree[2*x], tree[2*x+1]);
		}
	}
}seg;

struct node{
	int single;
	int s, e;
	lint dist;
	bool operator<(const node &n)const{
		if(dist == n.dist) return single < n.single;
		return dist > n.dist;
	}
};

vector<pi> gph[100005];
vector<intv> gph2[100005];
set<int> active;
lint dist[100005];

int n, q, s;
priority_queue<node> pq;

int main(){
	memset(dist, -1, sizeof(dist));
	scanf("%d %d %d",&n,&q,&s);
	seg.init(n);
	for(int i=1; i<=n; i++) active.insert(i);
	for(int i=1; i<=q; i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int s, e, x;
			scanf("%d %d %d",&s,&e,&x);
			gph[s].push_back(pi(e, x));
		}
		if(t == 2){
			int s, ss, se, x;
			scanf("%d %d %d %d",&s,&ss,&se,&x);
			gph2[s].push_back({ss, se, x});
		}
		if(t == 3){
			int s, ss, se, x;
			scanf("%d %d %d %d",&s,&ss,&se,&x);
			seg.add(ss, {se, x, s, ss});
		}
	}
	pq.push({s, -1, -1, 0});
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(x.single == -1){
			auto l = active.lower_bound(x.s);
			while(l != active.end() && *l <= x.e){
				pq.push({*l, -1, -1, x.dist});
				l++;
			}
			continue;
		}
		if(active.find(x.single) == active.end()) continue;
		active.erase(x.single);
		dist[x.single] = x.dist;
		for(auto &i : gph[x.single]){
			pq.push({i.first, -1, -1, i.second + x.dist});
		}
		for(auto &i : gph2[x.single]){
			pq.push({-1, i.s, i.e, i.x + x.dist});
		}
		while(1){
			auto l = seg.query(1, x.single);
			if(l.val < x.single) break;
			seg.rem(l.frm);
			pq.push({l.pos, -1, -1, x.dist + l.dis});
		}
	}
	for(int i=1; i<=n; i++) printf("%lld ", dist[i]);
}