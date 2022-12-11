#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const ll mod = 1e6 + 3;
const int nmax = 700500;

vector<ll> fact(nmax);
vector<ll> rfact(nmax);

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

typedef vector<vector<ll> > matrix;

matrix operator*(const matrix& a, const matrix& b)
{
    int n = sz(a);
    matrix c(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ll val = a[i][k];
                mul(val, b[k][j]);
                add(c[i][j], val);
            }
        }
    }
    return c;
}

matrix binpow(matrix a, ll n)
{
    int s = sz(a);
    matrix ans(s, vector<ll>(s));
    for (int i = 0; i < s; ++i) {
        ans[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            ans = ans * a;
        }
        n >>= 1;
        if (n) {
            a = a * a;
        }
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int c, w, h;
    cin >> c >> w >> h;

    matrix base(w + 1, vector<ll>(w + 1));

    for (int j = 0; j <= w; ++j) {
        base[0][j] = 1;
    }
    for (int i = 1; i <= w; ++i) {
        base[i][i - 1] = h;
    }

    matrix a = binpow(base, c);
    ll ans = 0;
    for (int i = 0; i <= w; ++i) {
        add(ans, a[i][0]);
    }

    cout << ans << "\n";

}