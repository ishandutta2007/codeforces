#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6;
bool used[MX];
long long ans = 0;
int cur = 0;
int a, b;

void dfs(int i, int x) {
    used[i] = 1;
    cur++;

    if (i + a <= x && !used[i + a]) {
        dfs(i + a, x);
    }
    if (i - b >= 0 && !used[i - b]) {
        dfs(i - b, x);
    }
}


long long sum(long long n) {
    long long d = __gcd(a, b);
    long long res = n + 1;

    long long prev = n;
    while(prev % d != 0) {
        prev--;
    }
    prev--;
    res += (n - prev) * (n / d);

    prev /= d;
    res += d * (prev * (prev + 1)) / 2;
    return res;

}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int m;
    cin >> m >> a >> b;

    ans = cur = 1;
    used[0] = 1;

    for (int i = 1; i < min(m + 1, MX); i++) {
        if (i >= a && used[i - a]) {
            dfs(i, i);
        }
        ans += cur;
    }

    if (m >= MX) {
        ans += sum(m) - sum(MX - 1);
    }
    cout << ans << '\n';

    return 0;
}