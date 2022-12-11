#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const int mod = 998244353;

void add(int& a, int b) {
	a += b;
	if (a > mod) {
		a -= mod;
	}
}

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

vector<int> conv(ll x, vector<ll>& p) {
	vector<int> ans;
	for (int i = 0; i < sz(p); ++i) {
		ans.pb(0);
		while (x % p[i] == 0) {
			++ans.back();
			x /= p[i];
		}
	}
	return ans;
}

const int nmax = 100500;

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

int fact[nmax];
int rfact[nmax];

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	
    ll n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
    	fact[i] = fact[i - 1];
    	mul(fact[i], i);
    }

    for (int i = 0; i < nmax; ++i) {
    	rfact[i] = binpow(fact[i], mod - 2);
    }

    vector<ll> primes;
    vector<int> degs;
    for (ll d = 2; d * d <= n; ++d) {
    	if (n % d == 0) {
    		primes.pb(d);
    		degs.pb(0);
    		while (n % d == 0) {
    			++degs.back();
    			n /= d;
    		}
    	}
    }
    if (n != 1) {
    	primes.pb(n);
    	degs.pb(1);
    }

    int q;
    cin >> q;
    while (q--) {
    	ll x, y;
    	cin >> x >> y;
    	vector<int> a = conv(x, primes), b = conv(y, primes);
    	int ans = 1;
    	int sum = 0;
    	for (int i = 0; i < sz(a); ++i) {
    		int d = a[i] - min(a[i], b[i]);
    		sum += d;
    		mul(ans, rfact[d]);
    	}
    	mul(ans, fact[sum]);
    	sum = 0;
    	for (int i = 0; i < sz(a); ++i) {
    		int d = max(a[i], b[i]) - a[i];
    		sum += d;
    		mul(ans, rfact[d]);
    	}
    	mul(ans, fact[sum]);
    	cout << ans << "\n";
    }

}