#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

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

const int nmax = 3e6 + 100;

int fact[nmax];
int rfact[nmax];
int f0[nmax], f1[nmax], f2[nmax];
int rev[nmax];

int bin(int n, int k) {
	if (n < k) {
		return 0;
	}
	int ans = fact[n];
	mul(ans, rfact[k]);
	mul(ans, rfact[n - k]);
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    rev[1] = 1;
    for (int i = 2; i < nmax; ++i) {
    	int val = rev[mod % i];
    	mul(val, mod / i);
    	mul(val, mod - 1);
    	rev[i] = val;
    }

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
    	fact[i] = fact[i - 1];
    	mul(fact[i], i);
    	rfact[i] = rfact[i - 1];
    	mul(rfact[i], rev[i]);
    }

    f0[0] = f1[0] = f2[0] = n + 1;
    int r3 = binpow(3, mod - 2);

    for (int x = 1; x < nmax - 5; ++x) {
    	int y = bin(3 * n + 3, x + 1);
    	sub(y, f1[x - 1]);
    	sub(y, f0[x - 1]);
    	sub(y, f0[x - 1]);
    	mul(y, r3);
    	f0[x] = y;
    	f1[x] = f0[x];
    	add(f1[x], f0[x - 1]);
    	f2[x] = f1[x];
    	add(f2[x], f1[x - 1]);
    }

    int q;
    cin >> q;
    while (q--) {
    	int x;
    	cin >> x;
    	cout << f0[x] << "\n";
    }

}