// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int x[200005], y[200005];
int rmstart[200005];

const int B = 500;

int cnt[505][505];
int zu[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i=0; i<m; i++) {
        int t, id;
        cin >> t >> id;

        t = 3-2*t;
        int x = ::x[id], y = ::y[id], w = x+y;
        if (x+y <= B) {
            if (t == 1) rmstart[id] = (i+x)%w;
            for (int i=0, j=rmstart[id]; i<y; i++, j=(j==w-1?0:j+1)) {
                cnt[w][j] += t;
            }
        } else {
            if (t == 1) {
                rmstart[id] = i+x;
                for (int j=i+x; j<m; j+=w) {
                    zu[j] += 1;
                    if (j+y < m) zu[j+y] -= 1;
                }
            } else {
                for (int j=rmstart[id]; j<m; j+=w) {
                    if (j >= i) zu[j] -= 1;
                    if (j+y < m && j+y >= i) zu[j+y] += 1;
                }

                int resto = i-1-rmstart[id];
                if (resto >= 0) {
                    resto %= w;
                    if (resto < y) {
                        zu[i-1] -= 1;
                    }
                }
            }
        }

        if (i) zu[i] += zu[i-1];

        int ans = zu[i];
        for (int r=1; r<=B; r++) {
            ans += cnt[r][i%r];
        }
        
        cout << ans << '\n';
    }
}