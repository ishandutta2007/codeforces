#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
struct matrix{
	int arr[208][208]; matrix(){memset(arr , 0 , sizeof(arr));}
	int* operator [](int x){return arr[x];}
	friend matrix operator *(matrix p , matrix q){
		matrix x;
		for(int i = 0 ; i < 208 ; ++i)
			for(int j = 0 ; j < 208 ; ++j)
				for(int k = 0 ; k < 208 ; ++k)
					x[i][k] = (x[i][k] + 1ll * p[i][j] * q[j][k]) % MOD;
		return x;
	}
}trs , F; int N , K , M;

int main(){
	cin >> N >> K >> M; F[0][0] = 1;
	for(int i = 0 ; i <= K ; ++i)
		for(int j = 0 ; j < 16 ; ++j){
			trs[(i << 4) | j][(i << 4) | ((j & ~8) << 1)] = 1;
			if(i != K)
				trs[(i << 4) | j][((i + 1) << 4) | ((j & ~8) << 1 | 1)] = __builtin_popcount(j & ((1 << M) - 1)) + 1;
		}
	while(N){
		if(N & 1) F = F * trs;
		trs = trs * trs; N >>= 1;
	}
	int sum = 0; for(int j = 0 ; j < 16 ; ++j) sum = (sum + F[0][K << 4 | j]) % MOD;
	cout << sum; return 0;
}