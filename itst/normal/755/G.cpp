#include<bits/stdc++.h>
using namespace std;

const int _ = 1 << 16 | 1 , G = 3 , P = 998244353;
int upd(int x){return x + (x >> 31 & P);}
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int dir[_] , w[_] , need , invnd;
void init(int len){
	need = 1; while(need < len) need <<= 1;
	invnd = poww(need , P - 2);
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for(int i = 1 ; i < need ; i <<= 1){
		w[i] = 1; int wn = poww(G , P / 2 / i);
		for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % P;
	}
}

void DFT(int *arr , int tp){
	for(int i = 1 ; i < need ; ++i) if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % P;
				arr[j + k] = upd(x + y - P); arr[i + j + k] = upd(x - y);
			}
	if(tp == -1){reverse(arr + 1 , arr + need); for(int i = 0 ; i < need ; ++i) arr[i] = 1ll * arr[i] * invnd % P;}
}

int main(){
	static int F[_] , G[_] , dwn[_];
	int N , K; cin >> N >> K; init(2  * K + 1);
	dwn[0] = 1; for(int i = 1 ; i <= K ; ++i) dwn[i] = 1ll * dwn[i - 1] * (N - i + 1) % P;
	for(int i = 0 , ifac = 1 ; i <= K ; ifac = 1ll * ifac * poww(++i , P - 2) % P){
		F[i] = (i & 1 ? P - 1ll : 1ll) * ifac % P * poww(dwn[i] , P - 2) % P;
		G[i] = 1ll * ifac * ifac % P * poww(2 , i) % P;
	}
	DFT(F , 1); DFT(G , 1); for(int i = 0 ; i < need ; ++i) F[i] = 1ll * F[i] * G[i] % P;
	DFT(F , -1); for(int i = 1 , fac = 1 ; i <= K ; fac = 1ll * fac * ++i % P) cout << 1ll * F[i] * dwn[i] % P * fac % P << ' ';
	return 0;
}