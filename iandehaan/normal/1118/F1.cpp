#include <iostream>
#include <unordered_set>
using namespace std;
int n;
int a[300001];
unordered_set<int> conn[300001];
pair<int, int> seen[300001];
int blue[300001];
int red[300001];
int parent[300001];
int sumred = 0;
int sumblue = 0;

pair<int, int> dfs(int start) {
    //cout << "dfs on " << start << endl;
    if (seen[start].first != -1 && seen[start].second != -1) {
        return make_pair(0, 0);
    }
    seen[start].first = 0;
    seen[start].second = 0;
    int blue = 0;
    int red = 0;
    for (int nxt : conn[start]) {
        if (seen[nxt].first != -1 || seen[nxt].second != -1) continue;
        parent[nxt] = start;
        pair<int, int> out = dfs(nxt);
        blue += out.first;
        red += out.second;
    }
    if (a[start] == 1) red++;
    if (a[start] == 2) blue++;
    seen[start].first = blue;
    seen[start].second = red;
    return seen[start];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            sumred++;
        }
        if (a[i] == 2) {
            sumblue++;
        }
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        conn[u].insert(v);
        conn[v].insert(u);
    }
    for (int i = 0; i < n; i++) {
        seen[i] = make_pair(-1, -1);
        parent[i] = -1;
    }
    dfs(0);
    int out = 0;
    for (int i = 0; i < n; i++) {
        for (int nxt : conn[i]) {
            // consider edge from i to nxt
            int par = i;
            int child = nxt;
            if (parent[par] == child) {
                continue;
            }

            //cout << "edge from " << par+1 << " to " << child+1 << endl;

            if ((seen[child].first == sumblue && seen[child].second == 0) || (seen[child].second == sumred && seen[child].first == 0)) {
                out++;
            }
        }
    }
    cout << out << endl;
}