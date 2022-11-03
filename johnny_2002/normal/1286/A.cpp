#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;

int f[N][N][2];

int n, a[N];

int DP(int r0, int r1, int odd) {
    if (r1 == 0 && r0 == 0) return 0;
    int &ans = f[r0][r1][odd];
    if (ans != -1) return ans;


    ans = n + 2;
    int cur = r0 + r1;

    if ((a[cur] == 0 || a[cur] % 2 == 1) && r1) {
        int res = DP(r0, r1 - 1, 1);
        if (cur != n && !odd) res++;
        ans = min(ans, res);
    }
    if ((a[cur] == 0 || a[cur] % 2 == 0) && r0) {
        int res = DP(r0 - 1, r1, 0);
        if (cur != n && odd) res++;
        ans = min(ans, res);
    }
    return ans;

}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(f, -1, sizeof(f));
    cout << DP(n / 2, (n + 1) / 2, 0);
}