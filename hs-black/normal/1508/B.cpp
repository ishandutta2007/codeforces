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

const int N = 200500;
ll k;
int vis[N], T, n;
int main() {
    for (read(T); T; T--) {
        read(n), read(k); --k;
        int fl = 1;
        for (int i = 1;i <= n; ++i) vis[i] = 1;
        for (int i = 60;i >= 0; --i) if (k >> i & 1) {
            if (n <= i + 1) { fl = 0; break; }
            vis[n - i - 1] = 0;
        }
        if (!fl) { write(-1); continue; }
        vis[0] = 1;
        for (int i = 1;i <= n; ++i) {
            if (!vis[i]) continue;
            write(i, ' ');
            int t = i - 1;
            while (!vis[t]) write(t, ' '), --t;
        }
        puts("");
    }
    return 0;
}