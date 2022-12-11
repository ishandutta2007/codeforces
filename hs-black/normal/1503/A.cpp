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

int main() {
    static const int N = 200050;
    static int T, n, A[N], B[N];
    static char s[N];
    for (read(T); T; T--) {
        read(n), scanf ("%s", s + 1);
        int _0 = 0;
        for (int i = 1;i <= n; ++i) 
            _0 += s[i] == '0';
        if (s[1] != '1' || _0 & 1) { puts("NO"); continue; }
        int _1 = (n - _0) >> 1;
        for (int i = 1;i <= n; ++i) {
            if (s[i] == '1') A[i] = B[i] = _1 ? (--_1, 1) : 0;
            else A[i] = !(B[i] = --_0 & 1);
        }
        auto check = [&](int *A) {
            int s = 0;
            for (int i = 1;i <= n && s >= 0; ++i)
                s += A[i] ? 1 : -1;
            return s == 0;
        };
        auto output = [&](int *A) {
            for (int i = 1;i <= n; ++i) putchar(A[i] ? '(' : ')');
            putchar('\n');
        };
        if (!check(A) || !check(B)) { puts("NO"); continue; }
        puts("YES"), output(A), output(B);
    }
    return 0;
}