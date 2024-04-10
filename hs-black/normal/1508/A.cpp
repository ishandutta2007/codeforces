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
char s[4][N], st[N];
int v[4], n, T, tp;
inline int ct(char *s) {
    int c = 0;
    for (int i = 1;i <= 2 * n; ++i)
        c += s[i] == '1';
    return c;
}
#include <cassert>
int Test;
void solve(char *s, char *t) {
    /* puts(s + 1), puts(t + 1); */
    /* OK; */
    tp = 0;
    /* OK; */
    if (ct(s) >= n && ct(t) >= n) {
        int j = 1;
        for (int i = 1;i <= 2 * n; ++i)
            if (s[i] == '1') {
                while (j <= 2 * n && t[j] != '1') 
                    st[++tp] = t[j++];
                if (j <= 2 * n && t[j] == '1') st[++tp] = t[j++];
                else st[++tp] = '1';
            } else st[++tp] = s[i];
        while (j <= 2 * n) st[++tp] = t[j++];
    } else {
        int j = 1;
        for (int i = 1;i <= 2 * n; ++i)
            if (s[i] == '0') {
                while (j <= 2 * n && t[j] != '0') 
                    st[++tp] = t[j++];
                if (j <= 2 * n && t[j] == '0') st[++tp] = t[j++];
                else st[++tp] = '0';
            } else st[++tp] = s[i];
        while (j <= 2 * n) st[++tp] = t[j++];
    }
    auto check = [&](char *s) {
        int t = 1;
        for (int i = 1;i <= 2 * n; ++i) {
            while (t <= tp && st[t] != s[i]) ++t;
            if (t > tp) return 0;
            ++t;
        }
        return 1;
    };
    /* gcwrite(n); */
    /* ++Test; write(Test); */

    for (int i = 1;i <= tp; ++i) putchar(st[i]);
    putchar('\n');
}

int main() {
    for (read(T); T; T--) {
        /* OK; */
        read(n);
        for (int i = 1;i <= 3; ++i) 
            scanf ("%s", s[i] + 1), v[i] = ct(s[i]);
        int fl = 0;
        for (int i = 1;i <= 3; ++i) {
            for (int j = i + 1;j <= 3; ++j) {
                if (!fl && v[i] >= n && v[j] >= n) { fl = 1; solve(s[i], s[j]); }
                if (!fl && v[i] <= n && v[j] <= n)  { fl = 1; solve(s[i], s[j]); }
            }
        }
    }
    return 0;
}