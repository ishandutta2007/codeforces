#include<bits/stdc++.h>
using namespace std;

const int _ = 1 << 18 , P = 998244353 , G = 3; int upd(int x){return x + (x >> 31 & P);}
int add(int x , int y){return upd(x + y - P);} int sub(int x , int y){return upd(x - y);}
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

int dir[_] , need , invnd , w[_];
void init(int len){
	static int L = 1; need = 1; while(need < len) need <<= 1;
	invnd = poww(need , P - 2); for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for(int &i = L ; i < need ; i <<= 1){w[i] = 1; int wn = poww(G , P / i / 2); for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % P;}
}

void dft(vector < int > &arr , int tp){
	arr.resize(need); for(int i = 1 ; i < need ; ++i) if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % P;
				arr[j + k] = add(x , y); arr[i + j + k] = sub(x , y);
			}
	if(tp == -1){reverse(arr.begin() + 1 , arr.end()); for(auto &t : arr) t = 1ll * t * invnd % P;}
}

int N , fac[_] , ifac[_];
int binom(int a , int b){return b >= 0 && a >= b ? 1ll * fac[a] * ifac[b] % P * ifac[a - b] % P : 0;}

int main(){
	cin >> N; fac[0] = 1; for(int i = 1 ; i <= 2e5 ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[200000] = poww(fac[200000] , P - 2); for(int i = 2e5 - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	vector < int > ans(1 , 1); int L = 1;
	while(N--){
		int A , B; cin >> A >> B; vector < int > coef; int nL = L + A - B;
		for(int i = -L + 1 ; i <= nL - 1 ; ++i) coef.push_back(binom(A + B , B + i));
		init(L + nL); dft(ans , 1); dft(coef , 1);
		for(int i = 0 ; i < need ; ++i) coef[i] = 1ll * ans[i] * coef[i] % P;
		dft(coef , -1); ans.clear(); for(int i = 0 ; i < nL ; ++i) ans.push_back(coef[i + L - 1]);
		L = nL;
	}
	int sum = 0; for(auto t : ans) sum = add(sum , t);
	cout << sum; return 0;
}