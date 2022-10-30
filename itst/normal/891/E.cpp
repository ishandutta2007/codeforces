#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 5003 , MOD = 1e9 + 7;
int arr[_] , N , K;

int poww(int a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = tms * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return tms;
}

signed main(){
	cin >> N >> K; int tms = 1 , sum = 0; arr[0] = 1;
	for(int i = 1 ; i <= N ; ++i){
		int p; cin >> p; tms = tms * p % MOD;
		for(int j = i ; j >= 0 ; --j)
			arr[j] = (arr[j] * p - (j ? arr[j - 1] : 0) + MOD) % MOD;
	}
	for(int i = 0 , jc = 1 ; i <= N && i <= K ; jc = jc * (K - (i++)) % MOD)
		sum = (sum + jc * arr[i] % MOD * poww(N , K - i)) % MOD;
	cout << (tms - sum * poww(poww(N , K) , MOD - 2) % MOD + MOD) % MOD;
	return 0;
}