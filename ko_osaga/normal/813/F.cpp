#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

struct ed{int x, y, s, e;};
int n, q;

struct disj{
	int pa[MAXN * 2];
	int rk[MAXN * 2];
	void init(int n){
		iota(pa, pa + n + 1, 0);
		fill(rk, rk + n + 1, 0);
	}
	int find(int x){
		return pa[x] == x ? x : find(pa[x]);
	}
	bool uni(int p, int q, vector<pi> &ht1, vector<pi> &ht2){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		if(rk[p] < rk[q]) swap(p, q);
		ht1.push_back(pi(q, pa[q]));
		pa[q] = p;
		if(rk[p] == rk[q]){
			ht2.push_back(pi(p, rk[p]));
			rk[p]++;
		}
		return 1;
	}
	void revert(vector<pi> &a, vector<pi> &b){
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for(auto &i : a) pa[i.first] = i.second;
		for(auto &i : b) rk[i.first] = i.second;
	}
}disj;

void solve(int s, int e, vector<ed> &v, bool nogood){
	vector<pi> ht1, ht2;
	vector<ed> l, r;
	int m = (s+e)/2;
	for(auto &i : v){
		if(i.s <= s && e <= i.e){
			disj.uni(i.x, i.y + n, ht1, ht2);
			disj.uni(i.y, i.x + n, ht1, ht2);
			if(disj.find(i.x) == disj.find(i.x + n)) nogood = 1;
		}
		else{
			if(i.s <= m) l.push_back(i);
			if(i.e > m) r.push_back(i);
		}
	}
	if(s == e){
		puts(!nogood ? "YES" : "NO");
		disj.revert(ht1, ht2);
		return;
	}
	solve(s, m, l, nogood);
	solve(m+1, e, r, nogood); 
	disj.revert(ht1, ht2);
}

int main(){
	map<pi, int> mp;
	vector<ed> edg;
	scanf("%d %d",&n,&q);
	for(int i=1; i<=q; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		if(mp.find(pi(x, y)) != mp.end()){
			int st = mp[pi(x, y)];
			int ed = i - 1;
			edg.push_back({x, y, st, ed});
			mp.erase(pi(x, y));
		}
		else{
			mp[pi(x, y)] = i;
		}
	}
	for(auto &i : mp) edg.push_back({i.first.first, i.first.second, i.second, q});
	disj.init(2*n);
	solve(1, q, edg, 0);
}