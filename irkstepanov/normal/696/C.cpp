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

struct matrix
{
    ll m[2][2];
    matrix()
    {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
    }
};

matrix operator*(const matrix& a, const matrix& b)
{
    matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ll val = a.m[i][k];
                mul(val, b.m[k][j]);
                add(c.m[i][j], val);
            }
        }
    }
    return c;
}

matrix binpow(matrix a, ll n)
{
    matrix ans;
    ans.m[0][0] = ans.m[1][1] = 1;
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

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        if (n) {
            mul(a, a);
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<ll> a(n);
    bool even = false;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        if (a[i] % 2 == 0) {
            even = true;
        }
    }

    if (even) {
        matrix b;
        b.m[0][0] = 2;
        b.m[1][1] = 1;
        b.m[0][1] = binpow(3, mod - 2);
        mul(b.m[0][1], mod - 2);
        for (int i = 0; i < n; ++i) {
            b = binpow(b, a[i]);
        }
        ll ans = b.m[0][0];
        add(ans, b.m[0][1]);
        mul(ans, binpow(2, mod - 2));
        cout << ans << '/';
        ll val = 2;
        for (int i = 0; i < n; ++i) {
            val = binpow(val, a[i]);
        }
        mul(val, binpow(2, mod - 2));
        cout << val << "\n";
    } else {
        matrix b;
        b.m[0][0] = 2;
        b.m[1][1] = 1;
        b.m[0][1] = binpow(3, mod - 2);
        mul(b.m[0][1], 2);
        for (int i = 0; i < n; ++i) {
            b = binpow(b, a[i]);
        }
        ll val = binpow(3, mod - 2);
        mul(val, mod - 1);
        ll ans = b.m[0][0];
        mul(ans, val);
        add(ans, b.m[0][1]);
        mul(ans, binpow(2, mod - 2));
        cout << ans << '/';
        val = 2;
        for (int i = 0; i < n; ++i) {
            val = binpow(val, a[i]);
        }
        mul(val, binpow(2, mod - 2));
        cout << val << "\n";
    }

}