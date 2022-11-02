#include <bits/stdc++.h>
using int64 = long long;
const int N = 1000005;
const int INF = 1000000000;
char a[N];
int n;
int sumu[N], sumd[N];
int q[N];
int64 ans[N];
int main() {
    std::cin >> n >> (a + 1);
    for (int i = 1; i <= n; i++) {
        sumu[i] = sumu[i - 1];
        if (a[i] == 'U') sumu[i]++;
    }
    for (int i = n; i >= 1; i--) {
        sumd[i] = sumd[i + 1];
        if (a[i] == 'D') sumd[i]++;
    }
    for (int i = 1; i <= n; i++) {
        if (sumd[i + 1] >= sumu[i]) {
            ans[i] = i;
        } else {
            ans[i] = n - i + 1;
        }
    }
    int head = 0, tail = 0;
    int64 tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += head - tail;
        while (head - tail > sumd[i]) tot -= i - q[tail++];
        ans[i] += tot * 2;
        if (a[i] == 'U') q[head++] = i;
    }
    head = 0, tail = 0;
    tot = 0;
    for (int i = n; i >= 1; i--) {
        tot += head - tail;
        while (head - tail > sumu[i]) tot += i - q[tail++];
        ans[i] += tot * 2;
        if (a[i] == 'D') q[head++] = i;
    }
    for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
    std::cout << std::endl;
    return 0;
}