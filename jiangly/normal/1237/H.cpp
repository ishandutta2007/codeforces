#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string a, b;
    cin >> a >> b;
    n = a.length();
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    for (int i = 0; i < n; i += 2) {
        if (a[i] == '0' && a[i + 1] == '0')
            ++a0;
        if (a[i] == '1' && a[i + 1] == '1')
            ++a1;
        if (b[i] == '0' && b[i + 1] == '0')
            ++b0;
        if (b[i] == '1' && b[i + 1] == '1')
            ++b1;
    }
    if (a0 != b0 || a1 != b1) {
        cout << -1 << "\n";
        return;
    }
    vector<int> sol;
    int a01 = 0, b10 = 0;
    for (int i = 0; i < n; i += 2) {
        if (a[i] == '0' && a[i + 1] == '1')
            ++a01;
        if (b[i] == '1' && b[i + 1] == '0')
            ++b10;
    }
    int mark = -1;
    if (a01 != b10) {
        int delta = 0;
        for (int i = 0; i < n; i += 2) {
            if (a[i] == '0' && a[i + 1] == '1')
                ++delta;
            if (a[i] == '1' && a[i + 1] == '0')
                --delta;
            if (a01 - delta == b10) {
                sol.push_back(i + 2);
                reverse(a.begin(), a.begin() + i + 2);
                break;
            }
        }
        if (sol.empty()) {
            delta = 0;
            for (int i = 0; i < n; i += 2) {
                if (b[i] == '1' && b[i + 1] == '0')
                    ++delta;
                if (b[i] == '0' && b[i + 1] == '1')
                    --delta;
                if (b10 - delta == a01) {
                    mark = i + 2;
                    reverse(b.begin(), b.begin() + i + 2);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i += 2) {
        char c = b[n - i - 2], d = b[n - i - 1];
        for (int j = i; j < n; j += 2)
            if (a[j] == d && a[j + 1] == c) {
                if (j != 0)
                    sol.push_back(j);
                reverse(a.begin(), a.begin() + j);
                sol.push_back(j + 2);
                reverse(a.begin(), a.begin() + j + 2);
                break;
            }
    }
    if (mark != -1)
        sol.push_back(mark);
    cout << sol.size() << "\n";
    for (int i = 0; i < sol.size(); ++i)
        cout << sol[i] << " \n"[i == sol.size() - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}