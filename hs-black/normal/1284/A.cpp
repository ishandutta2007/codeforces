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

int m, n, q;
string s[3333], t[3333];
int main() {
    read(n), read(m);
    for (int i = 1;i <= n; ++i) cin >> s[i];
    for (int i = 1;i <= m; ++i) cin >> t[i];
    read(q);
    for (int i = 1;i <= q; ++i) {
        int x, y; read(x), y = x;
        x = (x - 1) % n + 1, y = (y - 1) % m + 1;
        cout << s[x] + t[y] << endl;
    }
    return 0;
}