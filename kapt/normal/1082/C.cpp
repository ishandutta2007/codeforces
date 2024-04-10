#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<int> subs[maxn];
int nex[maxn], pre[maxn], sum[maxn];

bool cmp(int x, int y) {
    return x > y;
}

main() {
    int n, m;
    int s, r;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s >> r;
        subs[s - 1].push_back(r);
    }
    for (int i = 0; i < m; ++i) {
        sort(subs[i].begin(), subs[i].end(), cmp);
        nex[i] = i + 1;
        pre[i] = i - 1;
    }
    int start = 0;
    int ans = 0, nowans = 0;
    for (int i = 1; i <= n; ++i) {
        int now = start;
        while (now != m) {
            if (subs[now].size() < i || sum[now] + subs[now][i - 1] < 0) {
                nowans -= sum[now];
                if (now == start) {
                    start = nex[now];
                    now = nex[now];
                    continue;
                }
                nex[pre[now]] = nex[now];
                pre[nex[now]] = pre[now];
                now = nex[now];
            } else {
                sum[now] += subs[now][i - 1];
                nowans += subs[now][i - 1];
                now = nex[now];
            }
        }
        if (nowans > ans) {
            ans = nowans;
        }
    }
    cout << ans;
    return 0;
}