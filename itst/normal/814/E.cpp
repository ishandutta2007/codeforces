#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

inline ll poww(ll a , ll b){
	ll k = 1;
	while(b){
		if(b & 1)
			k = k * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return k;
}

ll num[51] , num2[51] , num3[51] , g[51][51][51] , f[51][51] , yh[51][51] = {1} , jc[51] = {1} , ni2 = poww(2 , MOD - 2);

void init(){
	for(ll i = 1 ; i <= 50 ; i++)
		jc[i] = jc[i - 1] * i % MOD;
	for(ll i = 1 ; i <= 50 ; i++){
		yh[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++)
			yh[i][j] = (yh[i - 1][j] + yh[i - 1][j - 1]) % MOD;
	}
	g[0][0][0] = 1;
	for(ll i = 3 ; i <= 50 ; i++)
		for(ll j = 2 ; j < i ; j++)
			g[0][0][i] = (g[0][0][i] + g[0][0][i - j - 1] * yh[i - 1][j] % MOD * jc[j] % MOD * ni2) % MOD;
	for(ll j = 2 ; j <= 50 ; j++)
		for(ll k = 0 ; k + j <= 50 ; k++){
			if(k)
				g[0][j][k] = g[0][j][k - 1] * k;
			g[0][j][k] = (g[0][j][k] + g[0][j - 2][k] * (j - 1)) % MOD;
		}
	for(ll i = 1 ; i <= 50 ; i++)
		for(ll k = 0 ; k + i <= 50 ; k++)
			for(ll j = 0 ; j + k + i <= 50 ; j++){
				if(k)
					g[i][j][k] = g[i - 1][j + 1][k - 1] * k % MOD;
				if(j)
					g[i][j][k] = (g[i][j][k] + g[i - 1][j - 1][k] * j) % MOD;
			}
}

int main(){
	init();
	ll N;
	cin >> N;
	for(ll i = 1 ; i <= N ; i++){
		cin >> num[i];
		num2[i] = num2[i - 1] + (num[i] == 2);
		num3[i] = num3[i - 1] + (num[i] == 3);
	}
	f[num[1] + 1][num[1]] = 1;
	for(ll i = num[1] + 2 ; i <= N ; i++)
		for(ll j = 1 ; j < i ; j++)
			for(ll k = 1 ; k <= i - j ; k++)
				f[i][j] = (f[i][j] + f[i - j][k] * g[j][num2[i - j] - num2[i - j - k]][num3[i - j] - num3[i - j - k]]) % MOD;
	ll ans = 0;
	for(ll i = 1 ; i <= N ; i++)
		ans = (ans + f[N][i] * g[0][num2[N] - num2[N - i]][num3[N] - num3[N - i]]) % MOD;
	cout << ans;
	return 0;
}