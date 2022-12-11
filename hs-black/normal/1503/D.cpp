/*
   
  | _ _|
   ` _x 
    /  |
   /   ?
  | |||
  | (__)_)
  
 
 */

#define OK printf ("Pass on Line #%d\n", __LINE__)
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
inline void write(T *st, int n, string s = "") {
    if (s.size()) cout << s << ": ";
    while (n--) write(*st++, ' ');
    puts("");
}

#include <cstdlib>
const int N = 400050;
const int inf = 1e9;
int vis[N], mat[N], ord[N], n;
void out(void) { write(-1); exit(0); }
int solve(int l, int r) {
    if (l >= r) return 0;
    int prer = mat[r];
    int prel = inf;
    int nowr = r, nowl = l - 1, res = 0;
    res += ord[r], vis[r] = vis[mat[r]] = 1;
    while (nowl < prer - 1 || nowr > prel + 1) {
        while (nowl < prer - 1) {
            ++nowl;
            if (vis[nowl]) continue;
            res += ord[nowl], vis[nowl] = vis[mat[nowl]] = 1;
            if (prel < mat[nowl] || mat[nowl] < prer) out();
            prel = mat[nowl];
        }
        while (nowr > prel + 1) {
            --nowr;
            if (vis[nowr]) continue;
            res += ord[nowr], vis[nowr] = vis[mat[nowr]] = 1; 
            if (prer > mat[nowr] || mat[nowr] > prel) out();
            prer = mat[nowr];
        }
    }
    int L = max(nowl, prer), R = min(nowr, prel);
    return solve(L + 1, R - 1) + min((r - l + 1 - (R - L - 1)) / 2 - res, res);
}

int main() {
//	freopen ("hs.in","r",stdin);
    read(n);
    for (int i = 1, a, b;i <= n; ++i)
        read(a), read(b), mat[a] = b, mat[b] = a, ord[b] = 1;
    write(solve(1, 2 * n));
    return 0;
}