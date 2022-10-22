#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int>> a(n);
    vector<int> l;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {{x, y}, i};
        l.push_back(x);
        l.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(l.begin(), l.end());
    vector<int> ans;
    int ii = 0;
    set<pair<int, int>> b, b2;
    for (auto r : l) {
        while (b.size() > 0) {
            auto x = *b.begin();
            if (x.first < r) {
                b.erase(b.begin());
                b2.erase({-x.first, x.second});
            }
            else {
                break;
            }
        }
        for (int i = ii; i < a.size(); i++) {
            if (a[i].first.first <= r && a[i].first.second >= r) {
                b.insert({a[i].first.second, a[i].second});
                b2.insert({-a[i].first.second, a[i].second});
                ii++;
            }
            else if (a[i].first.first <= r) {
                continue;
            }
            else {
                break;
            }
        }
        while (b2.size() > k) {
            auto x = *b2.begin();
            x.first = - x.first;
            ans.push_back(x.second);
            //cout << r << " " << x.second << endl;
            b2.erase(b2.begin());
            b.erase(x);
        }
    }
    cout << ans.size() << endl;
    for (auto c : ans) {
        cout << c + 1 << " ";
    }
}