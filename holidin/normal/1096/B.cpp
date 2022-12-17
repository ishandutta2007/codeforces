#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 1;
const int mod =  998244353;

int main() {
    int i, j, n, l, r, k;
    string s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (k = s.size() - 1; k > 0; --k)
    if (s[k] != s[k - 1])
        break;
    long long ans = 0;
    if (s[0] != s[s.size() - 1]) {
        ans += s.size() - k + 1;
        ++ans;
        i = 0;
        while (s[i] == s[i + 1])
            ++ans, ++i;
        cout << ans;
        return 0;
    }
    for (i = 0; i < s.size(); ++i) {
        if (k <= i)
            ans += s.size() - i + 1;
        else
            ans += s.size() - k + 1;
        if (i != 0 && s[i] != s[i - 1])
            break;
    }
    cout << ans % mod;
}