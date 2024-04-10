#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int t, n, x;
string s;
int p[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x >> s;
        for (int i = 0; i < n; i++) {
            if (i == 0) p[i] = 0; else p[i] = p[i - 1];
            if (s[i] == '0') p[i]++; else p[i]--;
        }
        if (p[n-1] == 0) {
            bool naso = 0;
            for (int i = 0; i < n; i++) {
                if (p[i] == x) naso = 1;
            }
            if (naso) cout << -1 << '\n'; else cout << 0 << '\n';
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((x - p[i]) % abs(p[n-1]) == 0 && (x - p[i]) / p[n-1] >= 0) cnt++;
            }
            if (x == 0) cnt++;
            cout << cnt << '\n';
        }
    }
    return 0;
}