#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int rmax = 60;

bool bit(ll mask, int pos)
{
    return (mask >> pos) & 1;
}

void mul(ll& a, ll b)
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

void sub(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

struct data
{
    ll a, b;
    data() : a(0), b(0) {}
    data(ll a, ll b) : a(a), b(b) {}
    data operator+(const data& other) const
    {
        ll new_a = a;
        add(new_a, other.a);
        ll new_b = b;
        add(new_b, other.b);
        return {new_a, new_b};
    }
    data operator*(const data& other) const
    {
        ll val1 = a;
        mul(val1, other.b);
        ll val2 = b;
        mul(val2, other.a);
        add(val1, val2);
        ll new_b = val1;
        val1 = a;
        mul(val1, other.a);
        val2 = b;
        mul(val2, other.b);
        mul(val2, 5);
        add(val1, val2);
        return {val1, new_b};
    }
    data operator-(const data& other) const
    {
        ll new_a = a;
        sub(new_a, other.a);
        ll new_b = b;
        sub(new_b, other.b);
        return {new_a, new_b};
    }
};

vector<vector<data> > dp;
vector<vector<ll> > bin;
ll r5 = binpow(5, mod - 2);

data count_magic(ll n, int k) // sum F(i)^k over i in [0, n]
{
    if (n == 0) {
        return {0, 0};
    }
    data res;
    for (int j = 0; j <= k; ++j) {
        data val = dp[k][j];
        vector<data> sum(rmax);
        vector<data> degs(rmax);
        degs[0] = val;
        sum[0] = {1, 0}; // till here
        for (int i = 1; i < rmax; ++i) {
            sum[i] = sum[i - 1] + degs[i - 1] * sum[i - 1];
            degs[i] = degs[i - 1] * degs[i - 1];
        }
        data ans;
        data curr = {1, 0};
        for (int r = rmax - 1; r >= 0; --r) {
            if (bit(n + 1, r)) {
                ans = ans + sum[r] * curr;
                curr = curr * degs[r];
            }
        }
        //ans = ans + curr;
        mul(ans.a, bin[k][j]);
        mul(ans.b, bin[k][j]);
        if ((k - j) & 1) {
            ans.a = mod - ans.a;
            ans.b = mod - ans.b;
        }
        ll r = binpow(r5, k / 2);
        mul(ans.a, r);
        mul(ans.b, r);
        if (k & 1) {
            ll new_a = ans.b;
            ll new_b = ans.a;
            mul(new_b, r5);
            ans = {new_a, new_b};
        }
        res = res + ans;
    }
    return res;
}

vector<ll> mul(const vector<ll>& a, const vector<ll>& b)
{
    int n = sz(a) - 1, m = sz(b) - 1;
    vector<ll> c(n + m + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            ll val = a[i];
            mul(val, b[j]);
            add(c[i + j], val);
        }
    }
    return c;
}

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    ll l, r;
    cin >> k >> l >> r;
    l += 2, r += 2;

    dp = vector<vector<data> >(k + 1, vector<data>(k + 1));
    vector<data> degs_plus(k + 1), degs_minus(k + 1);
    degs_plus[0] = degs_minus[0] = {1, 0};
    ll r2 = binpow(2, mod - 2);
    for (int i = 1; i <= k; ++i) {
        data tmp = {r2, r2};
        degs_plus[i] = degs_plus[i - 1] * tmp;
        tmp = {r2, mod - r2};
        degs_minus[i] = degs_minus[i - 1] * tmp;
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = degs_plus[j] * degs_minus[i - j];
        }
    }

    bin = vector<vector<ll> >(k + 1, vector<ll>(k + 1));
    bin[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j <= k; ++j) {
            bin[i][j] = bin[i - 1][j];
            add(bin[i][j], bin[i - 1][j - 1]);
        }
    }

    /*if (l < k) {
        l = k;
    }*/
    if (l > r) {
        cout << "0\n";
        return 0;
    }

    vector<ll> p = {0, 1}; // C(n, 1) = 0 + 1 * n
    for (int i = 2; i <= k; ++i) {
        // (n - i + 1) / i
        ll t = binpow(i, mod - 2);
        vector<ll> q(2);
        q[1] = t;
        q[0] = mod - t;
        mul(q[0], i - 1);
        vector<ll> r = mul(p, q);
        p = r;
    }

    data ans;
    for (int i = 0; i <= k; ++i) {
        data val = count_magic(r, i);
        mul(val.a, p[i]);
        mul(val.b, p[i]);
        ans = ans + val;
        val = count_magic(l - 1, i);
        mul(val.a, p[i]);
        mul(val.b, p[i]);
        ans = ans - val;
    }
    cout << ans.a << "\n";

}