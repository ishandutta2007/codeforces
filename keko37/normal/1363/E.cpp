#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n;
llint a[MAXN], b[MAXN], c[MAXN];
vector <int> v[MAXN];

pair <llint, int> dfs (int x, int rod, llint cost) {
    cost = min(cost, a[x]);
    int dif = 0, cnt = 0;
    llint res = 0;
    if (b[x] == 0 && c[x] == 1) dif++, cnt++;
    if (b[x] == 1 && c[x] == 0) dif--, cnt++;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        pair <llint, int> tr = dfs(sus, x, cost);
        dif += tr.second;
        cnt += abs(tr.second);
        res += tr.first;
    }
    return {res + (cnt - abs(dif)) * cost, dif};
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    pair <llint, int> res = dfs(1, 0, 1e9);
    if (res.second == 0) cout << res.first; else cout << -1;
    return 0;
}