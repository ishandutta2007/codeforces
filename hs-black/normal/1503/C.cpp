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

const int N = 200050;
int n;
pair<int, int> p[N];
int main() {
    ll ans = 0;
    read(n);
    for (int i = 1;i <= n; ++i) 
        read(p[i].fi), read(p[i].se), ans += p[i].se;
    sort(p + 1, p + n + 1);
    int mx = 0;
    for (int i = 1;i <= n; ++i) {
        mx = max(mx, p[i].fi + p[i].se);
        ans += max(0, p[i + 1].fi - mx);
    }
    write(ans);
    return 0;
}