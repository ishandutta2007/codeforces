 #include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define MAXN 1001
using namespace std;

ll dp[MAXN][MAXN];
int K , pa , pb;

inline ll ksm(ll a , ll b){
	ll times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

inline ll calc(ll a , ll b){
	if(a + b < K)
		return dp[a][b];
	else
		return (a + b + pa * ksm(pb , MOD - 2)) % MOD;
}

int main(){
	cin >> K >> pa >> pb;
	for(ll i = K - 2 ; i >= 0 ; i--)
		for(ll j = K - i - 1 ; j ; j--)
			dp[i][j] = (calc(i + j , j) * pb + pa * calc(i , j + 1)) % MOD * ksm(pa + pb , MOD - 2) % MOD;
	cout << calc(0 , 1);
	return 0;
}