#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }

string solve() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    int y = max(0, K - (floor_lg(N) + 1)), e = K - y;
    vector<string> cands;
    for (int i = 0, suc1 = 0; i < N; suc1 = (S[i] == '0' ? 0 : suc1 + 1), i++) {
        if (suc1 >= y and i + e <= N) cands.emplace_back(S.substr(i, e));
    }
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());

    vector<int> v(2 << e);
    for (int i = 1 << e; i < 2 << e; i++) v[i] = 1;
    for (auto s : cands) v[accumulate(s.begin(), s.end(), 1, [&](int now, char c) { return now * 2 + '1' - c; })] = 0;
    for (int i = (1 << e) - 1; i; i--) v[i] = v[i * 2] | v[i * 2 + 1];

    if (!v[1]) return "";
    string ret;
    for (int t = 0, now = 1; t < e; t++) ret += '1' - v[now * 2], now = now * 2 + 1 - v[now * 2];

    return string(y, '0') + ret;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        auto s = solve();
        cout << (s.length() ? "YES\n" + s + "\n" : "NO\n");
    }
}