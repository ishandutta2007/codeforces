#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

#define int long long
using namespace std;

const int MOD = 1000000007;

int pow(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b % 2 == 0) {
		return pow((a * a) % MOD, b / 2);
	} else {
		return (a * pow(a, b - 1)) % MOD;
	}
}

int fact[1000000];
int obr[1000000];
int pow2[1000000];
int obrpow2[1000000];

void init() {
	fact[0] = 1; 
	pow2[0] = 1;
	for (int i = 1; i < 1000000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
		pow2[i] = pow2[i - 1] * 2;
		pow2[i] %= MOD;
	}
	for (int i = 0; i < 1000000; i++) {
		obr[i] = pow(fact[i], MOD - 2);
		obrpow2[i] = pow(pow2[i], MOD - 2);
	}
}

int c(int n, int k) {
	int ans = fact[n];
	ans *= obr[k];
	ans %= MOD;
	ans *= obr[n - k];
	ans %= MOD;
	return ans;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n == m) {
		cout << (n * k) % MOD << endl;
		return;
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += c(n - i - 1, m - i) * ((((i * k) % MOD) * pow2[i - 1]) % MOD);
		ans %= MOD;
	}
	ans *= obrpow2[n - 1];
	ans %= MOD;
	cout << ans << endl;
}

signed main() {
	init();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}