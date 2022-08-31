#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3000005;
const int mod = 1e9 + 7;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
	int n;
	scanf("%d",&n);
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	for(int i = 0; i < n; i++) scanf("%d",&b[i]);
	disj.init(n);
	for(int i = 0; i < n; i++){
		disj.uni(a[i], b[i]);
	}
	lint ret = 1;
	for(int i = 1; i<= n; i++){
		if(disj.find(i) == i) ret *= 2;
		ret %= mod;
	}
	printf("%lld\n", ret);
	}
}