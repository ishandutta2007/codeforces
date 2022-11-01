#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 1e6 + 7 , P = 1e9 + 7 , IV6 = (P + 1) / 6;
ll val[4] , N , pw[1000003][4];

int main(){
	cin >> N; pw[0][0] = 1;
	val[0] = N % P * (N % P + 1) % P * (N % P + 2) % P;
	val[1] = (-3 * N - 2) % P; val[2] = -3 * N % P; val[3] = 2;
	for(int i = 1 ; 1ll * i * i <= N ; ++i)
		for(int tms = 1 , j = 0 ; j < 4 ; ++j , tms = 1ll * tms % P * i % P * i % P)
			pw[i][j] = (pw[i - 1][j] + 2ll * tms) % P;
	int sum = 0;
	for(int i = 0 ; 1ll * i * i <= N ; ++i){
		static ll tmp[4]; memcpy(tmp , val , sizeof(tmp));
		int coef = (1ll * i * i - 1) % P , lim = sqrt(N - 1ll * i * i + 1e-8);
		for(int j = 0 ; j < 4 ; ++j)
			for(int k = j - 1 , ch = j , tms = coef ; ~k ;
				ch = ch * k / (j - k + 1) , --k , tms = 1ll * tms * coef % P)
				tmp[k] = (tmp[k] + 1ll * tmp[j] * ch % P * tms) % P;
		for(int j = 0 ; j < 4 ; ++j) sum = (sum + 1ll * tmp[j] * (1 + (bool)i) * pw[lim][j]) % P;
	}
	cout << (1ll * sum * IV6 % P + P) % P;
	return 0;
}