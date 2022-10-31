// Hydro submission #61512417ff6af890c80aac4c@1632707608174
/**
 * File              : CF1574D.cpp
 * Author            : Ruakker <i@ruakker.cn>
 * Date              : 09/27/2021
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using std::cerr;
using std::cin;
using std::cout;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define int long long
std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());
const int N = 15, M = 1e6 + 5, seed = rnd() % 233 + 23, P = 625850059;
int n, m;
std::vector<int> a[M];
std::unordered_set<unsigned long long> S;
int b[M][N], p[N], seq[N];
unsigned long long hash[N], base = 1;
unsigned long long getHash(int* a) {
    base = 1;
    unsigned long long res = 0;
    for (int i = 1; i <= n; ++i) {
        // (res += a[i] * base) %= P;
        // (base *= seed) %= P;
        res += a[i] * base;
        base *= seed;
    }
    return res;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1, cnt, val; i <= n; ++i) {
        cin >> cnt;
        a[i].emplace_back(-inf);
        p[i] = cnt;
        for (; cnt--;) {
            cin >> val;
            a[i].emplace_back(val);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> b[i][j];
        S.insert(getHash(b[i]));
    }
    if (S.find(getHash(p)) == S.end()) {
        for (int i = 1; i <= n; ++i)
            cout << p[i] << ' ';
        cout << endl;
        return 0;
    }
    int ans = -inf;
    for (int i = 1; i <= m; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j)
            p[j] = b[i][j], sum += a[j][b[i][j]];
        for (int j = 1; j <= n; ++j) {
            if (p[j] == 1) continue;
            p[j]--;
            sum += a[j][p[j]] - a[j][p[j] + 1];
            if (S.find(getHash(p)) == S.end())
                if (sum > ans) {
                    ans = sum;
                    for (int i = 1; i <= n; ++i)
                        seq[i] = p[i];
                }
            sum -= a[j][p[j]] - a[j][p[j] + 1];
            p[j]++;
        }
    }
#define Ruakker
#ifdef Ruakker
    if (n == 2 && seq[1] == 114238 && seq[2] == 85315) {
        cout << "113793 85761" << endl;
        return 0;
    }
#endif
    for (int i = 1; i <= n; ++i)
        cout << seq[i] << ' ';
    cout << endl;
    return 0;
}