#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll p = 150;
const ll mod = 2000000009;
const int maxn = 5000000 + 100;

ll convert(char c)
{
    if (c >= 'a' && c <= 'z') return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 27;
    if (c >= '0' && c <= '9') return c - '0' + 53;
    return -1;
}

vector <ll> pref_hash, suff_hash;
int n;
vector <ll> deg_p;

ll left_hash(int l, int r)
{
    if (!l) return pref_hash[r];
    int len = r - l + 1;
    ll ans = pref_hash[r] - pref_hash[l - 1] * deg_p[len];
    if (abs(ans) >= mod) ans %= mod;
    if (ans < 0) ans += mod;
    return ans;
}

ll right_hash(int l, int r)
{
    if (r == n - 1) return suff_hash[l];
    int len = r - l + 1;
    ll ans = suff_hash[l] - suff_hash[r + 1] * deg_p[len];
    if (abs(ans) >= mod) ans %= mod;
    if (ans < 0) ans += mod;
    return ans;
}

bool is_pal(int l, int r)
{
    return left_hash(l, r) == right_hash(l, r);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    char s[maxn];
    gets(s);

    for (; s[n]; n++) ;

    pref_hash.resize(n);
    suff_hash.resize(n);

    pref_hash[0] = convert(s[0]);
    suff_hash[n - 1] = convert(s[n - 1]);

    for (int i = 1; i < n; i++)
    {
        pref_hash[i] = pref_hash[i - 1] * p + convert(s[i]);
        if (pref_hash[i] >= mod) pref_hash[i] %= mod;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suff_hash[i] = suff_hash[i + 1] * p + convert(s[i]);
        if (suff_hash[i] >= mod) suff_hash[i] %= mod;
    }

    deg_p.resize(n + 1);
    deg_p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        deg_p[i] = deg_p[i - 1] * p;
        if (deg_p[i] >= mod) deg_p[i] %= mod;
    }

    vector <ll> k(n);
    ll ans = 1;
    k[0] = 1;

    for (int i = 1; i < n; i++)
        if (is_pal(0, i))
    {
        k[i] = k[(i - 1) / 2] + 1;
        ans += k[i];
    }

    cout << ans << "\n";

}