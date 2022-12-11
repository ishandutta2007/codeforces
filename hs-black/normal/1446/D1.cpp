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

const int N = 200500;
int a[N], c[N], las[N<<1], n;
int main() {
    read(n);
    for (int i = 1;i <= n; i++)
        read(a[i]), c[a[i]]++;
    int t = 0, ans = 0;
    for (int i = 1;i <= 100; i++) if (c[i] > c[t]) t = i;
    for (int i = 1;i <= 100; i++) {
        if (i == t) continue;
        memset(las, -1, sizeof(las));
        int nw = n; las[n] = 0;
        for (int j = 1;j <= n; j++) {
            if (a[j] == i) nw++;
            if (a[j] == t) nw--;
            if (~las[nw]) Mx(ans, j - las[nw]);
            else las[nw] = j;
        }
    }
    write(ans);
    return 0;
}