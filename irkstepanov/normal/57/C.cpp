#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int mod = 1e9 + 7;

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

const int nmax = 200500;

int fact[nmax];
int rfact[nmax];

int binpow(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			mul(ans, a);
		}
		n >>= 1;
		mul(a, a);
	}
	return ans;
}

int bin(int n, int k) {
	int ans = fact[n];
	mul(ans, rfact[k]);
	mul(ans, rfact[n - k]);
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		fact[i] = fact[i - 1];
		mul(fact[i], i);
	}
	for (int i = 0; i < nmax; ++i) {
		rfact[i] = binpow(fact[i], mod - 2);
	}

	int n;
	cin >> n;

	int ans = bin(2 * n - 1, n);
	mul(ans, 2);
	sub(ans, n);
	cout << ans << "\n";

}