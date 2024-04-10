#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

#define MOD 1000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct rt {
    ll sm[2];
    ll nm[2];
};

vector<int> u[200005];
ll v[200005];
int n;
ll ans;

rt go(int i, int p) {
    rt res = {};
    res.sm[0] = v[i];
    res.nm[0] = 1;
    for (int j : u[i]) if (j != p) {
        rt a = go(j, i);

        fo(i,0,2) {
            ans = (ans + res.sm[i] * a.nm[i]) % MOD;
            ans = (ans + res.nm[i] * a.sm[i]) % MOD;
        }

        a.sm[0] = a.sm[0] + v[i] * a.nm[0];
        a.sm[1] = a.sm[1] + (MOD-1) * v[i] % MOD * a.nm[1];

        fo(i,0,2) {
            res.sm[i] = (res.sm[i] + a.sm[i]) % MOD;
            res.nm[i] = (res.nm[i] + a.nm[i]) % MOD;
        }
    }

    swap(res.sm[0], res.sm[1]);
    swap(res.nm[0], res.nm[1]);
    return res;
}

int main() {
    scanf("%d", &n);
    fo(i,1,n+1) {
        scanf("%lld", v+i);
        if (v[i] < 0) v[i] += MOD;
    }
    fo(i,0,n-1) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].eb(y);
        u[y].eb(x);
    }
    go(1,0);
    ans = (2 * ans) % MOD;
    fo(i,1,n+1) ans = (ans + v[i]) % MOD;
    printf("%lld\n", ans);
}