#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 13);

int ans[N], r[N];

vector<int> g[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    ans[0] = 1;
    for (int i = 0; i < N; ++i) g[i].push_back(0);
    for (int i = 0; i < N; ++i) r[i] = N;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (auto key : g[x]) {
            int to = (key ^ x);
            ans[to] = 1;
            while (r[to] > x) {
                --r[to];
                if (r[to] != x) g[r[to]].push_back(to);
            }
        }
        g[x] = {};
    }
    int k = 0;
    for (int i = 0; i < N; ++i) k += ans[i];
    cout << k << '\n';
    for (int i = 0; i < N; ++i) {
        if (ans[i]) cout << i << " ";
    }
    cout << '\n';
    return 0;
}