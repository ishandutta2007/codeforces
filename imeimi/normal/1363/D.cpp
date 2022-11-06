#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n, k, mx;
vector<int> S[1002];

int ask(vector<int> x) {
    cout << "? " << x.size();
    for (int i : x) cout << ' ' << i;
    cout << endl;
    int ret;
    cin >> ret;
    if (ret < 0) exit(0);
    return ret;
}

int get_max(int s, int e) {
    if (s == e) return s;
    int m = (s + e) / 2;
    if (mx < 0) {
        vector<int> R;
        for (int i = m + 1; i <= e; ++i) for (int j : S[i]) R.push_back(j);
        mx = ask(R);
    }
    vector<int> L;
    for (int i = s; i <= m; ++i) for (int j : S[i]) L.push_back(j);
    int l = ask(L);
    mx = max(mx, l);
    if (mx == l) return get_max(s, m);
    return get_max(m + 1, e);
}

int cnt[1001];
bool solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cnt[i] = 0;
    for (int i = 1; i <= k; ++i) {
        S[i].clear();
        int c;
        cin >> c;
        while (c--) {
            int x;
            cin >> x;
            S[i].push_back(x);
            cnt[x] = 1;
        }
    }
    S[k + 1].clear();
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) continue;
        S[k + 1].push_back(i);
    }
    vector<int> all;
    mx = -1;
    int rk = S[k + 1].empty() ? k : k + 1;
    if (rk == 1) {
        vector<int> V;
        for (int i = 2; i <= n; ++i) {
            V.push_back(i);
        }
        mx = max(ask({ 1 }), ask(V));
    }
    int mxp = get_max(1, rk);
    vector<int> V;
    for (int i = 1; i <= rk; ++i) {
        if (i == mxp) continue;
        for (int j : S[i]) V.push_back(j);
    }
    int mxs = ask(V);
    cout << '!';
    for (int i = 1; i <= k; ++i) {
        cout << ' ';
        if (i != mxp) cout << mx;
        else cout << mxs;
    }
    cout << endl;
    char str[1000];
    cin >> str;
    return str[0] == 'C';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) if (!solve()) break;
    return 0;
}