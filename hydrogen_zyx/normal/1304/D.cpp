#include <bits/stdc++.h>
using namespace std;
char c[300000];
vector<int> g[300000];
vector<int> ggg[300000];
int a[300000];
int b[300000];
int vis[300000];
int vvv[300000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> c + 1;
        for (int i = 1; i <= n; i++)
            vis[i] = 0, g[i].clear(), vvv[i] = 0, ggg[i].clear();
        for (int i = 1; i < n; i++) {
            if (c[i] == '>')
                g[i + 1].push_back(i), vis[i]++, ggg[i].push_back(i + 1),
                    vvv[i + 1]++;
            else
                g[i].push_back(i + 1), vis[i + 1]++, ggg[i + 1].push_back(i),
                    vvv[i]++;
        }
        priority_queue<int, vector<int>, greater<int> > que;
        priority_queue<int, vector<int>, greater<int> > qqq;
        for (int i = 1; i <= n; i++) {
            if (!vvv[i]) qqq.push(i);
        }
        int ttt = n;
        while (!qqq.empty()) {
            int k = qqq.top();
            qqq.pop();
            b[k] = ttt--;
            for (auto x : ggg[k]) {
                if (vvv[x]) {
                    vvv[x]--;
                    if (!vvv[x]) qqq.push(x);
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << endl;
        for (int i = 1; i <= n; i++)
            if (!vis[i]) que.push(i);
        int tot = 0;
        while (!que.empty()) {
            int k = que.top();
            que.pop();
            a[k] = ++tot;
            for (auto x : g[k]) {
                if (vis[x]) {
                    vis[x]--;
                    if (!vis[x]) que.push(x);
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}