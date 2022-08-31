#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> f(n);
    vector<bool> in(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
        if (f[i] != -1)
            in[f[i]] = true;
    }
    vector<int> b, e;
    for (int i = 0; i < n; ++i) {
        if (!in[i]) {
            int j = i;
            while (f[j] != -1)
                j = f[j];
            b.push_back(i);
            e.push_back(j);
        }
    }
    for (int i = 0; i < b.size(); ++i)
        f[e[i]] = b[(i + 1) % b.size()];
    for (int i = 0; i < n; ++i)
        cout << f[i] + 1 << " \n"[i == n - 1];
    return 0;
}