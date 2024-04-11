#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
vector<int> used;
int n, K;
const int N = 222222;
using ll = long long;
ll sum[N][6];
ll cnt[N][6];
ll totalSum[N][6];
ll totalCnt[N][6];

void dfs(int x) {
    used[x] = 1;

    ll cntPresum[6], sumPresum[6];
    memset(cntPresum, 0, sizeof(cntPresum));
    memset(sumPresum, 0, sizeof(sumPresum));

    for (int y : g[x]) {
        if (used[y]) {
            continue;
        }

        dfs(y);

        for (int kk = 0; kk < K; ++kk) {
            if (kk + 1 < K) {
                cnt[x][kk + 1] += cnt[y][kk];
                sum[x][kk + 1] += sum[y][kk];
            } else {
                cnt[x][0] += cnt[y][kk];
                sum[x][0] += sum[y][kk] + cnt[y][kk];
            }
        }
        for (int kk = 0; kk < K; ++kk) {
            for (int kk2 = 0; kk2 < K; ++kk2) {
                int to = (kk2 + kk + 2) % K;
                ll toAdd = (kk2 + kk + 2) / K;               
                totalSum[x][to] += sumPresum[kk] * cnt[y][kk2] + sum[y][kk2] * cntPresum[kk] + toAdd * cntPresum[kk] * cnt[y][kk2];
                totalCnt[x][to] += cntPresum[kk] * cnt[y][kk2];
            }
        }

        for (int kk = 0; kk < K; ++kk) {
            cntPresum[kk] += cnt[y][kk];
            sumPresum[kk] += sum[y][kk];
        }
    }

    cnt[x][0] += 1;

    /*
    cerr << x << endl;
    cerr << "cnt: ";
    for (int k = 0; k < K; ++k) {
        cerr << cnt[x][k] << " " ;
    }
    cerr << endl;
    cerr << "sum: ";
    for (int k = 0; k < K; ++k) {
        cerr << sum[x][k] << " " ;
    }
    cerr << endl;
    cerr << "totalSum: ";
    for (int k = 0; k < K; ++k) {
        cerr << totalSum[x][k] << " " ;
    }
    cerr << endl;
    cerr << "totalCnt: ";
    for (int k = 0; k < K; ++k) {
        cerr << totalCnt[x][k] << " " ;
    }
    cerr << endl;
    cerr << endl;
    */
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> K;
    g.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    used.resize(n + 1);
    dfs(1);
    ll ans = 0;
    for (int x = 1; x <= n; ++x) {
        for (int k  = 0; k < K; ++k) {
            ans += totalSum[x][k];
            ans += sum[x][k];
            if (k > 0) {
                ans += totalCnt[x][k];
                ans += cnt[x][k];
            }
        }
    }
    cout << ans << '\n';

    return 0;
}