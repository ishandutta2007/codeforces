#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll f[203][203][2] , g[203][203][2] , A[203] , B[203] , C[203] , SA[203] , SB[203] , N , T , K;

int main(){
	cin >> N >> T >> K; for(int i = 1 ; i <= N ; ++i) cin >> A[i] >> B[i] >> C[i];
	++N; A[N] = C[N] = 1e15; memset(f , 0x3f , sizeof(f)); memset(g , 0x3f , sizeof(g));
	for(int i = 1 ; i <= N ; ++i){SA[i] = SA[i - 1] + A[i]; SB[i] = SB[i - 1] + B[i];}
	memset(f[0] , 0 , sizeof(f[0])); memset(g[0] , 0 , sizeof(g[0]));
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 0 ; j <= T ; ++j)
			for(int k = 0 ; k <= 1 ; ++k){
				if(k * A[i] + B[i] * j <= C[i] && f[i - 1][j][k] <= 1e15){
					f[i][j][k] = f[i - 1][j][k];
					ll vl = (k * SA[i - 1] + j * SB[i - 1] + K - 1) / K;
					if(vl * K <= k * SA[i] + j * SB[i]) g[i][j][k] = vl;
				}
				for(int l = 0 ; l < j ; ++l){
					ll stp = g[i][l][k]; if(stp > 1e15) continue;
					ll lft = SA[i] * k + SB[i] * l - stp * K , need = max((lft + (j - l) * B[i] - C[i] + K - 1) / K , 0ll);
					if(need * K > lft) continue;
					if(f[i - 1][j - l][0] > 1e15) continue;
					f[i][j][k] = min(f[i][j][k] , stp + need + f[i - 1][j - l][0]);
					ll vl = ((j - l) * SB[i - 1] + K - 1) / K; if(vl * K > lft - need * K + vl * SB[i]) continue;
					g[i][j][k] = min(g[i][j][k] , stp + need + vl);
				}
			}
	cout << f[N][T][1] << endl; return 0;
}