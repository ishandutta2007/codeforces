#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> l(n);
    for (int& li : l) li = rand() % 2000 + 1;
    auto f = [&](int w) {
        for (int li : l) if (li > w) return 0;
        int res = 1, s = -1;
        for (int li : l) {
            if (s + li + 1 > w) {
                s = -1;
                res += 1;
            }
            s += li + 1;
        }
        return res;
    };
    {
        int count = 0;
        auto query = [&](int w) {
            count += 1;
            cout << "? " << w << endl;
            int res;
            cin >> res; return res;
            return f(w);
        };
        int L = 1, R = (2000 + 1) * n - 1;
        while (L < R) {
            int M = (L + R) >> 1;
            if (query(M) == 1) R = M;
            else L = M + 1;
        }
        int ans = L;
        for (int i = 1; i <= n; i += 1) {
            int w = L / i;
            int h = query(w);
            if (h) ans = min(ans, w * h);
        }
        cout << "! " << ans << endl;
        //cout << count << "\n";
    }
    return 0;
    int mw = (2000 + 1) * n, count = 0;
    vector<int> q(mw);
    auto query = [&](int w) {
        if (q[w]) return;
        count += 1;
        //cout << "? " << w << endl;
        //cin >> q[w];
        q[w] = f(w);
        if (not q[w]) q[w] = INT_MAX;
    };
    function<void(int, int)> DFS = [&](int L, int R) {
        query(L);
        query(R);
        if (q[L] == q[R]) {
            for (int j = L; j <= R; j += 1) q[j] = q[L];
            return;
        }
        if (L + 1 >= R) return;
        int M = (L + R) >> 1;
        DFS(L, M);
        DFS(M, R);
    };
    DFS(1, mw - 1);
    int area = INT_MAX;
    for (int i = 1; i < mw; i += 1)
        if (q[i] != INT_MAX)
            area = min(area, i * q[i]);
    cout << "! " << area << endl;
    cout << count << "\n";
    return 0;
}