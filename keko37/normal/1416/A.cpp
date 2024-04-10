#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

int t, n;
int a[MAXN], sol[MAXN];
vector <int> v[MAXN], r;
vector <pi> e;

void upd (int val) {
    int mx = max(v[val][0] + 1, n - v[val].back());
    for (int i = 1; i < v[val].size(); i++) {
        mx = max(mx, v[val][i] - v[val][i - 1]);
    }
    e.push_back({mx, val});
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        r.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            v[a[i]].clear();
            r.push_back(a[i]);
        }
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());
        for (int i = 0; i < n; i++) {
            v[a[i]].push_back(i);
        }
        e.clear();
        for (auto val : r) {
            upd(val);
        }
        sort(e.begin(), e.end());
        for (int i = 0; i <= n; i++) {
            sol[i] = 1e9;
        }
        for (auto par : e) {
            int pos = par.first, val = par.second;
            sol[pos] = min(sol[pos], val);
        }
        for (int i = 1; i <= n; i++) {
            sol[i] = min(sol[i - 1], sol[i]);
            if (sol[i] == 1e9) cout << "-1 "; else cout << sol[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}