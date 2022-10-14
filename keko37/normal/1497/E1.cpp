#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MAXVAL = 10000005;

int t, n, k;
int a[MAXN], pos[MAXVAL];
int dp[MAXN][21];
vector <int> v;
set <int> st;

void precompute () {
    bool p[10005];
    for (int i = 2; i < 1e4; i++) {
        if (p[i]) continue;
        for (int j = i * i; j < 1e4; j += i) {
            p[j] = 1;
        }
    }
    for (int i = 2; i < 1e4; i++) {
        if (p[i] == 0) v.push_back(i);
    }
}

int normalize (int x) {
    int res = 1;
    for (auto p : v) {
        int cnt = 0;
        while (x % p == 0) x /= p, cnt++;
        if (cnt & 1) res *= p;
    }
    res *= x;
    return res;
}

void calc () {
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    st.clear();
    st.insert(0);
    vector <int> tmp;
    for (int i = 1; i <= n; i++) {
        if (pos[a[i]] > 0) st.insert(pos[a[i]]);
        pos[a[i]] = i;
        tmp.clear();
        auto it = st.rbegin();
        for (int j = 0; j <= k; j++) {
            tmp.push_back(*it);
            it++;
            if (it == st.rend()) break;
        }
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 1e9;
            int lim = min(j + 1, (int)tmp.size());
            for (int h = 0; h < lim; h++) {
                dp[i][j] = min(dp[i][j], 1 + dp[tmp[h]][j - h]);
            }
        }
    }
    for (int i = 1; i <= n; i++) pos[a[i]] = 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = normalize(a[i]);
        }
        calc();
        cout << dp[n][k] << '\n';
    }
    return 0;
}