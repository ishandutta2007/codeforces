#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int y = 0, la = -1, ops = 0;
        while(y < n) {
            if((s[y] == '(') && (y == n-1)) {
                break;
            }
            else if(s[y] == '(') {
                y += 2;
                ops++;
                la = y - 1;
            }
            else {
                y++;
                while(y < n) {
                    if(s[y] == ')') {
                        la = y;
                        y++;
                        ops++;
                        break;
                    }
                    y++;
                }
            }
        }
        cout << ops << ' ' << n - la - 1 << '\n';
    }
}