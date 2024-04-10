#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 505;

int n, MOD;
int dp[MAXN][MAXN], dva[MAXN], fact[MAXN], inv[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int pot (int x, int e) {
	if (e == 0) return 1;
	int t = pot(x, e / 2);
	t = mul(t, t);
	if (e & 1) t = mul(t, x);
	return t;
}

void precompute () {
    dva[0] = fact[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        dva[i] = mul(dva[i - 1], 2);
        fact[i] = mul(fact[i - 1], i);
        inv[i] = pot(fact[i], MOD - 2);
    }
}

int calc (int pos, int br) {
    if (pos > n) return fact[br];
    if (dp[pos][br] != -1) return dp[pos][br];
    int res = 0;
    for (int i = pos + 1; i <= n + 1; i++) {
        if (i == n) continue;
        res = add(res, mul(calc(i + 1, br + (i - pos)), mul(dva[i - pos - 1], inv[i - pos])));
    }
    return dp[pos][br] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> MOD;
    precompute();
    cout << calc(1, 0);
    return 0;
}