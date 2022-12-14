#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; int coef[15][15] , A[15] , N , f[1 << 14] , sum;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int calc(int p , int q){
	int tms = 1;
	for(int i = 0 ; i < N ; ++i)
		if(p >> i & 1)
			for(int j = 0 ; j < N ; ++j)
				if(q >> j & 1) tms = 1ll * tms * coef[i][j] % P;
	return tms;
}

signed main(){
	cin >> N;
	for(int i = 0 ; i < N ; ++i) cin >> A[i];
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < N ; ++j)
			coef[i][j] = 1ll * poww(A[i] + A[j] , P - 2) * A[i] % P;
	for(int i = 1 ; i < 1 << N ; ++i){
		if(__builtin_popcount(i) == 1) f[i] = 1;
		else{
			int S = (i - 1) & i; f[i] = 1;
			while(S){
				f[i] = (f[i] - 1ll * f[S] * calc(S , i ^ S) % P + P) % P;
				S = (S - 1) & i;
			}
		}
		sum = (sum + 1ll * f[i] * calc(i , ((1 << N) - 1) - i) % P * __builtin_popcount(i)) % P;
	}
	cout << sum;
	return 0;
}