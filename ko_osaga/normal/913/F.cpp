#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
//typedef pair<int, int> pi;
const int MAXN = 2005;
const int mod = 998244353;

// return a % b (positive value)
lint mo(lint a, lint b) {
	return ((a%b) + b) % b;
}

// computes gcd(a,b)
lint gcd(lint a, lint b) {
	while (b) { lint t = a%b; a = b; b = t; }
	return a;
}

// computes lcm(a,b)
lint lcm(lint a, lint b) {
	return a / gcd(a, b)*b;
}

// (a^b) mod m via successive squaring
lint ipow(lint a, lint b){
	lint ret = 1;
	while (b)
	{
		if (b & 1) ret = mo(ret*a, mod);
		a = mo(a*a, mod);
		b >>= 1;
	}
	return ret;
}

lint dp[MAXN], game[MAXN];
lint pwr[1000005];
lint prob[MAXN][MAXN], p;
lint flux[MAXN][MAXN];
lint bino[MAXN][MAXN];

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	for(int i=0; i<=n; i++){
		bino[i][0] = 1;
		for(int j=1; j<=i; j++){
			bino[i][j] = (bino[i-1][j] + bino[i-1][j-1]) % mod;
		}
	}
	flux[0][0] = 1;
	p = 1ll * x * ipow(y, mod - 2) % mod;
	for(int i=1; i<=n; i++){
		flux[i][0] = 1;
		for(int j=1; j<=i; j++){
			flux[i][j] = flux[i-1][j-1] * ipow(p, i-j) + 
				flux[i-1][j] * ipow(1 - p, j);
			flux[i][j] %= mod;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			prob[i][j] = prob[j][j] * flux[i][j] % mod;
		}
		prob[i][i] = 1;
		for(int j=1; j<i; j++){
			prob[i][i] += mod - prob[i][j];
		}
		prob[i][i] %= mod;
	}
	game[1] = 0;
	dp[1] = 0;
	for(int i=2; i<=n; i++){
		for(int j=1; j<i; j++){
			dp[i] += prob[i][j] * (game[j] + dp[i-j]) % mod;
		}
		dp[i] += prob[i][i] * (i * (i - 1) / 2) % mod;
		dp[i] %= mod;
		dp[i] *= ipow(mod + 1 - prob[i][i], mod - 2);
		dp[i] %= mod;
		game[i] = (i * (i - 1) / 2 + dp[i]) % mod;
	}
	cout << game[n] << endl;
}