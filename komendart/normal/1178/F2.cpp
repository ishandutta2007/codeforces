#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int mod = 998244353;
const int maxn = 505;
const int maxm = 1e6 + 100;

int c[maxn];
int dp[maxn][maxn];

void calc_dp(int left, int right) {
    int mid = min_element(c + left, c + right) - c;
    int L = 0;
    for (int i = left; i <= mid; ++i) {
        L += dp[left][i] * dp[i][mid];
        if (!(i & 3)) L %= mod;
    }
    int R = 0;
    for (int i = mid; i < right; ++i) {
        R += dp[mid + 1][i + 1] * dp[i + 1][right];
        if (!(i & 3)) R %= mod;
    }
    //cerr << L << ' ' << R << endl;
    dp[left][right] = L % mod * R % mod;
}

int solve_permutation(const vector<int> &p) {
    int n = sz(p);
    if (n <= 1) {
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        c[i] = p[i];
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            calc_dp(l, r);
        }
    }
    return dp[0][n];
}

vector<int> p[maxm];

void fail() {
    cout << 0 << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 2);
    a[0] = 0;
    vector<int> last(n + 1);
    last[0] = m + 1;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        last[a[i]] = i;
    }
    
    vector<int> st;
    st.push_back(0);
    for (int i = 1; i <= m; ++i) {
        if (a[i] < a[st.back()]) {
            fail();
        }
        if (a[i] > a[st.back()]) {
            p[st.back()].push_back(a[i]);
            //cerr << st.back() << ' ' << a[i] << endl;
            st.push_back(i);
        }
        if (a[i] == a[st.back()]) {
            st.pop_back();
            st.push_back(i);
        }
        if (st.back() == last[a[st.back()]]) {
            st.pop_back();
        }
    }
    int ans = 1;
    for (int i = 0; i <= m; ++i) {
        ans *= solve_permutation(p[i]);
        ans %= mod;
    }
    cout << ans << '\n';
}