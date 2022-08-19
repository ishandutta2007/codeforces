#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int cL = count(s.begin(), s.end(), 'L');
    int cR = count(s.begin(), s.end(), 'R');
    int cU = count(s.begin(), s.end(), 'U');
    int cD = count(s.begin(), s.end(), 'D');
    if (cL == 0 || cR == 0) {
        int ans = min(1, min(cU, cD));
        cout << 2 * ans << "\n";
        for (int i = 0; i < ans; ++i)
            cout << "U";
        for (int i = 0; i < ans; ++i)
            cout << "D";
        cout << "\n";
    } else if (cU == 0 || cD == 0) {
        int ans = min(1, min(cL, cR));
        cout << 2 * ans << "\n";
        for (int i = 0; i < ans; ++i)
            cout << "L";
        for (int i = 0; i < ans; ++i)
            cout << "R";
        cout << "\n";
    } else {
        int ans = min(cL, cR) + min(cU, cD);
        cout << 2 * ans <<"\n";
        for (int i = 0; i < min(cL, cR); ++i)
            cout << "L";
        for (int i = 0; i < min(cU, cD); ++i)
            cout << "U";
        for (int i = 0; i < min(cL, cR); ++i)
            cout << "R";
        for (int i = 0; i < min(cU, cD); ++i)
            cout << "D";
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}