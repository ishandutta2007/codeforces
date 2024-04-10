#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int t, n;
int p[MAXN];

int main () {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) p[i] = 0;
        int sol = MAXN;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (p[x] != 0) sol = min(sol, i - p[x] + 1);
            p[x] = i;
        }
        if (sol < MAXN) cout << sol << '\n'; else cout << "-1\n";
    }
    return 0;
}