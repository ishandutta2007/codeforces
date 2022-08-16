#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define ld double
const int N = 500005;
const int logN = 38;
ld dp[logN][N], prevdp[logN][N];
int par[N];
int main(){
	int q, type, v, index = 1;
	for(int j = 1; j< logN; j++) dp[j][1] = 1.;
	sd(q);
	while(q--){
		sd(type), sd(v);
		if(type == 1){
			par[++index] = v; int p = v; v = index;
			for(int j = 1; j < logN; j++){
				dp[j][v] = 1.;
				prevdp[j][p] = dp[j][p];
				dp[j][p] *= (0.5 * (1 + dp[j - 1][v]));
			}
			int cnt = 2;
			int temp = par[p]; v = p; p = temp;
			while(p && cnt < logN){
				cnt ++;
				for(int j = 1; j < logN; j++){
					prevdp[j][p] = dp[j][p];
					dp[j][p] *= (1 + dp[j - 1][v]) / (1 + prevdp[j - 1][v]);
				}
				int temp = par[p]; v = p; p = temp;
			}	
		}
		else{
			ld exp = 0;
			for(int i = 1; i < logN; i++){
				ld p = dp[i][v] - dp[i - 1][v];
				exp += p * i;
			}
			printf("%.7lf\n", exp - 1.);
		}
	}

}