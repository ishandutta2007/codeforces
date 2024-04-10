#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 1 << 21 | 1 , G = 2 , G1 = 3 , M = 490019 , M1[2] = {998244353 , 1004535809};

int pw(ll a , ll b , int MOD = M){
	a %= MOD; int tms = 1;
	while(b){
		if(b & 1) tms = tms * a % MOD;
		a = a * a % MOD; b >>= 1;
	} return tms;
}

int dir[_] , need , w[2][_];
void init(int len){
	need = 1; while(need < len) need <<= 1;
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for(int j = 0 ; j < 2 ; ++j)
		for(int i = 1 ; i < need ; i <<= 1){
			int wn = pw(G1 , M1[j] / i / 2 , M1[j]); w[j][i] = 1;
			for(int k = 1 ; k < i ; ++k) w[j][i + k] = 1ll * w[j][i + k - 1] * wn % M1[j];
		}
}

int upd(int x , int M){return x + (x >> 31 & M);}
void DFT(int *A , int M , int *w , int tp){
	for(int i = 1 ; i < need ; ++i) if(i < dir[i]) swap(A[i] , A[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = A[j + k] , y = 1ll * A[i + j + k] * w[i + k] % M;
				A[j + k] = upd(x + y - M , M); A[i + j + k] = upd(x - y , M);
			}
	if(tp == -1){
		reverse(A + 1 , A + need); int invnd = pw(need , M - 2 , M);
		for(int i = 0 ; i < need ; ++i) A[i] = 1ll * A[i] * invnd % M;
	}
}

int N , K , C , A[_] , num[_];
ll B2(int x){return x * (x - 1ll) / 2;}

ll mul(ll A , ll B , ll P){
	A %= P; B %= P;
	ll L = ((long double)A / P * B + 0.5) , C = A * B - L * P;
	return (C % P + P) % P;
}

int main(){
	static int P[_] , Q[_] , T1[_] , T2[_] , pot[2][_];
	scanf("%d %d %d" , &N , &K , &C);
	for(int i = 0 ; i < N ; ++i) scanf("%d" , &A[i]);
	for(int j = 0 ; j < K ; ++j){int x; scanf("%d" , &x); P[1ll * j * j * j % (M - 1)] += x;}
	num[0] = P[0]; init(2 * M);
	for(int j = 0 ; j + 1 < M ; ++j) P[j] = 1ll * P[j] * pw(G , B2(j + 1)) % M;
	for(int j = -M + 2 ; j <= M - 2 ; ++j) Q[j + M - 2] = pw(G , M - 1 - B2(j) % (M - 1));
	for(int i = 0 ; i < 2 ; ++i){
		memcpy(T1 , P , sizeof(int) * need); memcpy(T2 , Q , sizeof(int) * need);
		DFT(T1 , M1[i] , w[i] , 1); DFT(T2 , M1[i] , w[i] , 1);
		for(int j = 0 ; j < need ; ++j) pot[i][j] = 1ll * T1[j] * T2[j] % M1[i];
		DFT(pot[i] , M1[i] , w[i] , -1);
	}
	ll v1 = 1ll * M1[1] * pw(M1[1] , M1[0] - 2 , M1[0]) ,
		v2 = 1ll * M1[0] * pw(M1[0] , M1[1] - 2 , M1[1]) , mod = 1ll * M1[0] * M1[1];
	for(int j = 0 , tms = 1 ; j + 1 < M ; ++j , tms = tms * 2 % M){
		int id = M - 2 + j , val = (mul(pot[0][id] , v1 , mod) + mul(pot[1][id] , v2 , mod)) % mod % M;
		num[tms] = 1ll * val * pw(G , B2(j)) % M;
	}
	int sum = 0; for(int i = 0 ; i < N ; ++i) sum = (sum + 1ll * A[i] * num[pw(C , 1ll * i * i)]) % M;
	cout << sum; return 0;
}