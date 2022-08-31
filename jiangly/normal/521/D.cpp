#include <bits/stdc++.h>  
using namespace std;
using LL = long long;
constexpr int N = 1E5;
int k, n, m;
int a[N], t[N], j[N], b[N];
pair<int, int> as[N];
vector<pair<int, int>> add[N];
vector<pair<long double, int>> mul;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n >> m;
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> j[i] >> b[i];
        --j[i];
        switch (t[i]) {
            case 1:
                as[j[i]] = max(as[j[i]], make_pair(b[i], i));
                break;
            case 2:
                add[j[i]].emplace_back(b[i], i);
                break;
            case 3:
                mul.emplace_back(b[i], i);
        }
    }
    for (int i = 0; i < k; ++i)
        if (as[i].first > a[i])
            add[i].emplace_back(as[i].first - a[i], as[i].second);
    for (int i = 0; i < k; ++i) {
        sort(add[i].begin(), add[i].end(), greater<pair<int, int>>());
        LL v = a[i];
        for (const auto &p : add[i]) {
            mul.emplace_back(1.0L * (v + p.first) / v, p.second);
            v += p.first;
        }
    }
    sort(mul.begin(), mul.end(), greater<pair<long double, int>>());
    int x = min(m, (int)mul.size());
    sort(mul.begin(), mul.begin() + x, [&](const auto &lhs, const auto &rhs) {return t[lhs.second] < t[rhs.second];});
    cout << x << "\n";
    for (int i = 0; i < x; ++i)
        cout << mul[i].second + 1 << " \n"[i == x - 1];
    return 0;
}