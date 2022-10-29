#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans1 = 10, ans2 = 10;
        int now = 0;
        for (int i = 0; i < 10; i++) {
            if (i & 1) {
                if (s[i] == '1') now--;
            } else {
                if (s[i] != '0') now++;
            }
            if ((9 - i + 1) / 2 < now) {
                ans1 = i + 1;
                break;
            }
        }
        now = 0;
        for (int i = 0; i < 10; i++) {
            if (i & 1) {
                if (s[i] != '0') now++;
            } else {
                if (s[i] == '1') now--;
            }
            if ((9 - i) / 2 < now) {
                ans2 = i + 1;
                break;
            }
        }
        cout << min(ans1, ans2) << endl;
    }
}