#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E6;
int vis[N];
void no() {
    cout << -1 << "\n";
    exit(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = 0, t = 0;
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            --a[i];
            if (vis[a[i]] != 0)
                no();
            vis[a[i]] = 1;
            ++cnt;
        } else {
            a[i] = -1 - a[i];
            if (vis[a[i]] != 1)
                no();
            vis[a[i]] = 2;
            --cnt;
        }
        if (cnt == 0) {
            c.push_back(i + 1 - t);
            for (int j = t; j <= i; ++j)
                vis[a[j]] = 0;
            t = i + 1;
        }
    }
    if (t != n)
        no();
    cout << c.size() << "\n";
    for (int i = 0; i < (int)c.size(); ++i)
        cout << c[i] << " \n"[i == (int)c.size() - 1];
    return 0;
}