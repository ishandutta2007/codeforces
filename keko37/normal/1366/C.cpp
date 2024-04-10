#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n, m;
int aa[MAXN], bb[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(aa, 0, sizeof aa);
        memset(bb, 0, sizeof bb);
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dual = n-1 + m-1 - i - j;
                int x; cin >> x;
                if (i + j == dual) continue;
                if (x == 0) aa[min(i + j, dual)]++; else bb[min(i + j, dual)]++;
            }
        }
        int sol = 0;
        for (int i = 0; i < n + m + 2; i++) {
            sol += min(aa[i], bb[i]);
        }
        cout << sol << '\n';
    }
    return 0;
}