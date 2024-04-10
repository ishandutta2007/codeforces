#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> e[200005];
int n, m;
int a[200005];
int z[200005];

ll sol;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    copy(a+1, a+n+1, z);
    sort(z, z+n);

    for (int i=1; i<=n; i++) {
        int sol = lower_bound(z, z+n, a[i]) - z;
        for (int y : e[i]) {
            if (a[y] < a[i])
                sol--;
        }
        cout << sol << ' ';
    }
}