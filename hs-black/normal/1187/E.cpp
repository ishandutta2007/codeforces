#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 200500;
int read(void) {
    int x = 0, f = 0;
    char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c=='-')f=1;
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return f ? -x : x;
}
int h[N], ne[N<<1], to[N<<1];
int tot;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[tot] = y;
    h[x] = tot;
}

int n, siz[N];
ll dp[N], ans[N];

void dfs(int x,int f) {
    siz[x] = 1;
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; if (y == f) continue;
        dfs(y, x); siz[x] += siz[y], ans[x] += ans[y];
    }
    ans[x] += siz[x];
}

ll kick;
void work(int x,int f) {
    kick = max(kick, dp[x]);
    for (int i = h[x]; i ; i = ne[i]) {
        int y = to[i]; if (y == f) continue;
        dp[y] = dp[x] + n - 2 * siz[y]; 
        work(y, x);
    }
}

int main() {
    n = read();
    for (int i = 1;i < n; i++) {
        int x = read(), y = read();
        add(x, y); add(y, x);
    }
    dfs(1, 0); dp[1] = ans[1], work(1, 0);
    cout << kick << endl;
    return 0;
}