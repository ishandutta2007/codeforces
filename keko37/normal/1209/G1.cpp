#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, q, sol;
int a[MAXN];
int lef[MAXN], rig[MAXN], br[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        int c = a[i];
        br[c]++;
        if (br[c] == 1) {
            lef[c] = rig[c] = i;
        } else {
            rig[c] = i;
        }
    }
    sol = n;
    int curr = 1, mx = 0;
    for (int i=1; i<=n; i++) {
        curr = max(curr, rig[a[i]]);
        mx = max(mx, br[a[i]]);
        if (curr == i) {
            sol -= mx;
            mx = 0;
        }
    }
    cout << sol;
    return 0;
}