#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0, sign = +1, val = 0;
    string s;
    cin >> s;
    for (char c : s) {
        if (c == '-' || c == '+') {
            ans += sign * val;
            sign = c == '-' ? -1 : 1;
            val = 0;
        }
        val = 10 * val + (int)(c - '0');
    }
    ans += sign * val;
    cout << ans;
    return 0;
}