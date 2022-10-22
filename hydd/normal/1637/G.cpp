//
// Created by hydd on 2022/10/9.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 0;
    cin >> T;
    while (T--) {
        int n = 0;
        cin >> n;
        if (n == 2) {
            cout << "-1\n";
            continue;
        }
        vector<int> vec, val(n + 1), low(n + 1);
        low[1] = 1;
        for (int i = 1; i <= n; i++) {
            vec.push_back(i);
            val[i] = i;
            if (i > 1) low[i] = (low[i >> 1] << 1);
        }
        vector<pair<int, int>> Ans;
        auto work = [&val, &Ans](int x, int y) {
            int a = val[x], b = val[y];
            Ans.emplace_back(a, b);
            val[x] = b + a;
            val[y] = abs(b - a);
        };
        auto calc = [](int x, int y) {
            return x + x - y;
        };
        function<void(vector<int> &)> solve = [&solve, &low, &work, &calc](vector<int> &pos) {
            int n = (int) pos.size();
            if (n <= 1) return;
            int p = low[n];
            vector<int> nxt;
            for (int y = p; y < n; y++) {
                int x = calc(p - 1, y);
                work(pos[x], pos[y]);
                nxt.push_back(pos[y]);
            }
            solve(nxt);

            pos.resize(calc(p - 1, n - 1));
            solve(pos);
        };
        solve(vec);

        vector<int> pos(n + 1);
        int f = 1;
        while (f < n) f <<= 1;
        int p = -1;
        for (int i = 1; i <= n; i++) {
            if (val[i] == f) continue;
            if (pos[val[i]]) {
                work(pos[val[i]], i);
                p = i;
                break;
            }
            pos[val[i]] = i;
        }
        assert(p != -1);

        for (int i = 1; i <= n; i++) {
            if (i == p) continue;
            while (val[i] != f) {
                work(i, p);
                work(i, p);
            }
        }
        work(p % n + 1, p);
        for (int i = 1; i <= n; i++)
            assert(val[i] == f);

        cout << Ans.size() << '\n';
        for (auto v: Ans) cout << v.first << ' ' << v.second << '\n';
    }
    return 0;
}