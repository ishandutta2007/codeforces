#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 5005;

typedef long long ll;
ll a[N], b[N];
int f[N][N];
int n;

inline ll getS(int l, int r) {
    return b[r] - b[l - 1];
}

int main() {
//    freopen("in", "r", stdin);

    memset(f, 63, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        b[i] = b[i - 1] + a[i];
    }


    for (int r = 1; r <= n; ++r) {
        int lboard = r;

        f[1][r] = r - 1;
        for (int l = r; l; --l) {
            while (lboard >= l) {
                --lboard;
            }
            
            int needS = getS(l, r);
            while (lboard && getS(lboard, l - 1) < needS) {
                --lboard;
            }
            if (!lboard) break;

            f[l][r] = min(f[l][r], f[lboard][l - 1] + (r - l));
        }

        for (int l = 2; l <= r; ++l) {
            f[l][r] = min(f[l][r], f[l - 1][r]);
        }
    }

    //for (int l = 1; l <= n; ++l)
    //    for (int r = l; r <= n; ++r)
    //        if (f[l][r] < 1e9) cout << l << " " << r << " " << f[l][r] << endl; 

    int ans = f[1][n];
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, f[i][n]);
    }

    cout << ans << endl;

    return 0;
}