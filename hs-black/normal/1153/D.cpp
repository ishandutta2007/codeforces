#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000500;
int opt[N], f[N];
int read(void) {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c=getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}
int n, m;
int h[N], ne[N], to[N];
int tot;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[tot] = y, h[x] = tot;
}


void dfs(int x) {
    if (!h[x]) {f[x]=1, m++; return;}
    if (opt[x]) f[x] = n;
    for (int i = h[x]; i; i = ne[i]) {
        int y = to[i]; dfs(y);
        if (opt[x]) f[x] = min(f[x], f[y]);
        else f[x] += f[y];
    }
}

int main() {
    n = read();
    for (int i = 1;i <= n; i++) opt[i] = read();
    for (int i = 2;i <= n; i++) add(read(), i);
    dfs(1); cout << m - f[1] + 1 << endl;
    return 0;
}