#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

int n, m;
llint x[MAXN], y[MAXN], pref[MAXN], suf[MAXN], val[MAXN];
pair <int, int> p[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        p[i] = make_pair(x[i] - y[i], i);
    }
    sort(p, p+n);
    for (int i=0; i<n; i++) {
        int ind = p[i].second;
        if (i == 0) pref[i] = x[ind]; else pref[i] = x[ind] + pref[i-1];
    }
    for (int i=n-1; i>=0; i--) {
        int ind = p[i].second;
        if (i == n-1) suf[i] = y[ind]; else suf[i] = y[ind] + suf[i+1];
    }
    for (int i=0; i<n; i++) {
        int ind = p[i].second;
        if (i > 0) val[ind] += pref[i-1] + i * y[ind];
        if (i < n-1) val[ind] += (n - i - 1) * x[ind] + suf[i+1];
    }
    for (int i=0; i<m; i++) {
        llint a, b, res;
        cin >> a >> b;
        a--; b--;
        res = min(x[a] + y[b], x[b] + y[a]);
        val[a] -= res;
        val[b] -= res;
    }
    for (int i=0; i<n; i++) {
        cout << val[i] << " ";
    }
    return 0;
}