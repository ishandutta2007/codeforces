#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1;

int a[N];
vector <int> e1[N];
set <int> e[N];
bool b[N];
int l[N], x[N], y[N], s[4*N];

int main() {
    int i, j, n, m, k, h, top;
    vector <int> v;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        e[x[i]].insert(y[i]);
        e[y[i]].insert(x[i]);
        e1[y[i]].push_back(x[i]);
        e1[x[i]].push_back(y[i]);
    }
    for (i = 1; i <= n; ++i) {
        b[i] = true;
        s[i] = i;
    }
    top = n;
    int ans = n;
    h = 1;
    for (i = m; i > 0; --i) {
        if (i != m) {
            e[x[i]].erase(y[i]);
            e[y[i]].erase(x[i]);
            ++top;
            s[top] = x[i];
            ++top;
            s[top] = y[i];
        }
        while (h <= top) {
            if (e[s[h]].size() < k && b[s[h]]) {
                --ans;
                for (j = 0; j < e1[s[h]].size(); ++j) {
                    e[e1[s[h]][j]].erase(s[h]);
                    ++top;
                    s[top] = e1[s[h]][j];
                }
                b[s[h]] = false;
            }
            ++h;
        }
        l[i] = ans;
    }
    for (i = 1; i <= m; ++i)
        cout << l[i] << "\n";
}