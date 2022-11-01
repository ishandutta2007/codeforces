#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a);i<(b);i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll r[5005];
ll st[5005][6000];
int n, k;

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = r * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return r;
}

int main() {
    scanf("%d %d", &n, &k);

    ll ml = 1;
    fo(i,0,5005) {
        if (i > n) r[i] = 0;
        else {
            r[i] = ml * pw(2, n - i) % MOD;
            ml = ml * (n - i) % MOD;
        }
    }

    st[0][0] = 1;
    fo(i,1,5005) fo(j,1,5005) {
        st[i][j] = (j * st[i-1][j] + st[i-1][j-1]) % MOD;
    }

    ll rs = 0;
    fo(i,0,k+1) rs = (rs + st[k][i] * r[i]) % MOD;
    printf("%lld\n", rs);
}