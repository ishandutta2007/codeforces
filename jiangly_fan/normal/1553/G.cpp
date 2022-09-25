#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000001;
int mp[maxn + 1], np[maxn + 1], a[maxn + 1];
int pr[maxn + maxn + 2];
vector<int> v[maxn + 1];
set<int> ok[maxn + maxn + 2];
int gp(int u) {
    return pr[u] == u ? u : pr[u] = gp(pr[u]);
}
void mer(int x, int y) {
    x = gp(x);
    y = gp(y);
    pr[x] = y;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 2; i <= maxn + n; i += 1) pr[i] = i;
    for (int i = 2; i <= maxn; i += 1) {
        if (not np[i]) {
            for (int j = i; j <= maxn; j += i) {
                np[j] = 1;
                if (mp[j]) mer(i, maxn + mp[j]);
                v[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i += 1) {
        if (mp[a[i] + 1]) {
            int s = gp(maxn + i), t = gp(maxn + mp[a[i] + 1]);
            ok[s].insert(t);
            ok[t].insert(s);
        }
        else {
            vector<int> w;
            w.push_back(gp(maxn + i));
            for (int j : v[a[i] + 1])
                w.push_back(gp(j));
            for (int x : w)
                for (int y : w)
                    ok[x].insert(y);
        }
    }
    for (int i = 1, s, t; i <= q; i += 1) {
        cin >> s >> t;
        s = gp(s + maxn);
        t = gp(t + maxn);
        if (s == t) cout << "0\n";
        else if (ok[s].count(t)) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}