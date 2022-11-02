#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;
int cntm[MAXN], cntp[MAXN];
vector<pair<int, int>> cost[MAXN];

int get(int i, int j) {
    if (i == j) {
        return cost[i][0].first + cost[i][1].first;
    }
    return cost[i][0].first + cost[j][0].first;
}

main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f;
        int res = 0;
        for (int j = 0; j < f; ++j) {
            int x;
            cin >> x;
            x--;
            res += (1 << x);
        }
        cntm[res]++;
    }
    for (int i = 0; i < m; ++i) {
        int c, r;
        cin >> c >> r;
        int res = 0;
        for (int j = 0; j < r; ++j) {
            int x;
            cin >> x;
            x--;
            res += (1 << x);
        }
        cntp[res]++;
        cost[res].push_back({c, i + 1});
    }
    for (int i = 0; i < MAXN; ++i) {
        sort(cost[i].begin(), cost[i].end());
    }
    int maxg = -1;
    int minc = 1e9;
    int ansi = -1, ansj = -1;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            if (cntp[i] == 0 || cntp[j] == 0) {
                continue;
            }
            if (i == j && cntp[i] < 2) {
                continue;
            }
            int cur_ans = get(i, j);
            int res = i | j;
            int cnt = 0;
            for (int k = 0; k < MAXN; ++k) {
                if ((res | k) == res) {
                    cnt += cntm[k];
                }
            }
            if (cnt > maxg) {
                maxg = cnt;
                minc = cur_ans;
                ansi = i;
                ansj = j;
            } else if (cnt == maxg && minc > cur_ans) {
                minc = cur_ans;
                ansi = i;
                ansj = j;
            }
        }
    }
    if (ansi == ansj) {
        cout << cost[ansi][0].second << " ";
        cout << cost[ansi][1].second;
    } else {
        cout << cost[ansi][0].second << " ";
        cout << cost[ansj][0].second;
    }
    return 0;
}