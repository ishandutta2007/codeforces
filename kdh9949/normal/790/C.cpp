#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int n, dp[76][76][76][2], chk[76][76][76][2];
char s[77], ts[77];

int f(int v, int k, int a, int l){
	if(v + k + a == n) return 0;
	if(chk[v][k][a][l]) return dp[v][k][a][l];
	int vc = 0, kc = 0, ac = 0, tc = 0, fv = -1, fk = -1, fa = -1;
	for(int i = 1; i <= n; i++){
		int &cur = (s[i] == 'V' ? vc : s[i] == 'K' ? kc : ac);
		int &oth = (s[i] == 'V' ? v : s[i] == 'K' ? k : a);
		int &fir = (s[i] == 'V' ? fv : s[i] == 'K' ? fk : fa);
		cur++;
		if(cur > oth){
			if(fir < 0) fir = tc; 
			tc++;
		}
	}
	int ret = inf;
	if(fv >= 0) ret = min(ret, f(v + 1, k, a, 1) + fv);
	if(fk >= 0 && !l) ret = min(ret, f(v, k + 1, a, 0) + fk);
	if(fa >= 0) ret = min(ret, f(v, k, a + 1, 0) + fa);
	dp[v][k][a][l] = ret;
	chk[v][k][a][l] = 1;
	return ret;
}

int main(){
	scanf("%d%s", &n, s + 1);
	printf("%d\n", f(0, 0, 0, 0));
}