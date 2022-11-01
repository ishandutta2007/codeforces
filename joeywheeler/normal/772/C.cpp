#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
 
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0) x1 += m0;
    return x1;
}
int n, m;
bool no[200005];
vector<int> vl[200005];
int cnt[200005];
int dp[200005];
int nk[200005];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        if (x == 0) x = m;
        no[x] = true;
    }
    vector<int> v;
    FO(i,1,m+1) if (!no[i]) {
        vl[__gcd(i,m)].push_back(i);
        cnt[__gcd(i,m)]++;
        v.push_back(__gcd(i,m));
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for (int i = sz(v)-1; i >= 0; i--) {
        int res = cnt[v[i]];
        int nj = -1;
        FO(j,i+1,sz(v)) if (v[j] % v[i] == 0) {
            if (res < cnt[v[i]]+dp[j]) {
                res = cnt[v[i]]+dp[j];
                nj = j;
            }
        }
        nk[i] = nj;
        dp[i] = res;
    }
    int bi = -1;
    FO(i,0,sz(v)) if (bi == -1 || dp[bi] < dp[i]) bi = i;
    vector<int> u;
    while (bi != -1) {
        for (int x : vl[v[bi]]) u.push_back(x);
        bi = nk[bi];
    }
    int crpr = 1;
    printf("%d\n", sz(u));
    for (int x : u) {
        ll fct = __gcd(x, m) / __gcd(crpr, m);
        ll a0 = crpr / __gcd(crpr,m);
        ll x0 = x / __gcd(x,m);
        ll ofct = x0 * modInverse(a0,m/__gcd(crpr,m)) % m;

        ll tfct = fct * 1ll * ofct % m;

        printf("%lld ", tfct);
        crpr = crpr * tfct % m;
    }
    printf("\n");
}