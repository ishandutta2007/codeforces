/*
>k,ceil(k/2)
*/
#include <bits/stdc++.h>
using namespace std;
#define N 200005

int n, m, k, pre[N], vis[N];
vector<int> G[N], cir;

void reverse(vector<int>& v) {
    int i = 0, j = v.size() - 1;
    while (i < j) swap(v[i], v[j]), ++i, --j;
}

void bfs() {
    for (int i = 1; i <= n; i++) vis[i] = -1;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    pre[1] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u])
            if (v != pre[u]) {
                if (vis[v] == -1) {
                    vis[v] = vis[u] ^ 1;
                    q.push(v);
                    pre[v] = u;
                } else {  //
                    vector<int> v1, v2;
                    int t = v;
                    v1.push_back(t);
                    while (pre[t] != t) v1.push_back(pre[t]), t = pre[t];
                    t = u;
                    v2.push_back(t);
                    while (pre[t] != t) v2.push_back(pre[t]), t = pre[t];

                    reverse(v1);
                    reverse(v2);

                    // for(auto x:v2)cout<<x<<" ";

                    int i;
                    vector<int> s;
                    for (i = 0; i < v1.size() && i < v2.size(); i++)
                        if (v1[i] != v2[i]) break;
                    i--;
                    for (int j = i; j < v1.size(); j++) s.push_back(v1[j]);
                    for (int j = v2.size() - 1; j > i; j--) s.push_back(v2[j]);
                    if (s.size() <= k) {  //<=k
                        cout << 2 << '\n' << s.size() << '\n';
                        for (auto x : s) cout << x << ' ';
                        return;
                    }

                    vector<int> s1, s0;  //
                    for (auto x : s) {
                        if (vis[x] == 0)
                            s0.push_back(x);
                        else
                            s1.push_back(x);
                    }
                    if (s1.size() > s0.size()) swap(s1, s0);
                    cout << 1 << "\n";
                    for (int i = 0; i < ceil(1.0 * k / 2); i++)
                        cout << s1[i] << " ";
                    return;
                }
            }
    }
    //
    vector<int> s1, s0;
    for (int x = 1; x <= n; x++) {
        if (vis[x] == 0)
            s0.push_back(x);
        else
            s1.push_back(x);
    }
    if (s1.size() < s0.size()) swap(s1, s0);
    cout << 1 << "\n";
    for (int i = 0; i < ceil(1.0 * k / 2); i++) cout << s1[i] << " ";
    return;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs();
}