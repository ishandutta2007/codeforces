#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        set<pii> s;
        for (int i = 0; i < m; ++i) {
            s.emplace(0, i);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int y;
            cin >> y;
            auto q = *s.begin();
            s.erase(s.begin());
            q.first += y;
            ans.push_back(q.second + 1);
            s.insert(q);
        }
        cout << "YES\n";
        for (int i = 0; i < ans.size(); ++i) {
            if (i)
                cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }



}