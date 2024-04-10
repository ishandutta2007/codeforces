#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, m;
int cnt[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        int sol = 0;
        for (int i = 0; i <= 101; i++) {
            if (cnt[i] == 2) sol++;
        }
        cout << sol << '\n';
    }
    return 0;
}