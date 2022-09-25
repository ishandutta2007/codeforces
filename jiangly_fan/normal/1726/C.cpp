#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> f(2 * n), stack;
        for (int i = 0; i < 2 * n; i += 1) {
            if (s[i] == '(') stack.push_back(i);
            else {
                f[stack.back()] = i;
                f[i] = stack.back();
                stack.pop_back();
            }
        }
        int ans = 0;
        function<void(int, int)> DFS = [&](int L, int R) {
            if (L > R) return;
            ans += 1;
            for (int p = L; p <= R; p = f[p] + 1)
                DFS(p + 1, f[p] - 1);
        };
        DFS(0, 2 * n - 1);
        cout << ans << "\n";
    }
}