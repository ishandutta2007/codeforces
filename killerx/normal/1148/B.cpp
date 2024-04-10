#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f = 0;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
    return f ? x : -x;
}
const int N = 2e5 + 5;
int n, m, k;
ll ta, tb;
ll a[N], b[N];
int main() {
    n = read(), m = read();
    ta = read(), tb = read(), k = read();
    for (int i = 0; i < n; ++ i) {
        a[i] = read();
    }
    for (int i = 0; i < m; ++ i) {
        b[i] = read();
    }
    ll mx = 0;
    if (n <= k) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n && i <= k; ++ i) {
        int low = lower_bound(b, b + m, a[i] + ta) - b;
        if (low + k - i >= m) {
            puts("-1");
            return 0;
        }
        mx = max(mx, b[low + k - i] + tb);
    }
    printf("%lld\n", mx);
    return 0;
}