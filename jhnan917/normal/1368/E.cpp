#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> E[200005];
vector<int> R[200005];
int D[200005];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            E[i].clear();
            R[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            E[x].push_back(y);
            R[y].push_back(x);
        }
        vector<int> S;
        for (int i = 1; i <= n; i++) {
            D[i] = R[i].size();
            if (D[i] == 0) S.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int x = S[i];
            for (int i : E[x]) {
                if (--D[i] == 0) {
                    S.push_back(i);
                }
            }
        }
        vector<int> ans;
        for (int x : S) {
            int pos[3] = { 1, 1, 1 };
            for (int i : R[x]) {
                if (D[i] == 0) continue;
                if (D[i] == 1) pos[1] = 0;
                if (D[i] == 2) pos[1] = 0, pos[2] = 0;
            }
            if (pos[1]) D[x] = 1;
            else if (pos[2]) D[x] = 2;
            else D[x] = 0, ans.push_back(x);
        }
        printf("%u\n", ans.size());
        for (int i : ans) printf("%d ", i);
        printf("\n");
    }
}