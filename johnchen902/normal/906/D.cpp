#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int phi(int x) {
    int ans = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            do
                x /= i;
            while (x % i == 0);
            ans = ans / i * (i - 1);
        }
    if (x > 1)
        ans = ans / x * (x - 1);
    return ans;
}

int mypow(int a, int b, int m) {
    if (b == 0)
        return 1;
    long long x = mypow(a, b / 2, m);
    x *= x;
    if (x > 32)
        x = (x - 32) % m + 32;
    if (b % 2) {
        x *= a;
        if (x > 32)
            x = (x - 32) % m + 32;
    }
    return x;
}

vector<int> mm;
int w[100000];

int solve2(int l, int r, int cnt) {
    if (cnt >= 5)
        return 1;
    if (l == r || w[l] == 1)
        return 1;
    return mypow(w[l], solve2(l + 1, r, cnt + 1), 1);
}

int solve(int l, int r, int cnt) {
    if (mm[cnt] == 1)
        return solve2(l, r, 0);
    if (l == r || w[l] == 1)
        return 1;
    return mypow(w[l], solve(l + 1, r, cnt + 1), mm[cnt]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", w + i);
    mm.push_back(m);
    while (mm.back() > 1)
        mm.push_back(phi(mm.back()));
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        printf("%d\n", solve(l, r, 0) % m);
    }
}