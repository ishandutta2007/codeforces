#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    const int INF = 1e9 + 6;
    vector<int> b(n, INF), c(n, -1);
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        a.push_back(a[i]);
    }
    if (2 * mn >= mx) {
        for (int i = 0; i < n; ++i) {
            cout << "-1 ";
        }
        cout << endl;
        return 0;
    }
    set<pii> st;
    for (int i = 0; i < 2 * n; ++i) {
        while (!st.empty() && 2 * a[i] < -st.begin()->first) {
            int idx = st.begin()->second;
            if (idx < n) {
                b[idx] = i - idx;
            }
            st.erase(st.begin());
        }
        st.insert({-a[i], i});
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            b[j] = min(b[j], 1 + b[(j + 1) % n]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}