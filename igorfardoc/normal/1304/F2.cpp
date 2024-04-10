#include<bits/stdc++.h>
#define maxn 20000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[maxn * 4 + 7], lp[maxn * 4 + 7];
vi op;

void update(int now, int l, int r, int l1, int r1, int val) {
    if(l > r1 || l1 > r) return;
    op.push_back(now);
    if(l1 <= l && r <= r1) {
        t[now] += val;
        lp[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
    t[now] = max(t[now * 2], t[now * 2 + 1]) + lp[now];
}

void clear_tree() {
    for(const auto& el : op) {
        lp[el] = 0;
        t[el] = 0;
    }
    op.clear();
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    ++n;
    vvi a(n, vi(m, 0));
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vvi dp(n, vi(m - k + 1, 0));
    for(int i = n - 2; i >= 0; i--) {
        clear_tree();
        for(int j = 0; j < m; j++) {
            int l = max(0, j - k + 1);
            if(j < m - k + 1) {
                update(1, 0, m - 1, j, j, dp[i + 1][j]);
            }
            update(1, 0, m - 1, l, min(j, m - k), a[i + 1][j]);
            if(j >= k) {
                update(1, 0, m - 1, l, min(j, m - k), a[i][j]);
            }
        }
        for(int j = 0; j < m - k + 1; j++) {
            dp[i][j] = t[1];
            if(j == m - k) continue;
            int l = max(0, j - k + 1);
            update(1, 0, m - 1, l, j, a[i][j]);
            int r = min(m - k, j + k);
            update(1, 0, m - 1, j + 1, r, -a[i][j + k]);
        }
    }
    //cout << dp[n - 5][1] << endl;
    int mx = -1;
    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += a[0][i] + a[1][i];
    }
    for(int i = 0; i < m - k + 1; i++) {
        mx = max(mx, dp[1][i] + sum);
        sum -= a[0][i];
        sum -= a[1][i];
        if(i != m - k) {
            sum += a[0][i + k];
            sum += a[1][i + k];
        }
    }
    cout << mx;

}