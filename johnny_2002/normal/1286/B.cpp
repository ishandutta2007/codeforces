#include <bits/stdc++.h>

using namespace std;


const int N = 2e3 + 10;
int n;
int pa[N], c[N];
int per[N];
vector<int> adj[N];
int ans[N];

void BFS(int st) {
    per[1] = st;
    for(int i = 1, j = 1; i <= n; i++) {
        int u = per[i];
        for(auto v : adj[u]) {
            per[++j] = v;
        }
    }
}
void fail() {
    cout << "NO";
    exit(0);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> pa[i] >> c[i];
        adj[pa[i]].push_back(i);
    }
    BFS(adj[0][0]);


    for(int i = 1; i <= n; i++) {
        for(int pos = 1; pos <= n + 1; pos++) {
            if (pos == n + 1) {
                fail();
            }
            int u = per[pos];
            if (c[u] == 0) {
                ans[u] = i;
                while (u) {
                    c[u]--;
                    u = pa[u];
                }
                break;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}