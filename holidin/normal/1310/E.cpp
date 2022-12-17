#include <bits/stdc++.h>
#pragma GCC optimize 03
//#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 22;
const int mod = 998244353;
int a[N], t[N];
vector <pair<int, int> > v;
int dp[N][N];
vector <int> m[200][N];

void write(vector <int> &v) {
    for (auto u : v)
        cout << u <<  ' ';
    cout << endl;
}


vector <int> fmin(vector <int> &was) {
    //sort(was.begin(), was.end());
    vector <int> ans;
    int num = 1;
    for (int i = was.size() - 1; i >= 0; --i) {
        for (int j = 0; j < was[i]; ++j)
            ans.push_back(num);
        ++num;
    }
    return ans;
}

bool good(vector <int> v, int n, int k) {
    for (int i = 2; i < k; ++i) {
        v = fmin(v);
        int cnt = 0;
        for (auto u: v)
            cnt += u;
        if (cnt > n)
            return false;
    }
    int num = 1, sum = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        sum += num * v[i];
        ++num;
    }
    if (sum > n)
        return false;
    return true;
}

int cn = 0;

int f(int len, int mink, int maxsum) {
    if (len * (len + 1) * mink / 2 > maxsum)
        return 0;
    if (len == 0)
        return 1;
    if (mink >= m[len][maxsum].size()) {
        for (int i = 0; mink >= m[len][maxsum].size(); ++i)
            m[len][maxsum].push_back(-1);
    }
    if (m[len][maxsum][mink] == -1) {
            ++cn;
        int ans = (f(len, mink + 1, maxsum) + f(len - 1, mink, maxsum - len * mink)) % mod;
        m[len][maxsum][mink] = ans;
    }
    return m[len][maxsum][mink];
}


void calc(int n) {

    int i, j;
    /*
    for (i = 0; i < n; ++i) {
        c[0][i] = 0;
        c[i][0] = 1;
    }
    for (i = 1; i < n; ++i)
    for (j = 1; j < n; ++j)
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];*/
    for (i = 0; i <= n; ++i)
        dp[0][i] = 1;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
        dp[i][j] = dp[i][j - 1];
        if (i >= j)
            dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
    }

}

int ans = 0;

void rec(vector <int> v, int n, int k) {
    int mn = 1;
    if (v.size() > 0)
        mn = v.back();
    v.push_back(0);
    for (int i = mn; i <= n; ++i) {
        v.back() = i;
        if (good(v, n, k))
            ++ans;
        else
            break;
        rec(v, n, k);
    }
    v.pop_back();
}

void solve() {
    int i, j, k, n;
    cin >> n >> k;
    if (k == 1) {
        calc(n);
        int ans = 0;
        for (i = 1; i <= n; ++i)
            ans = (ans + dp[i][i]) % mod;
        cout << ans % mod;
        return;
    }
    if (k == 2) {
        int ans = 0;
        cn = 0;
        for (i = 1; i * (i + 1) / 2 <= n; ++i)
            ans = (ans + f(i, 1, n)) % mod;
        cout << ans % mod;
        return;
    }
    {
        vector <int> v;
        rec(v, n, k);
        cout << ans;
    }

}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}