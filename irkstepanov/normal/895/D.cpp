#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

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

const int sigma = 26;
const int nmax = 1e6 + 100; // TODO

int fact[nmax];
int rev[nmax];
int rfact[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	fact[0] = 1;
	rfact[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		fact[i] = fact[i - 1];
		mul(fact[i], i);
		rfact[i] = binpow(fact[i], mod - 2);
	}

	for (int i = 1; i < nmax; ++i) {
		rev[i] = binpow(i, mod - 2);
	}

	string a, b;
	cin >> a >> b;
	int n = sz(a);

	vector<int> c(sigma);
	for (int i = 0; i < n; ++i) {
		++c[a[i] - 'a'];
	}
	int revDen = 1;
	for (int i = 0; i < sigma; ++i) {
		mul(revDen, rfact[c[i]]);
	}

	int y = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = b[i] - 'a' + 1; j < sigma; ++j) {
			int curr = fact[n - i - 1];
			mul(curr, c[j]);
			mul(curr, revDen);
			add(y, curr);
		}
		int j = b[i] - 'a';
		if (c[j] == 0) {
			break;
		}
		mul(revDen, c[j]);
		--c[j];
	}

	c = vector<int>(sigma, 0);
	revDen = 1;

	for (int i = 0; i < n; ++i) {
		++c[a[i] - 'a'];
	}
	for (int i = 0; i < sigma; ++i) {
		mul(revDen, rfact[c[i]]);
	}

	int z = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = a[i] - 'a' + 1; j < sigma; ++j) {
			int curr = fact[n - i - 1];
			mul(curr, c[j]);
			mul(curr, revDen);
			//if (curr) cout << fact[n - i - 1] << " " << c[j] << " " << revDen << "\n";
			add(z, curr);
		}
		int j = a[i] - 'a';
		if (c[j] == 0) {
			break;
		}
		mul(revDen, c[j]);
		--c[j];
	}

	//cout << y << " " << z << "\n";

	sub(z, y);
	sort(all(a));
	sort(all(b));
	if (a == b) {
		sub(z, 1);
	}

	cout << z << "\n";

}