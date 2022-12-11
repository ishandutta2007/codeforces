#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const ll mod = 1e9 + 7;

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

int pop_count(ll val)
{
    int ans = 0;
    while (val) {
        if (val & 1) {
            ++ans;
        }
        val >>= 1;
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    matrix base(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll val = (a[i] ^ a[j]);
            int pc = pop_count(val);
            if (pc % 3 == 0) {
                base[i][j] = 1;
                //cout << i << " " << j << a[i] << " " << a[j] << " " << val << " " << pc << "\n";
            }
        }
    }

    matrix b = binpow(base, k - 1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            add(ans, b[i][j]);
        }
    }

    cout << ans << "\n";

}