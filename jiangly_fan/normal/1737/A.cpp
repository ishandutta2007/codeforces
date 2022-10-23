#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> c(26);
        for (char si : s)
            c[si - 'a'] += 1;
        for (int i = 0; i < k; i += 1) {
            int x = 0, j = n / k;
            while (c[x] and j) {
                c[x] -= 1;
                x += 1;
                j -= 1;
            }
            cout << char('a' + x);
        }
        cout << "\n";
    }
}