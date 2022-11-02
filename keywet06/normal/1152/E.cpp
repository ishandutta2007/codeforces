#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
multiset<int> to[N];
int len[N];
int road[N], k;
void dfs(int x) {
    for (auto a = to[x].begin(); a != to[x].end(); a = to[x].begin()) {
        int u = *a;
        to[x].erase(a);
        to[u].erase(to[u].find(x));
        dfs(u);
    }
    road[k++] = x;
}
int n;
int x[N], y[N];
bool flag;
map<int, int> m;
int p[2 * N];
int cnt;
int main() {
    int a, b;
    flag = true;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) cin >> x[i];
    for (int i = 1; i < n; i++) cin >> y[i];
    for (int i = 1; i < n; i++) {
        if (m.count(x[i]) == 0) {
            p[cnt] = x[i];
            m[x[i]] = cnt++;
        }
        if (m.count(y[i]) == 0) {
            p[cnt] = y[i];
            m[y[i]] = cnt++;
        }
        a = m[x[i]];
        b = m[y[i]];
        if (x[i] > y[i]) flag = false;
        len[a]++, len[b]++;
        to[a].insert(b);
        to[b].insert(a);
    }
    int s = -1, e = -1;
    if (!flag) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < cnt; i++)
        if (len[i] % 2 == 1) {
            if (s == -1)
                s = i;
            else if (e == -1)
                e = i;
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    if (s == -1) s = 0;
    dfs(s);
    if (k == n)
        for (k = k - 1; k >= 0; k--) printf("%d ", p[road[k]]);
    else
        cout << -1 << endl;
    return 0;
}