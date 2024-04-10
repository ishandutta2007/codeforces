#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e6 + 1;
const int mod = 998244353;
bool bl[3], br[3];
string ans, s;

int main() {
    int i, j, k, n, w, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (i = 0; i < s.size(); ++i)
        s[i] -= 'a';
    for (i = 0; i < s.size() / 4; ++i) {
        for (j = 0; j < 3; ++j) {
            bl[j] = 0;
            br[j] = 0;
        }
        for (j = 0; j < 2; ++j) {
            bl[s[2*i + j]] = 1;
            br[s[s.size() - 2 * i - j - 1]] = 1;
        }
        for (j = 0; j < 3; ++j)
        if (bl[j] && br[j]) {
            ans += (char) (j + 'a');
            break;
        }
    }
    cout << ans;
    if (s.size() % 4 != 0)
        cout << (char) (s[2*i] + 'a');
    for (i = 0; i < ans.size(); ++i)
        cout << ans[ans.size() - i - 1];
}