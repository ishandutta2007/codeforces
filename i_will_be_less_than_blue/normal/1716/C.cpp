#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 200005;
int m, mxadd[2][N], mxsub[2][N], a[2][N];
void solve(){
    cin >> m;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    a[0][0] = -1000000000;
        mxadd[i][m]=mxsub[i][m]=INT_MIN;
        for (int j = m - 1; j >= 0; --j) {
            mxadd[i][j]=max(mxadd[i][j+1], a[i][j] + j);
            mxsub[i][j]=max(mxsub[i][j+1], a[i][j] - j);
        }
    }
    int ans = INT_MAX, cur = INT_MIN;
    for (int i = 0; i < m; ++i) {
        if (i & 1) {
            ans = min(ans, max(cur, max(mxsub[1][i] - i, mxadd[0][i] -2 * m - i + 1)));
            cur = max(cur, a[1][i] - 2 * i);
            cur = max(cur, a[0][i] - 2 * i - 1);
        } else {
            ans = min(ans, max(cur, max(mxsub[0][i] - i, mxadd[1][i] -2 * m - i + 1)));
            cur = max(cur, a[0][i] - 2 * i);
            cur = max(cur, a[1][i] - 2 * i - 1);
        }
    }
    cout << ans + 2 * m << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}