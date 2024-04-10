#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,a[210000],b[210000],fa[210000];
ll s[210000]; bool vis[210000];
vector<int> vec[210000];
int findset(int x) {
    if (x != fa[x]) fa[x] = findset(fa[x]);
    return fa[x];
}
void solve(int i) {
    if (vis[i]) return;
    s[i] = 0;
    fa[i] = i + 1;
    vis[i] = true;
    for (int j: vec[i])
        if (!s[j])
            for (int x = findset(min(i, j)); x <= max(i, j); x = findset(x)) solve(x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - b[i];
        int l, r;
        for (int i = 1; i <= m; i++) {
            cin >> l >> r;
            vec[l - 1].push_back(r);
            vec[r].push_back(l - 1);
        }
        for (int i = 0; i <= n + 1; i++) vis[i] = false, fa[i] = i;
        for (int i = 0; i <= n; i++)
            if (!s[i]) solve(i);
        bool ans = true;
        for (int i = 1; i <= n; i++) ans = ans && (!s[i]);
        if (ans) cout << "YES\n"; else cout << "NO\n";
        for (int i = 0; i <= n; i++) vec[i].clear();
    }
    return 0;
}