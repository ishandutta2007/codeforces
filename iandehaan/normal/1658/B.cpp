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

ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll fac[2000];
    fac[0] = 1;
    for (int i = 1; i < 2000; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            ll out = fac[n/2]*fac[n/2];
            out %= mod;
            cout << out << endl;
        } else {
            cout << 0 << endl;
        }
    }
}