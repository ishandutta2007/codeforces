#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, m, dt[1005][2005][4];

int main()
{
	dt[1][1][0] = 1;
	dt[1][2][1] = 1;
	dt[1][2][2] = 1;
	dt[1][1][3] = 1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++) {
		for(int j=1;j<=m;j++) {
			for(int k=0;k<4;k++) {
				for(int l=0;l<4;l++) {
					if(l == 0 || l == 3) {
						dt[i+1][j+((k ^ 3) == l)][l] = (dt[i+1][j+((k ^ 3) == l)][l] + dt[i][j][k]) % mod;
					}
					else {
						dt[i+1][j+((k&1) != (l&1))+((k&2) != (l&2))][l] = (dt[i+1][j+((k&1) != (l&1))+((k&2) != (l&2))][l] + dt[i][j][k]) % mod;
					}
				}
			}
		}
	}
	printf("%d\n",(1ll * dt[n][m][0] + dt[n][m][1] + dt[n][m][2] + dt[n][m][3]) % mod);
}