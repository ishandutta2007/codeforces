#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s + '0';
    int cnt = 0;
    int cnt2 = 0;
    for (char c : s) {
        if (c == '1') {
            cnt = 0;
            cnt2++;
            if (cnt2 == 2) {
                cout << "No" << '\n';
                return 0;
            }
        } else {
            cnt++;
            cnt2 = 0;
            if (cnt == 3) {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';
}