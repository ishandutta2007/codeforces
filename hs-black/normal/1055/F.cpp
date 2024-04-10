#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1000050;
template <typename T>
void read(T &x) {
    x = 0; char c = getchar();
    while (!isdigit(c)) c=getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
}

ll dis[N], n, K;
int ch[2][N<<2][2];
int cnt[2], p[N], p2[N];

int h[N], to[N], ne[N];
ll siz[2][N], w[N], tot;
inline void add(int x, int y, ll z) {
    ne[++tot] = h[x], to[tot] = y;
    h[x] = tot, w[tot] = z;
}

void dfs(int x) {
    for (int i = h[x]; i; i = ne[i]) 
        dis[to[i]] = dis[x] ^ w[i], dfs(to[i]);
}

int main() {
    read(n), read(K);
    for (int i = 2;i <= n; i++) {
        ll a, b; read(a), read(b);
        add(a, i, b);
    } dfs(1);
    ll ans = 0;
    for (int i = 1;i <= n; i++) p[i] = p2[i] = 1;
    for (ll b = 62;b >= 0; b--) {
        int k = b & 1, pk = !k; cnt[k] = 0;
        for (int i = 1;i <= n; i++) {
            ll di = (dis[i] >> b) & 1; siz[pk][p[i]] = 0;
            if (!ch[pk][p[i]][di]) ch[pk][p[i]][di] = ++cnt[k];
            p[i] = ch[pk][p[i]][di]; siz[k][p[i]]++;
            ch[k][p[i]][0] = ch[k][p[i]][1] = 0;
        }
        ll sum = 0;
        for (int i = 1;i <= n; i++) {
            ll di = (dis[i] >> b) & 1;
            sum += siz[k][ch[pk][p2[i]][di]];
        }
        for (int i = 1;i <= n; i++) {
        	ll di = (dis[i] >> b) & 1;
        	if (K > sum) p2[i] = ch[pk][p2[i]][!di];
        	else p2[i] = ch[pk][p2[i]][di];
        }
        if (K > sum) K -= sum, ans |= (1ll << b);
    }
    cout << ans << endl;
}