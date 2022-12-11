#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 710;
const int cnt_primes = 127;
const int base = 1e4;

vector<int> primes;
vector<vector<int> > factorization(nmax, vector<int>(cnt_primes));

bool operator<(const vector<int>& a, const vector<int>& b)
{
    //printf("My less\n");
    if (sz(a) != sz(b)) {
        return sz(a) < sz(b);
    }
    for (int i = sz(a) - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

vector<int> operator*(const vector<int>& a, int b)
{
    int n = sz(a);
    if ((n == 1 && a[0] == 0) || b == 0) {
        return {0};
    }
    vector<int> ans;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        c += a[i] * b;
        ans.pb(c % base);
        c /= base;
    }
    if (c) {
        ans.pb(c);
    }
    return ans;
}

struct number
{
    vector<int> v;
    number() {}
    number(const vector<int>& v) : v(v) {}
    number operator*(const number& other) const
    {
        vector<int> ans(cnt_primes);
        for (int i = 0; i < cnt_primes; ++i) {
            ans[i] = v[i] + other.v[i];
        }
        return number(ans);
    }
    number operator/(const number& other) const
    {
        vector<int> ans(cnt_primes);
        for (int i = 0; i < cnt_primes; ++i) {
            ans[i] = v[i] - other.v[i];
        }
        return number(ans);
    }
    number& operator*=(const number& other)
    {
        for (int i = 0; i < cnt_primes; ++i) {
            v[i] += other.v[i];
        }
        return *this;
    }
    number& operator/=(const number& other)
    {
        for (int i = 0; i < cnt_primes; ++i) {
            v[i] -= other.v[i];
        }
        return *this;
    }
};

vector<int> convert(const number& d)
{
    vector<int> ans = {1};
    for (int i = 0; i < cnt_primes; ++i) {
        for (int j = 0; j < d.v[i]; ++j) {
            ans = ans * primes[i];
        }
    }
    return ans;
}

vector<vector<number> > dp;
vector<vector<int> > g;

bool comp(int u, int v)
{
    number x = dp[u][1] * dp[v][0];
    number y = dp[v][1] * dp[u][0];
    vector<int> a = convert(x);
    vector<int> b = convert(y);
    return b < a;
}

void out(const number& d)
{
    vector<int> ans = convert(d);
    for (int i = sz(ans) - 1; i >= 0; --i) {
        if (i != sz(ans) - 1) {
            printf("%04d", ans[i]);
        } else {
            printf("%d", ans[i]);
        }
    }
    printf("\n");
}

void dfs(int v, int p)
{
    if (sz(g[v]) == 1 && g[v][0] == p) {
        dp[v][0].v = factorization[1];
        dp[v][1].v = factorization[1];
        return;
    }
    vector<int> sons;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        sons.pb(to);
    }
    sort(all(sons), comp);
    dp[v][1].v = factorization[1];
    for (int son : sons) {
        dp[v][1] *= dp[son][0];
    }
    dp[v][0].v = dp[v][1].v;
    int s = sz(sons);
    number p_sons = dp[v][1];
    vector<int> curr = convert(dp[v][0]);
    for (int k = 0; k < s; ++k) {
        p_sons *= dp[sons[k]][1];
        p_sons /= dp[sons[k]][0];
        number upd = factorization[k + 2];
        upd *= p_sons;
        vector<int> relax = convert(upd);
        if (curr < relax) {
            dp[v][0] = upd;
            curr = relax;
        }
    }
    for (int son : sons) {
        p_sons = dp[son][1];
        p_sons *= dp[v][1];
        p_sons /= dp[son][0];
        vector<int> grandsons;
        for (int to : g[son]) {
            if (to != v) {
                grandsons.pb(to);
            }
        }
        sort(all(grandsons), comp);
        for (int k = 0; k < sz(grandsons); ++k) {
            p_sons *= dp[grandsons[k]][1];
            p_sons /= dp[grandsons[k]][0];
            number upd = factorization[k + 3];
            upd *= p_sons;
            vector<int> relax = convert(upd);
            if (curr < relax) {
                dp[v][0] = upd;
                curr = relax;
            }
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    vector<char> pp(nmax, true);
    for (int i = 2; i < nmax; ++i) {
        if (pp[i]) {
            primes.pb(i);
            for (int j = 2 * i; j < nmax; j += i) {
                pp[j] = false;
            }
        }
    }

    for (int i = 2; i < nmax; ++i) {
        int x = i;
        for (int j = 0; j < cnt_primes; ++j) {
            while (x % primes[j] == 0) {
                ++factorization[i][j];
                x /= primes[j];
            }
        }
    }

    int n;
    scanf("%d", &n);
    g.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; ++i) {
        dp[i].resize(2);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0);
    /*for (int i = 0; i < n; ++i) {
        printf("%d, 0: ", i + 1);
        out(dp[i][0]);
        printf("%d, 1: ", i + 1);
        out(dp[i][1]);
    }*/
    out(dp[0][0]);

}