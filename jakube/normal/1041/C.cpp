#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    
    set<pair<int, int>> s(v.begin(), v.end());
    vector<int> res(n, 0);


    for (int i = 1; i <= n; i++) {
        int cur = 0;
        while (1) {
            auto it = s.lower_bound({cur, 0});
            if (it == s.end())
                break;
            res[it->second] = i;
            cur = it->first + d + 1;
            s.erase(it);
        }
    }

    cout << *max_element(res.begin(), res.end()) << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}