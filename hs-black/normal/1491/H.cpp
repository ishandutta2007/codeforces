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
int a[N], tag[N], bl[N], f[N], L[N], R[N], cnt, S, n, q;
inline int A(int x) { return max(1, a[x] - tag[bl[x]]); }
#include <cassert>
int main() {
    read(n), read(q), S = 350;
    for (int i = 2;i <= n; ++i) read(a[i]);
    for (int l = 2, r;l <= n; l = r + 1) {
        r = min(l + S - 1, n), L[++cnt] = l, R[cnt] = r;
        for (int i = l;i <= r; ++i) 
            bl[i] = cnt, f[i] = a[i] < l ? i : f[a[i]];
    }
    //for (int i = 1;i <= n; ++i) write(f[i], " \n"[i == n]);
    for (int i = 1, op, l, r, x;i <= q; ++i) {
        read(op), read(l), read(r);
        if (op == 1) { 
            read(x);
            if (bl[l] == bl[r]) {
                for (int j = l;j <= r; ++j) {
                    a[j] -= x, a[j] = max(a[j], 1);
                    f[j] = bl[A(j)] != bl[j] ? j : f[A(j)];
                }
                for (int j = r + 1;bl[j] == bl[r]; ++j)
                    f[j] = bl[A(j)] != bl[j] ? j : f[A(j)];
                continue;
            }
            for (int j = l;bl[j] == bl[l]; ++j) {
                a[j] -= x, a[j] = max(a[j], 1);
                f[j] = bl[A(j)] != bl[j] ? j : f[A(j)];
            }
            for (int j = bl[l] + 1;j < bl[r]; ++j) {
                tag[j] += x;
                if (tag[j] - x < S) {
                    for (int k = L[j];k <= R[j]; ++k) 
                        f[k] = bl[A(k)] != bl[k] ? k : f[A(k)];
                }
                tag[j] = min(tag[j], n);
            }
            for (int j = L[bl[r]];j <= r; ++j) {
                a[j] -= x, a[j] = max(a[j], 1);
                f[j] = bl[A(j)] != bl[j] ? j : f[A(j)];
            }
            for (int j = r + 1;bl[j] == bl[r]; ++j)
                f[j] = bl[A(j)] != bl[j] ? j : f[A(j)];
        } else {
            //for (int j = 1;j <= n; ++j) write(f[j], " \n"[j == n]);
            //for (int j = 1;j <= n; ++j) write(a[j], " \n"[j == n]);
            //write(l, ' '), write(r);
            //write(f[l], ' '), write(f[r]);
            /* OK; */
            while (f[l] != f[r]) {
                if (f[l] < f[r]) swap(l, r);
                //OK, write(l, ' '), write(r);
                l = A(f[l]);
            }
            //write(l, ' '), write(r);
            /* OK; */
            while (l != r) {
                if (l < r) swap(l, r);
                /* write(l, ' '), write(r), write(a[l]); */
                //if (l == a[l]) return 0;
                l = A(l);
            }
            write(l);
        }
    }
    return 0;
}