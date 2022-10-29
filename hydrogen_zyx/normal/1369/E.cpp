#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[300000];
int w[300000];
int c[300000];
vector<int> v[300000];
vector<int> vv[300000];
vector<int> cnt;
stack<int> ans;
set<int> s;
void del(int k) {
    if (vis[k]) return;
    for (int i = 0; i < vv[k].size(); i++) {
        if (s.count(vv[k][i]) == 0) {
            s.insert(vv[k][i]);
            ans.push(vv[k][i]);
        }
    }
    vis[k] = 1;
    vector<int> point;
    for (int i = 0; i < v[k].size(); i++) {
        if (!vis[v[k][i]]) {
            w[v[k][i]]++;
            if (w[v[k][i]] >= 0) {
                point.push_back(v[k][i]);
            }
        }
    }
    for (int i = 0; i < point.size(); i++) {
        del(point[i]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        w[a]--;
        w[b]--;
        v[a].push_back(b);
        v[b].push_back(a);
        vv[a].push_back(i + 1);
        vv[b].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (w[i] >= 0) del(i);
    }
    for (int i = 1; i <= n; i++) {
        if (w[i] < 0) {
            cout << "DEAD";
            return 0;
        }
    }
    cout << "ALIVE" << endl;
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}