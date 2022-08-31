#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 100005;
const int mod = 1e9 + 7;

struct queries{
	int type;
	int arg1, arg2, arg3;
};

struct seg{
	vector<int> tree[270000];
	vector<lint> bit[270000];
	int lim;
	void init(vector<pi> pnt, int n){
		sort(pnt.begin(), pnt.end());
		pnt.resize(unique(pnt.begin(), pnt.end()) - pnt.begin());
		for(lim = 1; lim <= n; lim <<= 1);
		for(auto &i : pnt){
			for(int j=i.first + lim; j; j>>=1){
				tree[j].push_back(i.second);
			}
		}
		for(int i=1; i<270000; i++){
			tree[i].push_back(-1);
			sort(tree[i].begin(), tree[i].end());
			tree[i].resize(unique(tree[i].begin(), tree[i].end()) - tree[i].begin());
			bit[i].resize(tree[i].size());
		}
	}
	void add(int x, int y, int v){
		x += lim;
		while(x){
			int vy = lower_bound(tree[x].begin(), tree[x].end(), y) - tree[x].begin();
			while(vy < bit[x].size()){
				bit[x][vy] += v;
				vy += vy & -vy;
			}
			x >>= 1;
		}
	}
	lint nodeQ(int v, int x){
		int vy = upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin() - 1;
		lint ret = 0;
		while(vy){
			ret += bit[v][vy];
			vy -= vy & -vy;
		}
		return ret;
	}
	lint query(int s, int e, int x){
		s += lim;
		e += lim;
		lint ret = 0;
		while(s < e){
			if(s % 2 == 1) ret += nodeQ(s++, x);
			if(e % 2 == 0) ret += nodeQ(e--, x);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret += nodeQ(s, x);
		return ret;
	}
}seg;

int n, m, a[MAXN], nxt[MAXN];
set<int> s[MAXN];

vector<pi> point;
vector<queries> qr;

void update(int x, int v){
	point.push_back(pi(x, v));
	qr.push_back({1, x, nxt[x], -(nxt[x] - x)});
	nxt[x] = v;
	qr.push_back({1, x, nxt[x], (nxt[x] - x)});
}

void query(int s, int e, int x){
	qr.push_back({2, s, e, x});
	/*
	lint ans = 0;
	for(int i=s; i<=e; i++) if(nxt[i] <= x) ans += nxt[i] - i;
	printf("%lld\n", ans);*/
}

void solve_now(){
	seg.init(point, n);
	for(int i=0; i<n; i++){
		seg.add(point[i].first, point[i].second, point[i].second - point[i].first);
	}
	for(auto &i : qr){
		if(i.type == 1) seg.add(i.arg1, i.arg2, i.arg3);
		else printf("%lld\n", seg.query(i.arg1, i.arg2, i.arg3));
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	for(int i=1; i<=n; i++){
		auto it1 = s[i].begin(), it2 = s[i].begin();
		while(it2 != s[i].end()){
			it2++;
			if(it2 == s[i].end()) nxt[*it1] = n + 1;
			else nxt[*it1] = *it2;
			it1++;
		}
	}
	for(int i=1; i<=n; i++){
		point.push_back(pi(i, nxt[i]));
	}
	while(m--){
		int t, ll, r;
		scanf("%d %d %d",&t,&ll,&r);
		if(t == 2){
			int l = ll;
			lint ans = 0;
			query(l, r, r);
		}
		else{
			int p = ll, x = r;
			if(a[p] == x) continue;
			auto l = s[a[p]].upper_bound(p);
			int nxtv = n + 1;
			if(l != s[a[p]].end()) nxtv = *l;
			l--;
			if(l != s[a[p]].begin()){
				l--;
				update(*l, nxtv);
			}
			s[a[p]].erase(p);
			a[p] = x;
			l = s[a[p]].upper_bound(p);
			if(l != s[a[p]].end()) update(p, *l);
			else update(p, n+1);
			if(l != s[a[p]].begin()){
				l--;
				update(*l, p);
			}
			s[a[p]].insert(p);
		}
	}
	solve_now();
}