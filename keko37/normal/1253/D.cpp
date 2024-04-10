#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, m, cnt, sol;
int bio[MAXN];
vector <int> v[MAXN];

int dfs (int x) {
    if (bio[x]) return 0;
    int res = x;
    bio[x] = cnt;
    for (auto sus : v[x]) res = max(res, dfs(sus));
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int lim = 0;
    for (int i = 1; i <= n; i++) {
        if (bio[i]) continue;
        if (i <= lim) sol++;
        cnt++;
        int rig = dfs(i);
        lim = max(lim, rig);
    }
    cout << sol;
    return 0;
}