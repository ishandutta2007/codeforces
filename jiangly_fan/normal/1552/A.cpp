#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        auto t = s;
        sort(t.begin(), t.end());
        int ans = 0;
        for (int i = 0; i < n; i += 1)
            ans += t[i] != s[i];
        cout << ans << "\n";
    }
    return 0;
}