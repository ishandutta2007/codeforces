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
int A[N], B[N], n, l, tp;
int main() {
    read(n);
    ll ans = 0;
    for (int i = 1;i <= n; ++i) {
        read(l); int mx = 0, mn = 1e9, fl = 0;
        for (int j = 1, x;j <= l; ++j) {
            read(x);
            if (x > mn) fl = 1;
            mx = max(mx, x), mn = min(mn, x);
        }
        if (fl) continue;
        A[++tp] = mx, B[tp] = mn;
    }
    ans += 1ll * n * n - 1ll * tp * tp;
    n = tp;
    sort(A + 1, A + n + 1), sort(B + 1, B + n + 1);
    for (int i = 1;i <= n; ++i)
        ans += lower_bound(B + 1, B + n + 1, A[i]) - B - 1;
    write(ans);
    return 0;
}