#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

struct frac {
    ll num, den;
    frac() : num(0), den(1) {}
    frac(ll x) : num(x), den(1) {}
    frac(ll a, ll b) {
        ll g = __gcd(a, b);
        num = a / g;
        den = b / g;
    }
    bool operator<(const frac& other) const {
        return num * other.den < den * other.num;
    }
};

int rev(int x) {
    vector<int> d;
    while (x) {
        d.pb(x % 10);
        x /= 10;
    }
    for (int p : d) {
        x *= 10;
        x += p;
    }
    return x;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int A, B, w;
    cin >> A >> B >> w;

    vector<frac> p(A + 1);
    for (int a = 1; a <= A; ++a) {
        p[a] = {a, rev(a)};
    }
    vector<frac> q(B + 1);
    for (int b = 1; b <= B; ++b) {
        q[b] = {rev(b), b};
    }

    map<frac, int> lf, rg;
    for (int a = 1; a <= A; ++a) {
        ++lf[p[a]];
    }
    for (int b = 1; b <= B; ++b) {
        ++rg[q[b]];
    }

    ll curr = 0;
    for (auto it : lf) {
        curr += ll(it.second) * rg[it.first];
    }

    if (curr < w) {
        cout << "-1\n";
        return 0;
    }
    int b = B;
    while (true) {
        if (curr - lf[q[b]] >= w) {
            curr -= lf[q[b]];
            --rg[q[b]];
            --b;
        } else {
            break;
        }
    }

    int opta = A, optb = b;
    ll best = ll(opta) * optb;

    for (int a = A; a >= 2; --a) {
        /// delete p[a]
        --lf[p[a]];
        curr -= rg[p[a]];
        while (curr < w && b + 1 <= B) {
            curr += lf[q[b + 1]];
            ++rg[q[b + 1]];
            ++b;
        }
        if (curr < w) {
            break;
        }
        ll val = ll(a - 1) * b;
        if (val < best) {
            opta = a - 1, optb = b;
            best = val;
        }
    }

    cout << opta << " " << optb << "\n";

}