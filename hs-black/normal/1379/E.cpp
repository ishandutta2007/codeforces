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

int n, k;
bool check(int n) {
    int mi = 1, t = n + 1;
    for (;mi <= t; mi <<= 1) if (mi == t) return 1;
    return 0;
}

void output(int n, int x, int f) {
    write(f, ' ');
    for (int i = 2;i <= n; i++)
        write(i / 2 + x, ' ');
}

namespace subtask1 {
    int main() { return puts("YES"), output(n, 0, 0), 0; }
}

int main() {
    read(n), read(k);
    if ((~n & 1) || max(n - 3, 0) < k * 2) return puts("NO"), 0;
    if (n == 9 && k == 2) return puts("NO"), 0;
    if (k == 0) return check(n) ? subtask1::main() : (puts("NO"), 0);
    if (k == 1) return check(n) ? (puts("NO"), 0) : subtask1::main(); 
    puts("YES");
    write(0, ' '), write(1, ' ');
    k--;
    for (int i = 3;i <= 2 * k; i += 2)
        write(i - 2, ' '), write(i, ' ');
    int pre = 2 * k - 1;
    if (check(n - 2 * k)) k++, write(2, ' '), write(2, ' ');
    output(n - 2 * k, 2 * k, pre);
    return 0;
}