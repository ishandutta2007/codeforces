#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n;
string s;
int p[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (s[i-1] == '1');
        }
        int res = 1e9;
        for (int i = 0; i <= n; i++) {
            int val = p[i] + n - i - (p[n] - p[i]);
            res = min(res, val);
            res = min(res, n - val);
        }
        cout << res << '\n';
    }
    return 0;
}