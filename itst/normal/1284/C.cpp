#include<bits/stdc++.h>
using namespace std;

int N , MOD , jc[250003];

int main(){
	cin >> N >> MOD; jc[0] = 1;
	for(int i = 1 ; i <= N ; ++i) jc[i] = 1ll * jc[i - 1] * i % MOD;
	int sum = 0;
	for(int i = 1 ; i <= N ; ++i)
		sum = (sum + 1ll * (N - i + 1) * (N - i + 1) % MOD * jc[N - i] % MOD * jc[i]) % MOD;
	cout << sum; return 0;
}