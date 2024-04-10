#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;

int a[105][105];

int main() {
    int m, n;
    cin >> m >> n;
    --m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j)
            cin >> a[i][j];
        for (int j = 0; j < m; ++j)
            a[i][j] -= a[i][m];
    }
    int ans = 1e9;
    vector<int> ansv;
    for (int j = 0; j < m; ++j) {
        vector<pii> v;
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(a[i][j], i);
            balance += a[i][j];
        }
        sort(all(v));
        vector<int> curans;
        for (int i = 0; balance < 0; ++i) {
            curans.push_back(v[i].second);
            balance -= v[i].first;
        }
        if ((int)curans.size() < ans) {
            ans = curans.size();
            ansv = curans;
        }
    }
    sort(all(ansv));
    cout << ansv.size() << endl;
    for (int x : ansv)
        cout << x + 1 << ' ';
    cout << endl;
}