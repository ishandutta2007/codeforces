#include<cstdio>
using namespace std;
#define ld long double
const int _ = 1 << 6 | 3;
ld p[_][_] , win[7][_] , dp[7][_] , ans; int N;
ld max(ld a , ld b){return a > b ? a : b;}
int main(){
	scanf("%d" , &N);
	for(int i = 0 ; i < 1 << N ; ++i)
		for(int j = 0 ; j < 1 << N ; ++j){
			scanf("%Lf" , &p[i][j]); p[i][j] /= 100;
		}
	for(int i = 0 ; i < 1 << N ; ++i) win[N][i] = 1;
	for(int i = N - 1 ; i >= 0 ; --i)
		for(int j = 0 ; j < 1 << N ; ++j){
			int id = (j >> (N - i - 1) ^ 1) << (N - i - 1);
			for(int k = 0 ; k < 1 << (N - i - 1) ; ++k)
				win[i][j] += p[j][id | k] * win[i + 1][id | k];
			win[i][j] *= win[i + 1][j];
		}
	for(int i = 0 ; i < 1 << N ; ++i) dp[N][i] = 0;
	for(int i = N - 1 ; i >= 0 ; --i)
		for(int j = 0 ; j < 1 << N ; ++j){
			int id = (j >> (N - i - 1) ^ 1) << (N - i - 1);
			for(int k = 0 ; k < 1 << (N - i - 1) ; ++k)
				dp[i][j] = max(dp[i][j] , dp[i + 1][id | k]);
			dp[i][j] += dp[i + 1][j] + win[i][j] * (1 << (N - i - 1));
		}
	for(int i = 0 ; i < 1 << N ; ++i) ans = max(ans , dp[0][i]);
	printf("%.10Lf" , ans);
	return 0;
}