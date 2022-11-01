#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    set<int> maxrind;
    for (int i = 0; i < n; i++) cin >> s[i];
    int maxr = -INT_MAX, maxc = -INT_MAX;
    int maxrow = 0;
    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < m; j++) if (s[i][j] == '*') ++now;
        if (maxr < now) {
            maxrow = i;
            maxr = now;
        }
    }
    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < m; j++) if (s[i][j] == '*') ++now;
        if (maxr == now) {
            maxrind.emplace(i);
        }
    }
    // cout << maxr << "\n";
    maxr = m - maxr;
    for (int i = 0; i < m; i++) {
        int now = 0;
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (maxrind.find(j) != maxrind.end() && s[j][i] == '.' && !flag) {
                ++now;
                flag = true;
            }

            if (s[j][i] == '*') ++now;
            maxc = max(maxc, now);
        }
    }
    // cout << maxc << "\n";
    maxc = n - maxc;
    cout << maxr + maxc << "\n";
}

int main(){
    int q;
    cin>>q;
    // q = 1;
    while(q--) {
        solve();
    }
    return 0;
}