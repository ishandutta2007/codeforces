#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 5010
ll mod = 998244353;

ll memo[MAXN][MAXN];
ll a[MAXN];
int runsize[MAXN];
int n;
ll fac[MAXN];
ll facinv[MAXN];
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll dp(int index, int numbig) {
    if (index == -1) {
        if (numbig == 0) return 1;
        else return 0;
    }
    if (memo[index][numbig] != -1) return memo[index][numbig];

    ll out = 0;
    if (index == n-1 || a[index] > a[index+1]) {
        out += facinv[runsize[index]-1]*dp(index-1, numbig-1); // make big
        out %- mod;
    }

    ll coeff = max(numbig-1, 0) - (index-numbig);
    if (numbig == n/2) coeff++;
    if (index == n-1 || a[index] > a[index+1]) coeff *= facinv[runsize[index]];
    coeff %= mod;
    out += coeff*dp(index-1, numbig);
    out %= mod;
    //cout << index << ' ' << numbig << ' ' << out << endl;
    return memo[index][numbig] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, MAXN) {
        fac[i] = (fac[i-1]*i)%mod;
    }

    rep(i, 0, MAXN) {
        facinv[i] = modpow(fac[i], mod-2);
    }

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        sort(a, a+n);
        reverse(a, a+n);

        rep(i, 0, n+1) rep(j, 0, n+1) memo[i][j] = -1;

        int curr = -1;
        int run = 0;
        rep(i, 0, n) {
            if (a[i] == curr) {
                run++;
            } else {
                run = 1;
                curr = a[i];
            }
            runsize[i] = run;
        }

        ll out = dp(n-1, n/2);
        cout << out << endl;

        
        
    }
}