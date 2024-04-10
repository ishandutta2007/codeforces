#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;

vector<int> g[N];
int pre[N];
int vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    queue<pair<int, int> > q;
    int cnt = 0;
    for (auto x: g[s]) {
        q.push({x, ++cnt});
        pre[x] = s;
        vis[x] = cnt;
    }

    while (!q.empty()) {
        int u = q.front().first;
        int id = q.front().second;
        q.pop();
        for (int v: g[u]) {
            if (v == s) continue;
            if (!vis[v]) {
                pre[v] = u;
                vis[v] = id;
                q.push({v, id});
            } else if (vis[v] != id) {
                cout<<"Possible"<<endl;
                vector<int> ans;
                int now = v;
                while (now != s) {
                    ans.push_back(now);
                    now = pre[now];
                }
                ans.push_back(s);
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                for (auto x: ans) cout << x << " ";
                cout << endl;

                ans.clear();
                ans.push_back(v);
                now = u;
                while (now != s) {
                    ans.push_back(now);
                    now = pre[now];
                }
                ans.push_back(s);
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                for (auto x: ans) cout << x << " ";
                cout << endl;
                return 0;
            }
        }
    }
    cout << "Impossible" << endl;
}