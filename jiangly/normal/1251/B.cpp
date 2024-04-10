#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 50;
int n;
string s;
int c;
void solve() {
    cin >> n;
    c = 0;
    bool even = true;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s.length() % 2 == 1)
            even = false;
        c += count(s.begin(), s.end(), '0');
    }
    cout << n - (even && c % 2 == 1) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}