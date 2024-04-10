#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    string even, odd;
    for (char c : s)
        if (c % 2 == 1)
            odd += c;
        else
            even += c;
    merge(even.begin(), even.end(), odd.begin(), odd.end(), s.begin());
    cout << s << "\n";
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