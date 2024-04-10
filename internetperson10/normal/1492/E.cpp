#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<vector<int>> nums;
vector<int> test;
vector<map<int, int>> ct;
vector<vector<pair<int, int>>> ctsort;

bool check() {
    // cout << "Checking ";
    // for(int i = 0; i < test.size(); i++) cout << test[i] << ' ';
    for(int i = 0; i < nums.size(); i++) {
        int x = 0;
        for(int j = 0; j < test.size(); j++) {
            if(test[j] != nums[i][j]) x++;
        }
        if(x > 2) return false;
    }
    // cout << "...good!\n";
    return true;
}

bool rec(int i, int s) {
    if(s < 0) return false;
    if(i == -1) {
        return check();
    }
    for(int j = 0; j < ctsort[i].size(); j++) {
        test[i] = ctsort[i][j].second;
        if(rec(i-1, s-ctsort[i][j].first)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> m >> n;
    nums.resize(m);
    ct.resize(n);
    ctsort.resize(n);
    test.resize(n);
    for(int i = 0; i < m; i++) {
        nums[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> nums[i][j];
            ct[j][nums[i][j]]++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(pair<int, int> p : ct[i]) {
            ctsort[i].push_back({m - p.second, p.first});
        }
        sort(ctsort[i].begin(), ctsort[i].end());
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < ctsort[i].size(); j++) {
    //         cout << ctsort[i][j].second << ' ' << ctsort[i][j].first << " | ";
    //     }
    //     cout << '\n';
    // }
    if(rec(n-1, 2*m)) {
        cout << "Yes\n";
        for(int i = 0; i < n; i++) cout << test[i] << ' ';
    }
    else cout << "No\n";
}