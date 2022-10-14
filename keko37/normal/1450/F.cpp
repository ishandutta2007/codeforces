#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, cnt;
int a[MAXN], br[MAXN], pola[MAXN];
vector <int> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v[i].clear();
            br[i] = pola[i] = 0;
        }
        cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i - 1]) cnt++;
            v[cnt].push_back(a[i]);
        }
        for (int i = 1; i <= cnt; i++) {
            if (v[i][0] == v[i].back()) {
                br[v[i][0]]++;
            } else {
                pola[v[i][0]]++;
                pola[v[i].back()]++;
            }
        }
        int mx = -1e9, ind = -1;
        for (int i = 1; i <= n; i++) {
            int val = br[i] - 1 - (cnt - br[i] - pola[i]);
            if (val > mx) {
                mx = val;
                ind = i;
            }
        }
        int sol = cnt - 1;
        if (mx > 0) {
            for (int i = 2; i <= n; i++) {
                if (a[i] != a[i - 1] && a[i] != ind && a[i - 1] != ind) {
                    sol++;
                    mx--;
                }
                if (mx == 0) break;
            }
        }
        if (mx > 0) cout << "-1\n"; else cout << sol << '\n';
    }
    return 0;
}