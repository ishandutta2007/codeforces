#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3000005;
const int mod = 1e9 + 7;
/*
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
*/

char str[55][55];
int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		int n, m;
		scanf("%d %d",&n,&m);
		int s[2] = {};
		for(int i = 0; i < n; i++){
			scanf("%s", str[i]);
			for(int j = 0; j < m; j++){
			int flg = (i + j) % 2;
			if(str[i][j] == 'R') flg ^= 1;
			if(str[i][j] != '.') s[flg] = 1;
			}
		}
		if(s[0] && s[1]) {
			puts("NO");
			continue;
		}
		puts("YES");
		int flg = (s[0] ? 0 : 1);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int ww = flg ^ (i%2) ^ (j%2);
				if(ww) putchar('R');
				else putchar('W');
			}
			puts("");
		}
	}
}