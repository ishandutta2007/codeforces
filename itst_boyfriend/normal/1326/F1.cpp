#include<bits/stdc++.h>
using namespace std;

#define int long long
int dp[1 << 14][1 << 6][14] , N , ans[1 << 13] , sum[2][1 << 6] , tmp[1 << 14][1 << 6][2];
char str[18][18]; int rev[1 << 6];

int reverse(int id , int len){
	int sum = 0;
	for(int t = 0 ; t < len ; ++t , id >>= 1) sum |= (id & 1) << (len - t - 1);
	return sum;
}

signed main(){
	scanf("%lld" , &N);
	for(int i = 0 ; i < N ; ++i) scanf("%s" , str[i]);
	for(int i = 0 ; i < N ; ++i) dp[1 << i][0][i] = 1;
	for(int i = 0 ; i < 1 << (N - (N + 1) / 2 - 1) ; ++i) rev[i] = reverse(i , (N - (N + 1) / 2 - 1));
	for(int i = 1 ; i < 1 << N ; ++i)
		if(__builtin_popcount(i) < (N + 1) / 2)
			for(int j = 0 ; j < 1 << 6 ; ++j)
				for(int k = 0 ; k < N ; ++k)
					if(dp[i][j][k])
						for(int p = 0 ; p < N ; ++p)
							if(!(i >> p & 1))
								dp[i | (1 << p)][j | (str[k][p] - '0') << (__builtin_popcount(i) - 1)][p] += dp[i][j][k];
	for(int k = 0 ; k < N ; ++k){
		memset(tmp , 0 , sizeof(tmp));
		for(int i = 0 ; i < 1 << N ; ++i)
			if(__builtin_popcount(i) == N - (N + 1) / 2){
				for(int p = 0 ; p < 1 << (N - (N + 1) / 2 - 1) ; ++p)
					for(int q = 0 ; q < N ; ++q)
						if(dp[i][p][q]) tmp[i][p][str[k][q] - '0'] += dp[i][p][q];
			}
		for(int i = 0 ; i < 1 << N ; ++i)
			if(__builtin_popcount(i) == (N + 1) / 2)
				for(int j = 0 ; j < 1 << ((N + 1) / 2 - 1) ; ++j)
					if(dp[i][j][k]){
						for(int p = 0 ; p < 1 << (N - (N + 1) / 2 - 1) ; ++p)
							for(int q = 0 ; q < 2 ; ++q)
								ans[j | q << ((N + 1) / 2 - 1) | rev[p] << ((N + 1) / 2)] += dp[i][j][k] * tmp[(1 << N) - i - 1][p][q];
					}
	}
	for(int i = 0 ; i < 1 << (N - 1) ; ++i) cout << ans[i] << ' ';
	return 0;
}