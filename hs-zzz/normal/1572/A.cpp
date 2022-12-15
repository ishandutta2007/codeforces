/*

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

#pragma GCC optimize(2)
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T& x) {
    x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = 1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    if (f)
        x = -x;
}

template <typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];
    short tp = 0;
    if (x < 0)
        putchar('-'), x = -x;
    do
        st[++tp] = x % 10, x /= 10;
    while (x);
    while (tp)
        putchar('0' | st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T& x, T y) {
    x < y && (x = y);
}

template <typename T>
inline void Mn(T& x, T y) {
    x > y && (x = y);
}

#include <queue>
#include <vector>
const int N = 200500;
int T, n;
int f[N], in[N];
vector<int> vec[N];
void work(void) {
    queue<int> q;
    read(n), memset(f, 0, (n + 1) << 2);
    for (int i = 1; i <= n; ++i)
        vec[i].clear();
    for (int i = 1, x; i <= n; ++i) {
        read(in[i]);
        for (int j = 1; j <= in[i]; ++j)
            read(x), vec[x].emplace_back(i);
        if (!in[i])
            q.push(i);
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto t : vec[x]) {
            Mx(f[t], f[x] + (x > t));
            if (!--in[t])
                q.push(t);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (in[i])
            return write(-1);
        Mx(ans, f[i]);
    }
    write(ans + 1);
}

int main() {
    read(T);
    for (int i = 1; i <= T; ++i)
        work();
    return 0;
}