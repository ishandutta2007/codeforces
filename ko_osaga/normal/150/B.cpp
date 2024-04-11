#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int mod = 1e9 + 7;
const int MAXN = 2005;

struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		for(int i=0; i<=n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	disj.init(n);
	int cnt = n;
	for(int i=1; i<=n-k+1; i++){
		int st = i, ed = i + k - 1;
		while(st < ed){
			if(disj.uni(st, ed)) cnt--;
			st++;
			ed--;
		}
	}
	lint ans = 1;
	for(int i=1; i<=cnt; i++) ans = ans * m % mod;
	cout << ans;
}