#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    set<int> s;
    vector<pair<int, int>> ord;
    ord.push_back({0, -1});
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        s.insert(i);
        ord.push_back({nums[i], i});
    }
    string st(n, '0');
    sort(ord.begin(), ord.end());
    for(int i = 1; i <= n; i++) {
        if(ord[i].first != ord[i-1].first) {
            int x = min(q, ord[i].first) - ord[i-1].first;
            for(int j = 0; j < x; j++) {
                if(s.size() == 0) break;
                int b = *(--s.end());
                s.erase(b);
                st[b] = '1';
            }
        }
        if(ord[i].first > q) break;
        s.erase(ord[i].second);
        st[ord[i].second] = '1';
    }
    cout << st << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}