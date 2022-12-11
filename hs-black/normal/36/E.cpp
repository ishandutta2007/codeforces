/*
  
 | _ _|
  ` _x 
   /  |
  /   ?
 | |||
 | (__)_)
 
  */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#define Fuck write(-1)
const int N = 30050;
int h[N], to[N<<1], ne[N<<1], tot = 1;
inline void add(int x, int y) {
    ne[++tot] = h[x], to[h[x] = tot] = y;
}

int siz, vis[N], odd, deg[N], st[7], poi[4][6], cnt;
void dfs(int x) {
    vis[x] = 1, siz++;
    if (deg[x] & 1) odd++, poi[cnt][odd] = x;
    if (odd > 4) { Fuck; exit(0); }
    for (int i = h[x]; i; i = ne[i]) 
        if (!vis[to[i]]) dfs(to[i]);
}

vector<int> ans[5];
void Dfs(int x, vector<int> &ans) {
    for (int &i = h[x]; i; i = ne[i]) {
        int y = to[i], t = i; if (vis[t]) continue;
        vis[t] = vis[t ^ 1] = 1;
        Dfs(y, ans), ans.push_back(t / 2);
    }
}

int pp[43], m, n;
void work(int p) {
    if (st[p]) Dfs(poi[p][1], ans[p]);
    else Dfs(pp[p], ans[p]);
}

int main() {
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    read(m); n = 10000;
    for (int i = 1, x, y;i <= m; i++) 
        read(x), read(y), add(x, y), add(y, x), deg[x]++, deg[y]++;
    for (int i = 1;i <= n; i++) {
        if (vis[i]) continue;
        pp[++cnt] = i, dfs(i), st[cnt] = odd, odd = 0;
        if (siz == 1) { siz = 0, cnt--; continue; }
        siz = 0;
        if (cnt > 2) return Fuck, 0;
    }
    if (m == 1) return Fuck, 0;
    if (cnt == 2 && max(st[1], st[2]) >= 4) return Fuck, 0;
    memset(vis, 0, sizeof(vis));
    if (cnt == 2) work(1), work(2);
    else {
        if (st[1] == 4) 
            st[1] = 2, add(poi[1][3], poi[1][4]), add(poi[1][4], poi[1][3]);
        work(1);
        for (int i = 0;i < (int)ans[1].size(); i++) {
            if (ans[1][i] > m) {
                for (int j = i + 1;j < (int)ans[1].size(); j++)
                    ans[2].push_back(ans[1][j]);
                ans[1].resize(i);
                break;
            }
        }
        if (!ans[2].size()) ans[2].push_back(ans[1].back()), ans[1].pop_back();
    }
    write(ans[1].size());
    for (auto t: ans[1]) write(t, ' ');
    puts("");
    write(ans[2].size());
    for (auto t: ans[2]) write(t, ' ');
    return 0;
}