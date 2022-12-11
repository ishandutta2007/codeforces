#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int M = 105000;
int h[M], to[M<<1], ne[M<<1], tot;
ll vis[M], dis[M], w[M<<1];
inline void add(int x, int y, ll z) {
    ne[++tot] = h[x], to[tot] = y;
    w[tot] = z, h[x] = tot;
}

ll read(void) {
    ll x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}

int n, m;

ll num[80];
void ins(ll x) {
    for (ll i = 62;i >= 0; i--) {
        ll t = (x >> i) & 1;
        if (!t) continue;
        if (!num[i]) 
            return num[i] = x, void();
        else x ^= num[i];
    }
}

ll query(ll x) {
    ll res = x;
    for (ll i = 62;i >= 0; i--) 
        if ((res ^ num[i]) < res) res ^= num[i];
    return res;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; 
        if (!vis[y]) dis[y] = dis[x] ^ w[i], dfs(y);   
        else ins(dis[y] ^ dis[x] ^ w[i]);
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1;i <= m; i++) {
        int x = read(),  y = read();
        ll z = read();
        add(x, y, z); add(y, x, z);
    }
    dfs(1);
    printf ("%lld", query(dis[n]));
    return 0;
}