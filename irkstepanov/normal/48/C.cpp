#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct frac {
    ll num, den;
    frac() : num(0), den(1) {}
    frac(ll a, ll b) {
        ll g = __gcd(a, b);
        num = a / g, den = b / g;
    }
    bool operator<(const frac& other) const {
        return num * other.den < den * other.num;
    }
    bool operator<=(const frac& other) const {
        return num * other.den <= den * other.num;
    }
};

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> vct(n);
    for (int i = 0; i < n; ++i) {
        cin >> vct[i];
    }

    frac lf, rg;
    rg.num = ll(1e9);

    for (int i = 0; i < n; ++i) {
        int k = i + 1;
        int b = vct[i];
        frac t = {10 * b, k};
        if (lf < t) {
            lf = t;
        }
        t = {10 * b + 10, k};
        if (t < rg) {
            rg = t;
        }
        //cout << lf.num << " " << lf.den << "; " << rg.num << " " << rg.den << "\n";
    }

    //cout << rg.num << " " << rg.den << endl;

    int k = n + 1;
    vector<int> ans;
    for (int d = vct.back() + 1; d < 4e6; ++d) {
        frac t1 = {10 * d, k};
        frac t2 = {10 * d + 10, k};
        if (lf <= t1 && t1 < rg) {
            ans.pb(d);
        } else if (t1 <= lf && lf < t2) {
            ans.pb(d);
        }
    }

    if (sz(ans) == 1) {
        cout << "unique\n";
        cout << ans[0] << "\n";
    } else {
        cout << "not unique\n";
    }

}