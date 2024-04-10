#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int K , N , arr[103] , num;
struct matrix{
	int arr[103][103];
	matrix(){memset(arr , 0 , sizeof(arr));}
	int* operator [](int x){return arr[x];}
	friend matrix operator *(matrix A , matrix B){
		matrix C;
		for(int i = 0 ; i <= num ; ++i)
			for(int k = 0 ; k <= num ; ++k)
				for(int j = 0 ; j <= num ; ++j)
					C[i][j] = (C[i][j] + 1ll * A[i][k] * B[k][j]) % MOD;
		return C;
	}
}G , T;

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int main(){
	cin >> N >> K; int cnt = 0 , all = N * (N - 1) / 2 , inv = poww(all , MOD - 2);
	for(int i = 1 ; i <= N ; ++i){cin >> arr[i]; num += !arr[i];}
	if(!num || num == N){puts("1"); return 0;}
	for(int i = 1 ; i <= num ; ++i) cnt += !arr[i];
	G[0][cnt] = 1;
	for(int i = 0 ; i <= num ; ++i){
		int val = 1;
		if(i != N){
			int t = (num - i) * (num - i);
			T[i][i + 1] = 1ll * t * inv % MOD; val = (val - 1ll * t * inv % MOD + MOD) % MOD;
		}
		if(i){
			int t = i * (N + i - 2 * num);
			if(t >= 0){T[i][i - 1] = 1ll * t * inv % MOD; val = (val - 1ll * t * inv % MOD + MOD) % MOD;}
		}
		T[i][i] = val;
	}
	while(K){
		if(K & 1) G = G * T;
		T = T * T; K >>= 1;
	}
	cout << G[0][num] << endl; return 0;
}