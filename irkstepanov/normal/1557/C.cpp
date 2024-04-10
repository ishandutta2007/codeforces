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

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

const int nmax = 200500;

int fact[nmax];
int rfact[nmax];
int rev[nmax];

int bin(int n, int k) {
	int ans = fact[n];
	mul(ans, rfact[k]);
	mul(ans, rfact[n - k]);
	return ans;
}

int binpow(int a, ll n) {
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

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    rev[1] = 1;
    for (int i = 2; i < nmax; ++i) {
    	int val = mod / i;
    	mul(val, rev[mod % i]);
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

    int tt;
    cin >> tt;

    while (tt--) {
    	int n, k;
    	cin >> n >> k;
    	if (n & 1) {
    		int val = 1;
    		for (int i = 0; i < n; i += 2) {
    			add(val, bin(n, i));
    		}
    		int ans = 1;
    		for (int i = 0; i < k; ++i) {
    			mul(ans, val);
    		}
    		cout << ans << "\n";
    	} else {
    		int sum = 0;
    		for (int i = 0; i < n; i += 2) {
    			add(sum, bin(n, i));
    		}
    		int pw = 1;
    		int ans = 0;
    		for (int i = 0; i <= k; ++i) {
    			if (i == k) {
    				add(ans, pw);
    			} else {
    				int x = pw;
    				mul(x, binpow(2, ll(n) * (k - i - 1)));
    				add(ans, x);
    			}
    			mul(pw, sum);
    		}
    		cout << ans << "\n";
    	}
    }

}