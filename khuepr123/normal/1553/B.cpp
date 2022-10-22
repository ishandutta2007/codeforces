
#include <bits/stdc++.h>

using namespace std;
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define MOD 1000000007
#define MOD2 1000000009
#define INF 1000000000000000000
#define EPS 1e-6
string s, t;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        cin >> s;
        cin >> t;
        int n = s.length(), m = t.length();
        s = '?' + s;
        t = '?' + t;
        int noaonofs = 0, noaonofs2 = 0;
        for1(i,1,m) {
            noaonofs = (noaonofs * 43 + (t[i] + 1 - 'a')) % MOD;
            noaonofs2 = (noaonofs2 * 61 + (t[i] + 1 - 'a')) % MOD2;
        }

        bool ans = 0;
        for1(i,1,n) if (n - i + n >= m) {
            for1(j,i,min(n, i + m - 1)) {
                int r1 = 0, r2 = 0;
                for1(k,i,j) {
                    r1 = (r1 * 43 + (s[k] + 1 - 'a')) % MOD;
                    r2 = (r2 * 61 + (s[k] + 1 - 'a')) % MOD2;
                }
                for2(k,j - 1,j - (m - (j - i + 1))) {
                    r1 = (r1 * 43 + (s[k] + 1 - 'a')) % MOD;
                    r2 = (r2 * 61 + (s[k] + 1 - 'a')) % MOD2;
                }

                if (r1 == noaonofs && r2 == noaonofs2) {
                    ans = 1;
                    goto nxtdddd;
                }
            }
        }

        nxtdddd:;
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

}