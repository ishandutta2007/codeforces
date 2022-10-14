#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = __int128;
using namespace std;
const int maxn = 1e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<array<ll, 3>> ops;
void mul(ll x, ll p) {
	if(p < 2) return;
	ll r = x;p--;
	while(p) {
		if(p&1) ops.push_back({r, x, 0}), r += x;
		ops.push_back({x, x, 0}), x += x;
		p>>=1;
	}
}

ll find_good(ll i) {
	for(ll x = -1; x < 17; x++) {
		if(((i*(i+x)) ^ i) < 3) continue;
		if(__gcd((i*(i+x)) ^ i, i) == 1) return i+x;
	}
	assert(0);
}
namespace nvm {
	ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
	}
	ll bp(ll a, ll p, ll M) {
		ll r = 1;
		while(p) {
			if(p&1) r = r*a%M;
			a = a*a%M, p>>=1;
		}
		return r;
	}
};
ll inverse(ll n, ll m) {
	ll P = nvm::phi(m);
	return nvm::bp(n, P-1, m);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    long long tmp;
    cin >> tmp; n = tmp;
    ll m = find_good(n);
    mul(n, m);
    ops.push_back({n*m, n, 1});
    m = (n*m) ^ n;
    ops.push_back({m, m, 0});
    m += m;
    ll inv = inverse(n, m);
    mul(n, inv);
    ll X = n*inv;
    ll D = X/m;
    mul(m, D);
    ops.push_back({m*D, X, 1});
    cout << ops.size() << '\n';
    set<int> have;
    have.insert(n);
    for(auto [x, y, z] : ops) {
		char op = z ? '^' : '+';
		if(!have.count(x)) cout << "No "<< endl;
		if(!have.count(y)) cout << "No "<< endl;
		cout << (int64_t)x << " " << op << " " << (int64_t)y << '\n';
		if(z) have.insert(x^y);
		else have.insert(x+y);
	}
}