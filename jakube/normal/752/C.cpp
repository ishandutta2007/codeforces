#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;

    char dir_x = '?';
    char dir_y = '?';

    int cnt = 1;
    for (char c : s) {
        if (c == 'R' || c == 'L') {
            if (dir_x == '?') {
                dir_x = c;
            }
            else if (c != dir_x) {
                cnt++;
                dir_x = c;
                dir_y = '?';
            }
        }
        else if (c == 'U' || c == 'D') {
            if (dir_y == '?') {
                dir_y = c;
            }
            else if (c != dir_y) {
                cnt++;
                dir_y = c;
                dir_x = '?';
            }
        }
    }

    cout << cnt << endl;

    return 0;
}