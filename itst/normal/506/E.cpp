#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i , j , k) for(int i = j ; i <= k ; ++i)
const int P = 1e4 + 7;
int upd(int x){return x + (x >> 31 & P);}
void inc(int &a , int b){a = upd(a + b - P);}
char str[203]; int dp[203][203][203] , L , N , coef[403] , val[203][203][2];

void mul(int *pol , int v2){for(int i = 2 * L + 1 ; i ; --i) pol[i] = (pol[i] + pol[i - 1] * v2) % P;}
//pol*(1+v2x)

int f[803] , tmp[803] , ans[803] , arr[803];
void mul(int *A , int *B){
	memset(tmp , 0 , sizeof(tmp));
	REP(i , 0 , 2 * L) if(B[i])
		REP(j , 0 , 2 * L) tmp[i + j] = (tmp[i + j] + B[i] * A[j]) % P;
	for(int i = 4 * L ; i > 2 * L ; --i)
		if(tmp[i]){
			REP(p , 0 , 2 * L) tmp[i - 2 * L - 1 + p] = (tmp[i - 2 * L - 1 + p] - f[p] * tmp[i] % P + P) % P;
			tmp[i] = 0;
		}
	memcpy(A , tmp , sizeof(tmp));
}

void calc(){
	f[0] = ans[0] = arr[1] = 1; mul(f , P - 26);
	REP(i , 1 , L){mul(f , P - 24); mul(f , P - 25);}
	REP(i , 0 , 2 * L) f[i] = f[i + 1];
	reverse(f , f + 2 * L + 1); f[2 * L + 1] = 1; int step = (N + L) / 2;
	while(step){
		if(step & 1) mul(ans , arr);
		mul(arr , arr); step >>= 1;
	}
	memset(arr , 0 , sizeof(arr)); arr[1] = 1;
	REP(i , 0 , 2 * L){coef[i] = ans[2 * L]; mul(ans , arr);}
}

int main(){
	scanf("%s %d" , str + 1 , &N); L = strlen(str + 1); dp[1][L][0] = 1;
	REP(i , 1 , L)
		for(int j = L ; j >= i ; --j)
			REP(k , 0 , L)
				if(dp[i][j][k])
					if(str[i] == str[j]) inc(dp[i + 1][j - 1][k] , dp[i][j][k]);
					else{inc(dp[i + 1][j][k + 1] , dp[i][j][k]); inc(dp[i][j - 1][k + 1] , dp[i][j][k]);}
	REP(i , 1 , L + 1) REP(k , 0 , L){
		if(dp[i][i][k]){
			int p = 1 + (L - 1 - k) / 2; if((N + L) & 1) inc(val[k][p][0] , dp[i][i][k]);
			inc(val[k][p][1] , dp[i][i][k] * ((N + L) & 1 ? 26 : 1) % P);
		}
		if(dp[i][i - 1][k])
			inc(val[k][(L - k) / 2][1] , dp[i][i - 1][k] * ((N + L) & 1 ? 26 : 1) % P);
	}
	calc(); int ans = 0;
	REP(i , 0 , L) REP(j , 0 , L) REP(k , 0 , 1) if(val[i][j][k]){
		static int pol[403]; memset(pol , 0 , sizeof(pol)); pol[i + j + k - 1] = 1;
		REP(p , i + 1 , L) mul(pol , P - 24);
		REP(p , j + 1 , L) mul(pol , P - 25);
		REP(p , k + 1 , 1) mul(pol , P - 26);
		int sum = 0; REP(p , 0 , 2 * L) inc(sum , pol[p] * coef[2 * L - p] % P);
		inc(ans , sum * val[i][j][k] % P);
	}
	printf("%d\n" , ans); return 0;
}