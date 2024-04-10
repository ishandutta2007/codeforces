#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    bool ok = true;
    // Answer always n + m - 2 if the robot can reach, just go to edges
    if(sx - d <= 1 && sx + d >= n) {
        ok = false;
    }
    if(sy - d <= 1 && sy + d >= m) {
        ok = false;
    }
    if(sx - d <= 1 && sy - d <= 1) {
        ok = false;
    }
    if(sx + d >= n && sy + d >= m) {
        ok = false;
    }
    if(!ok) cout << "-1\n";
    else cout << n + m - 2 << '\n';
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