#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int n, k, root;
int deg[MAXN], val[MAXN], d[MAXN];
vector <int> v[MAXN], r[MAXN];

int dfs (int x, int rod) {
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x] [i];
        if (sus == rod) continue;
        val[x] += dfs(sus, x);
        r[x].push_back(d[sus]);
    }
    sort(r[x].begin(), r[x].end());
    for (int i=0; i<r[x].size(); i++) {
        if (i == r[x].size()-1 || r[x] [i]+1 + r[x] [i+1]+1 > k) {
            d[x] = r[x] [i] + 1;
            val[x] -= i;
            break;
        }
    }
    if (v[x].size() == 1) val[x] = 1;
    return val[x];
}

int main () {
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (int i=1; i<=n; i++) {
        if (deg[i] > 1) {
            root = i;
            break;
        }
    }
    cout << dfs(root, 0);
    return 0;
}