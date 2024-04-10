#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 83;

int n, k, curr_k, curr_cost;
int pos[MAXN];
int dp[MAXN][MAXN][MAXN * MAXN / 2];

void calc (int lef, int rig, int lo, int hi) {
    if (lef > rig) return;
    int mid = (lef + rig) / 2;
    int lim = min(hi, mid);
    int res = 1e9, ind = lo;
    for (int i = lo; i <= lim; i++) {
        int d = abs(i - pos[curr_k]);
        if (d <= curr_cost) {
            int tmp = dp[i - 1][curr_k - 1][curr_cost - d] + (mid - i) * (mid - i - 1) / 2;
            if (tmp < res) {
                res = tmp;
                ind = i;
            }
        }
    }
    dp[mid][curr_k][curr_cost] = res;
    calc(lef, mid - 1, lo, ind);
    calc(mid + 1, rig, ind, hi);
}

void ispis () {
    cout << curr_k << " " << curr_cost << "  ";
    for (int i = 1; i <= n; i++) {
        cout << dp[i][curr_k][curr_cost] << " ";
    }
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1) {
            k++;
            pos[k] = i;
        }
    }
    for (int pos = 0; pos <= n; pos++) {
        for (curr_cost = 0; curr_cost <= n * (n - 1) / 2; curr_cost++) {
            dp[pos][0][curr_cost] = pos * (pos - 1) / 2;
        }
    }
    for (curr_k = 1; curr_k <= k; curr_k++) {
        for (curr_cost = 0; curr_cost <= n * (n - 1) / 2; curr_cost++) {
            calc(1, n, 1, n);
            //ispis();
        }
    }
    for (curr_cost = 0; curr_cost <= n * (n - 1) / 2; curr_cost++) {
        cout << (n - k) * (n - k - 1) / 2 - dp[n][k][curr_cost] << " ";
    }
    return 0;
}