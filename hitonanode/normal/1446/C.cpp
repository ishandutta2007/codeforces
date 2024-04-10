#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }
    auto dfs = [&](auto&& dfs, const vector<int> &v, int d) -> int {
        if (v.size() <= 1) return 0;
        vector<int> a, b;
        for (auto x : v) {
            if (x & (1 << d)) {
                a.emplace_back(x - (1 << d));
            } else {
                b.emplace_back(x);
            }
        }
        return min(dfs(dfs, a, d - 1) + (b.size() ? b.size() - 1 : 0), dfs(dfs, b, d - 1) + (a.size() ? a.size() - 1 : 0));
    };

    cout << dfs(dfs, A, 30) << '\n';
}