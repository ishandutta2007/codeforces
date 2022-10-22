#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool b[1001][1001];
bool d[1001][1001];

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            b[i][j] = (s[j] == '1');
            d[i][j] = 0;
        }
    }
    for(int i = 0; i < k-1; i++) {
        for(int j = 0; j <= i; j++) {
            d[n-k+i+1][j] = 1;
            d[k-2-i][n-1-j] = 1;
        }
    }
    vector<pair<int, int>> v;
    for(int i = n-k+1; i >= 0; i--) {
        v.push_back({i, 0});
    }
    for(int i = 1; i <= n-k+1; i++) {
        v.push_back({0, i});
    }
    bool ok = true;
    for(int z = 1; z < k; z++) {
        bool moved = true;
        while(moved) {
            moved = false;
            for(int i = 1; i < v.size() - 1; i++) {
                if(v[i-1] == make_pair(v[i].first + 1, v[i].second)) {
                    if(v[i+1] == make_pair(v[i].first, v[i].second + 1)) {
                        if(b[v[i].first][v[i].second] == 1) {
                            v[i].first++;
                            v[i].second++;
                            moved = true;
                        }
                    }
                }
            }
        }
        for(auto &p : v) {
            d[p.first][p.second] = true;
            p.first++;
            p.second++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(b[i][j] == 0 && d[i][j] == 0) {
                ok = false;
            }
        }
    }
    if(!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << d[i][j];
        }
        cout << '\n';
    }
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