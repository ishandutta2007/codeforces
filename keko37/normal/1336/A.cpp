#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, k, sol;
int dub[MAXN], siz[MAXN];
vector <int> v[MAXN], val;

void dfs (int x, int rod) {
    dub[x] = 1 + dub[rod];
    siz[x] = 1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
        siz[x] += siz[sus];
    }
    val.push_back(dub[x] - siz[x]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    sort(val.begin(), val.end());
    for (int i = 0; i < k; i++) sol += val[n - 1 - i];
    cout << sol;
    return 0;
}