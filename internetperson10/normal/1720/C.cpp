#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> v(r);
    int tot = 0, mi = 4;
    for(int i = 0; i < r; i++) {
        cin >> v[i];
        for(int j = 0; j < c; j++) {
            tot += (v[i][j] - '0');
        }
    }
    for(int i = 0; i < r-1; i++) {
        for(int j = 0; j < c-1; j++) {
            int su = 0;
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    if(v[i+k][j+l] == '1') su++;
                }
            }
            mi = min(mi, max(0, su-2));
        }
    }
    cout << tot - mi << '\n';
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