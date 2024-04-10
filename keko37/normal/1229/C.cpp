#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, m, q, sol;
llint hi[MAXN], lo[MAXN], val[MAXN];
vector <int> v[MAXN], r[MAXN];

void update (int x) {
    while (!v[x].empty()) {
        int sus = v[x].back();
        v[x].pop_back();
        if (val[sus] < val[x]) continue;
        sol -= lo[x] * hi[x];
        sol -= lo[sus] * hi[sus];
        v[sus].push_back(x);
        lo[x]++; hi[x]--;
        lo[sus]--; hi[sus]++;
        sol += lo[x] * hi[x];
        sol += lo[sus] * hi[sus];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        v[a].push_back(b);
        r[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        hi[i] = v[i].size();
        lo[i] = r[i].size();
        val[i] = i;
        sol += lo[i] * hi[i];
    }
    cout << sol << endl;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        update(x);
        val[x] = n + i;
        cout << sol << '\n';
    }
    return 0;
}