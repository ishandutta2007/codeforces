/*
   
  | _ _|
   ` _x 
    /  |
   /   ?
  | |||
  | (__)_)
  
 
     AzusaCat yyds!
 
 */

#define Fin freopen ("hs.in","r",stdin)
#define Fout freopen ("hs.out","w",stdout)
#define OK puts("OK")
#define Iloveccf false
#define AzusaAkIOI true
#define jzpyyds true
#define lhmrsyj true
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

#include <set>
set<pair<int, int> > s;
int n, q;
int main() {
    for (read(n), read(q), s.insert(MP(1, n)); q; --q) {
        int l, r, k;
        read(l), read(r), read(k);
        auto st = s.upper_bound(MP(l, r));
        if (st != s.begin()) -- st;
        if (st != s.end()) {
            auto t = *st;
            if (t.se >= l) { 
                if (t.fi < l) {
                    if (t.se <= r) n -= t.se - l + 1, s.erase(st++), s.insert(MP(t.fi, l - 1));
                    else {
                        s.erase(st), n -= r - l + 1, s.insert(MP(t.fi, l - 1)), s.insert(MP(r + 1, t.se)).fi;
                        st = s.end();
                    }
                }
            }
            else ++st;
        }
        while (st != s.end() && st -> se <= r) 
            n -= st->se - st->fi + 1, s.erase(st++); 
        if (st != s.end() && st -> fi <= r) {
            auto t = *st;
            n -= r - st -> fi + 1, s.erase(st), s.insert(MP(r + 1, t.se));
        }
        if (k == 2) n += r - l + 1, s.insert(MP(l, r));
        write(n);
    }
    return 0;
}