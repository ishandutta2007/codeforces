#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

typedef vector<vector<ll> > matrix;

void mult(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

matrix operator*(const matrix& a, const matrix& b)
{
    int n = sz(a);
    matrix c;
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        c[i].resize(n);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ll d = a[i][k];
                mult(d, b[k][j]);
                add(c[i][j], d);
            }
        }
    }
    return c;
}

matrix binPow(matrix a, int n)
{
    matrix ans(sz(a));
    for (int i = 0; i < sz(ans); ++i) {
        ans[i].resize(sz(ans));
        ans[i][i] = 1;
    }
    if (!n) {
        return ans;
    }
    while (n) {
        if (n & 1) {
            ans = ans * a;
        }
        a = a * a;
        n >>= 1;
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, b, k, x;
    cin >> n >> b >> k >> x;
    //cout << n << " " << b << " " << k << " " << x << "\n";
    vector<int> init(x);
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        //cout << d % x << "\n";
        ++init[d % x];
    }

    matrix base(x);
    for (int i = 0; i < x; ++i) {
        base[i].resize(x);
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            int t = x - (10 * j) % x;
            t = (i + t) % x;
            base[i][j] += init[t];
        }
    }

    matrix res = binPow(base, b - 1);
    ll ans = 0;
    for (int j = 0; j < x; ++j) {
        ll t = res[k][j];
        mult(t, init[j]);
        add(ans, t);
    }

    cout << ans << "\n";

}