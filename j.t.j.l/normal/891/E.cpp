#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MM = 1e9 + 7;
const int MAXN = 5e3 + 10;

ll a[MAXN];
ll C[MAXN][MAXN];
ll fac[MAXN << 1], inv[MAXN << 1];

ll pw(ll p, int q){
	if (q == 0) return 1;
	ll ret = 1;
	for (; q; q >>= 1){
		if (q & 1) ret = ret * p % MM;
		p = p * p % MM;
	}
	return ret;
}

ll c[MAXN], d[MAXN];
int n, K;

ll calc(ll cof){
	if (cof < 0) return 0;
	/*
	ll ret = fac[2 * n - 1];
	for (int i = 1; i <= 2 * n - 1; i++){
		ret = ret * (cof + i) % MM;
	}*/
	ll ret = pw(n, cof);
	for (int i = cof + 1; i <= K; i++){
		ret = (ret * i) % MM;
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &K);
	/*C[1][1] = C[1][0] = 1;
	for (int i = 2; i <= n; i++){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if (C[i][j] >= MM) C[i][j] -= MM;
		}
	}*/
	ll sum = 1;
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		sum = (sum * a[i]) % MM;
	}
	c[0] = 1;
	/*
	fac[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= 2 * n; i++){
		inv[i] = pw(i, MM - 2);
		fac[i] = (fac[i - 1] * inv[i]) % MM;
	}*/
	ll nico = 1;
	for (int i = 2 * n - 1; i >= 1; i--)
		nico = (nico * i) % MM;
	fac[2 * n - 1] = pw(nico, MM - 2);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++)
			d[j] = 0;
		for (int j = 0; j < i; j++){
			//d[j] += c[j] * a[i];
			//d[j + 1] -= c[j] * (1 + a[i]);
			d[j] -= c[j] * a[i];
			d[j + 1] += c[j];
		}
		for (int j = 0; j <= i; j++)
			c[j] = (d[j]) % MM;
	}
	//for (int i = 0; i <= n; i++)
	//	cerr << c[i] << ' '; cout << endl;
	ll ans = 0;
	for (int i = 0; i <= n && i <= K; i++){
		ans = (ans + c[i] * calc(K - i)) % MM;
	}
	ans %= MM;
	ans = (ans * pw(pw(n, K), MM - 2)) % MM;
	if (n & 1)
		ans = -ans;
	ans = sum - ans;
	printf("%lld\n", (ans % MM + MM) % MM);
	return 0;
}