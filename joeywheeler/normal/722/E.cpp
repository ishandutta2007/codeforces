#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

#define y first
#define x second

typedef long long ll;

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b&1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }
    return r;
}

ll mdinv(ll x) {
    return pw(x, MOD-2);
}

ll f[200005], vf[200005];

ll chs(int a, int b) {
    if (b < 0 || b > a) return 0;
    return f[a] * vf[b] % MOD * vf[a-b] % MOD;
}

ll np(int y, int x) {
    return chs(x+y,x);
}

pair<int,int> an[2005];
int k, s;
int h, w;

ll ch[2005][25];

ll dp(int i, int d) {
    // from i to end hitting d things
    if (ch[i][d] != -1) return ch[i][d];
    ll rs = np(h-1-an[i].y, w-1-an[i].x);
    FO(j,0,d) rs += MOD-dp(i, j);
    rs %= MOD;
    FO(j,i+1,k) {
        rs += MOD - dp(j,d) * np(an[j].y-an[i].y, an[j].x-an[i].x) % MOD;
    }
    rs %= MOD;
    //printf("ch[%d][%d]=%d\n", i, d, rs);
    return ch[i][d] = rs;
}

int main() {
    f[0] = 1;
    FO(i,1,200005) f[i] = i * f[i-1] % MOD;
    vf[200004] = mdinv(f[200004]);
    for (int i = 200003; i >= 0; i--) vf[i] = vf[i+1]*(i+1) % MOD;
    
    scanf("%d %d %d %d", &h, &w, &k, &s);
    FO(i,0,k) {
        scanf("%d %d", &an[i].y, &an[i].x);
        an[i].y--; an[i].x--;
    }
    sort(an,an+k);
    if (k && an[k-1] == make_pair(h-1,w-1)) {
        s -= s/2;
        k--;
    }
    if (k && an[0] == make_pair(0,0)) {
        s -= s/2;
    } else {
        an[k++] = make_pair(0,0);
    }
    sort(an, an+k);

    memset(ch,-1,sizeof ch);
    ll ans = np(h-1,w-1);
    FO(i,0,25) if (s > 1) {
        ans += (s-1) * dp(0,i) % MOD;
        s -= s/2;
    }
    ans %= MOD;
    ans = ans * mdinv(np(h-1,w-1)) % MOD;
    printf("%lld\n", ans);
}