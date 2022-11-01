#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int f[53][53] , g[103][103] , h[53][53] , N , M , iv[53];
void inc(int &a , int b){a = a + b >= P ? a + b - P : a + b;}
#define REP(i,j,k) for(int i = j ; i <= k ; ++i)

int main(){
	cin >> N >> M; f[0][1] = 1; iv[1] = 1; REP(i , 2 , 50) iv[i] = P - 1ll * (P / i) * iv[P % i] % P;
	if(M == N + 1){puts("1"); return 0;} else if(M > N){puts("0"); return 0;}
	REP(i , 1 , N){
		REP(j , 0 , i - 1) REP(k , 1 , N) if(f[j][k])
			REP(p , 0 , i - 1) REP(q , 1 , N) if(f[p][q] && (j == i - 1 || p == i - 1))
				inc(g[j + p + 1][min(k , q)] , 1ll * f[j][k] * f[p][q] % P);
		REP(k , 1 , N) if(g[i][k])
			for(int p = N ; p >= i ; --p)
				for(int q = N ; q >= k ; --q)
					for(int c = 1 , tms = 1 ; c * i <= p && c * k <= q ; ++c){
						tms = 1ll * tms * (g[i][k] + c - 1) % P * iv[c] % P;
						f[p][q] = (f[p][q] + 1ll * f[p - c * i][q - c * k] * tms) % P;
					}
	}
	cout << f[N][M]; return 0;
}