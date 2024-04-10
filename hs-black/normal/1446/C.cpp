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

const int N = 200050;
int ch[N * 31][2], siz[N * 31], dp[N * 31], cnt, n;
void insert(int x) {
    int p = 0;
    for (int i = 30;i >= 0; i--) {
        int c = x >> i & 1;
        if (!ch[p][c]) ch[p][c] = ++cnt;
        p = ch[p][c], siz[p]++;
    }
}

#define ls ch[x][0]
#define rs ch[x][1]
void dfs(int x) {
    if (ls) dfs(ls); if (rs) dfs(rs);
    if (!ls && !rs) return dp[x] = 1, void();
    dp[x] = max(dp[ls] + min(dp[rs], 1), dp[rs] + min(dp[ls], 1));
}

int main() {
    read(n);
    for (int i = 1, x;i <= n; i++) read(x), insert(x);
    dfs(0), write(n - dp[0]);
    return 0;
}