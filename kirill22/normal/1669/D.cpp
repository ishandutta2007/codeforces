#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans = "YES", s;
        cin >> s;
        int x = 0, y = 0;
        for (auto c : s) {
            if (c == 'B') {
                x++;
            } else if (c == 'R') {
                y++;
            } else {
                if ((!x && y) || (x && !y)) {
                    ans = "NO";
                }
                x = y = 0;
            }
        }
        if ((!x && y) || (x && !y)) {
            ans = "NO";
        }
        cout << ans << '\n';
    }
}