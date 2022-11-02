#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int M = (int)(1e5 + 239);

int n, m;
int64 cnt_l[M], cnt_r[M], deg[M];
vector<int> r[M];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, f;
        cin >> s >> f;
        if (s > f) swap(s, f);
        s--, f--;
        cnt_r[s]++;
        r[s].push_back(f);
        cnt_l[f]++;
        deg[s]++;
        deg[f]++;
    }
    int64 cur = 0;
    for (int i = 0; i < n; i++) cur += cnt_l[i] * cnt_r[i];
    cout << cur << "\n";
    int q;
    cin >> q;
    for (int z = 0; z < q; z++) {
        int i;
        cin >> i;
        i--;
        cur -= cnt_l[i] * cnt_r[i];
        for (int t : r[i]) {
            cur -= cnt_r[t];
            r[t].push_back(i);
            cnt_l[t]--;
            cnt_r[t]++;
            cur += cnt_l[t];
        }
        cnt_l[i] = deg[i];
        cnt_r[i] = 0;
        r[i].clear();
        cout << cur << "\n";
    }
    return 0;
}