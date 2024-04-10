#include <bits/stdc++.h>
using namespace std;

class UF{
    public:
        vector<int> p;
        vector<int> rank;

        UF(int N) {
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; ++i) {
                p[i] = i;
            }
        }

        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);
                if (rank[x] > rank[y]) {
                    p[y] = x;
                }
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, w;
    cin >> n >> m >> w;
    
    vector<int> ws(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> ws[idx];
    vector<int> bs(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> bs[idx];
    
    UF uf(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unionSet(x, y);
    }

    vector<int> groups;
    vector<int> total_b(n, 0);
    vector<int> total_w(n, 0);
    vector<int> max_b(n, 0);
    vector<int> max_w(n, 0);

    for (int i = 0; i < n; ++i) {
        int p = uf.findSet(i);
        if (p == i) groups.push_back(i);
        total_b[p] += bs[i];
        total_w[p] += ws[i];
        max_b[p] = max(max_b[p], bs[i]);
        max_w[p] = max(max_w[p], ws[i]);
    }


    // for (int i : groups) 
        // cout << i << ": " << total_b[i] << " " << total_w[i] << endl;

    vector<int> dp(w + 1, 0); // best beauty per weight
    dp[0] = 1;

    vector<vector<int>> gs(n);
    for (int i = 0; i < n; ++i) {
        int p = uf.findSet(i);
        gs[p].push_back(i);
    }

    for (int i : groups) {
        vector<int> dp2(dp);
        for (int j = 0; j <= w; j++)
        {
            if (dp[j]) {
                if (j + total_w[i] <= w)
                    dp2[j + total_w[i]] = max(dp2[j + total_w[i]], dp[j] + total_b[i]);
                for (int k : gs[i]) {
                    if (j + ws[k] <= w)
                        dp2[j + ws[k]] = max(dp2[j + ws[k]], dp[j] + bs[k]);
                }
            }
        }
        dp = dp2;
    }

    cout << *max_element(dp.begin(), dp.end()) - 1 << endl;


    return 0;
}