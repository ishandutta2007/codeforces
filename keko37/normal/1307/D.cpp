#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, k, sol;
int a[MAXN], dist[MAXN][2], bio[MAXN];
pi p[MAXN];
vector <int> v[MAXN];
queue <int> q;
set <int> st;

void bfs (bool s) {
    memset(bio, 0, sizeof bio);
    int from = (s == 0 ? 1 : n);
    q.push(from);
    bio[from] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto sus : v[x]) {
            if (bio[sus] == 0) {
                bio[sus] = 1;
                q.push(sus);
                dist[sus][s] = dist[x][s] + 1;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(0); bfs(1);
    for (int i = 0; i < k; i++) {
        p[i] = {dist[a[i]][0] - dist[a[i]][1], a[i]};
    }
    sort(p, p + k);
    for (int i = k-1; i >= 0; i--) {
        int x = p[i].second;
        if (!st.empty()) sol = max(sol, p[i].first + 1 + dist[x][1] + *st.rbegin());
        st.insert(dist[x][1]);
    }
    cout << min(sol, dist[n][0]);
    return 0;
}