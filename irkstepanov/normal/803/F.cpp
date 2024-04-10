#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int nmax = 100500;
int cnt[nmax];

int mod = 1e9 + 7;

void add(int& a, int b)
{
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int& a, int b)
{
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

void mul(int& a, int b)
{
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

int binpow(int a, int n)
{
	int ans = 1;
	while (n) {
		if (n & 1) {
			mul(ans, a);
		}
		mul(a, a);
		n >>= 1;
	}
	return ans;
}

int del[nmax];
int f[nmax];

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int d = 1; d * d <= a; ++d) {
			if (a % d == 0) {
				++cnt[d];
				if (d * d != a) {
					++cnt[a / d];
				}
			}
		}
	}

	int degs[nmax];
	degs[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		degs[i] = degs[i - 1];
		mul(degs[i], 2);
	}

	for (int d = 2; d < nmax; ++d) {
		int val = degs[cnt[d]];
		sub(val, 1);
		del[d] = val;
	}

	f[nmax - 1] = del[nmax - 1];
	for (int d = nmax - 2; d >= 1; --d) {
		f[d] = del[d];
		for (int i = 2 * d; i < nmax; i += d) {
			sub(f[d], f[i]);
		}
	}

	int ans = degs[n];
	sub(ans, 1);
	for (int d = 2; d < nmax; ++d) {
		sub(ans, f[d]);
	}

	cout << ans << "\n";

}