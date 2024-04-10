#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1E9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int ans = 1;
    vector<int> f(s.length() + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= s.length(); ++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    for (int i = 0; i < s.length(); ) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << "\n";
            return 0;
        }
        int j = i;
        while (j < s.length() && s[i] == s[j])
            ++j;
        if (s[i] == 'n' || s[i] == 'u')
            ans = 1LL * ans * f[j - i] % MOD;
        i = j;
    }
    cout << ans << "\n";
    return 0;
}