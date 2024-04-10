#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int even = 0, zero = 0, sum = 0;
        for (char c : s) {
            if (c % 2 == 0)
                ++even;
            if (c == '0')
                ++zero;
            sum += c - '0';
        }
        cout << (sum % 3 == 0 && zero > 0 && even > 1 ? "red" : "cyan") << "\n";
    }
    return 0;
}