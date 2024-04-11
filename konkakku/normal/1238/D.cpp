#include <bits/stdc++.h>
using namespace std;

int n, la = -1, lb = -1;
long long ans = 0;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (s[i] == s[i - 1]) {
                ans += i;
                if (s[i] == 'A' && lb > -1) {
                    ans--;
                } else if (s[i] == 'B' && la > -1) {
                    ans--;
                }
            } else {
                if (s[i] == 'A') {
                    ans += la + 1;
                } else {
                    ans += lb + 1;
                }
            }
        }
        if (s[i] == 'A') {
            la = i;
        } else {
            lb = i;
        }
    }
    cout << ans;
}