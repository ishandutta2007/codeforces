#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    // Do it greedily then yay. Divide set into parts then solve it recursively
    int n;
    cin >> n;
    vector<vector<int>> a(1), b(1);
    a[0].resize(n);
    b[0].resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[0][i];
    }
    int ans = 0;
    for(int d = 29; d >= 0; d--) {
        bool ok = true;
        for(int i = 0; i < a.size(); i++) {
            sort(a[i].begin(), a[i].end());
            sort(b[i].rbegin(), b[i].rend());
            int tot = 0;
            for(int j = 0; j < a[i].size(); j++) {
                tot += (bool)(a[i][j] & (1 << d));
                tot += (bool)(b[i][j] & (1 << d));
            }
            if(tot != a[i].size()) ok = false;
        }
        if(ok) {
            ans += (1 << d);
            int curr_size = a.size();
            for(int i = 0; i < curr_size; i++) {
                a.push_back(vector<int>());
                b.push_back(vector<int>());
                while(a[i].size()) {
                    if(a[i].back() & (1 << d)) {
                        a.back().push_back(a[i].back());
                        a[i].pop_back();
                    }
                    else break;
                }
                while(b[i].size()) {
                    if(!(b[i].back() & (1 << d))) {
                        b.back().push_back(b[i].back());
                        b[i].pop_back();
                    }
                    else break;
                }
                if(a.back().size() == 0) {
                    a.pop_back();
                    b.pop_back();
                }
            }
        }
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < a[i].size(); j++) {
                if(a[i][j] & (1 << d)) a[i][j] -= (1 << d);
                if(b[i][j] & (1 << d)) b[i][j] -= (1 << d);
            }
        }
    }
    cout << ans << '\n';
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