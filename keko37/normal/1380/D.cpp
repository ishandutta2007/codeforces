#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, m, x, k, y, sol, moze = 1;
llint a[MAXN], b[MAXN];
vector <int> v;

void solve (int lo, int hi) {
    llint lim = max(a[lo], a[hi]);
    lo++; hi--;
    if (lo > hi) return;
    llint len = hi - lo + 1;
    llint mx = 0;
    for (int i = lo; i <= hi; i++) mx = max(mx, a[i]);
    if (mx <= lim) {
        llint cost = min(x, k * y);
        sol += len / k * cost + len % k * y;
    } else {
        if (len < k) {
            moze = 0;
            return;
        }
        if (x > k * y) {
            sol += (len - k) * y + x;
        } else {
            sol += len / k * x + len % k * y;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x >> k >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    v.push_back(0);
    int curr = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[curr]) {
            v.push_back(i);
            curr++;
        }
    }
    if (curr <= m) {
        cout << -1;
        return 0;
    }
    v.push_back(n + 1);
    for (int i = 1; i < v.size(); i++) {
        solve(v[i - 1], v[i]);
    }
    if (moze) cout << sol; else cout << -1;
    return 0;
}