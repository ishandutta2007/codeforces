#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    vector<vector<long long>> wsum(Q);
    vector<vector<int>> parent(Q);
    vector<long long> weights(Q);
    int idx = 0;
    weights[0] = 0;
    int last = 0;

    while (Q --> 0) {
        int t;
        long long p, q;
        cin >> t >> p >> q;
        if (t == 1) {
            int R = p ^ last;
            R--;
            long long W = q ^ last;

            idx++;
            weights[idx] = W;
            // find first parent >= W
            if (weights[R] >= W) {
                parent[idx].push_back(R);
                wsum[idx].push_back(weights[R]);
            } else {
                int cur = R;
                for (int i = parent[cur].size() - 1; i >= 0; i--) {
                    if (i < (int)parent[cur].size() && weights[parent[cur][i]] < W)
                        cur = parent[cur][i];
                }
                if (!parent[cur].empty()) {
                    cur = parent[cur][0];
                    assert(weights[cur] >= W);
                    parent[idx].push_back(cur);
                    wsum[idx].push_back(weights[cur]);
                }
            }

            // get other parent informations
            if (!parent[idx].empty()) {
                for (int i = 0; i < idx; i++) {
                    int half = parent[idx][i];
                    if ((int)parent[half].size() <= i)
                        break;

                    parent[idx].push_back(parent[half][i]);
                    wsum[idx].push_back(wsum[idx][i] + wsum[half][i]);
                }
            }
        } else {
            int R = p ^ last;
            R--;
            long long X = q ^ last;

            last = 0;
            if (X >= weights[R]) {
                last++;
                X -= weights[R];

                int cur = R;
                for (int i = parent[cur].size() - 1; i >= 0; i--) {
                    if (i < (int)parent[cur].size() && wsum[cur][i] <= X) {
                        last += 1 << i;
                        X -= wsum[cur][i];
                        cur = parent[cur][i];
                    }
                }
            }
            cout << last << '\n';
        }
    }
}