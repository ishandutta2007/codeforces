#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 500050;

int bl;
struct node {
    int l, r, num;
    bool operator < (const node &i) const {
        int lb = (l - 1) / bl, rb = (i.l - 1) / bl;
        if (lb != rb) return lb < rb;
        return (r - 1) / bl < (i.r - 1) / bl;
    }
}q[N];

template <typename T>
void read(T &x) {
    x = 0; char c = getchar();
    while (!isdigit(c)) c=getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
}

int n, m, k;
int a[N], tong[N<<3];
long long ans, Ans[N];

inline void del(int x) {
    tong[x]--;
    ans -= tong[x ^ k];
}

inline void add(int x) {
    ans += tong[x ^ k];
    tong[x]++;
}

int main() {
    read(n), read(m), read(k); bl = sqrt(n) + 1;
    for (int i = 1;i <= n; i++) read(a[i]), a[i] ^= a[i-1];
    for (int i = 1;i <= m; i++) 
        read(q[i].l), read(q[i].r), q[i].num = i, q[i].l--;
    int l = 1, r = 1; tong[a[1]] = 1;
    sort(q + 1, q + m + 1);
    for (int i = 1;i <= m; i++) {
        while (l > q[i].l) l--, add(a[l]);
        while (r < q[i].r) r++, add(a[r]);
        while (l < q[i].l) del(a[l]), l++;
        while (r > q[i].r) del(a[r]), r--;
        Ans[q[i].num] = ans;
    }
    for (int i = 1;i <= m; i++) printf ("%lld\n", Ans[i]);
    return 0;
}
/*
6 3 0
0 0 0 0 0 0
1 4
2 6
4 5

*/