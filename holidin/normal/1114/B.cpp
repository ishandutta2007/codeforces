#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 3e5 + 1;

vector <pair<int, int> > v;
int a[N], c[N];

int main() {
    int i, j, n, m, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    long long ans = 0;
    sort(v.begin(), v.end());
    for (i = n - m * k; i < v.size(); ++i) {
        c[v[i].se] = 1;
        ans += v[i].fi;
    }
    cout << ans << "\n";
    int cnt = 0, tp = 1;
    for (i = 1; i <= n; ++i) {
        cnt += c[i];
        if (cnt == m) {
            ++tp;
            cnt = 0;
            if (tp <= k)
                cout << i << ' ';
        }
    }
}