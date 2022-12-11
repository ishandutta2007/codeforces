#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const ll mod = 1e9 + 7;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;

	++k;
	k >>= 1;

	while (k) {
		if (n == 1) {
			break;
		}
		ll res = n;
		for (ll p = 2; p * p <= n; ++p) {
			if (n % p == 0) {
				res /= p;
				res *= (p - 1);
				while (n % p == 0) {
					n /= p;
				}
			}
		}
		if (n != 1) {
			res /= n;
			res *= (n - 1);
		}
		n = res;
		--k;
	}

	cout << n % mod << "\n";

}