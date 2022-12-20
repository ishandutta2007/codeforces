#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

vector <int> f[N], v[N];
bool use[N];
int p[N], q[N], top = 0;

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> p[i];
    for (i = 1; i <= n; ++i)
    if (!use[i]) {
        ++top;
        v[top].push_back(i);
        j = i;
        use[i] = true;
        while (p[j] != i) {
            j = p[j];
            use[j] = true;
            v[top].push_back(j);
        }
        f[v[top].size()].push_back(top);
    }
    for (i = 1; i <= n; ++i)
    if (i % 2 == 0) {
        if (f[i].size() % 2 == 1) {
            cout << -1;
            return 0;
        }
        for (j = 0; j < f[i].size(); j += 2) {
            int w = f[i][j], u = f[i][j + 1];
            for (int l = 0; l < i; ++l) {
                q[v[u][l]] = v[w][l];
                q[v[w][l]] = v[u][(l + 1) % i];
            }
        }
    } else
        for (j = 0; j < f[i].size(); ++j) {
            int u = f[i][j];
            for (int l = 0; l < i; ++l) {
                q[v[u][l]] = v[u][(l + (i + 1) / 2) % i];
            }
        }
    for (i = 1; i <= n; ++i)
        cout << q[i] << ' ';
}