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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, m;

llong solve() {
    cin >> n >> m;
    vector<int> st;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        st.push_back(a);
    }
    reverse(st.begin(), st.end());
    set<int> top;
    llong ans = m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        if (top.count(x)) {
            top.erase(x);
        }
        else {
            ans += 2 * top.size();
            while (st.back() != x) {
                top.insert(st.back());
                st.pop_back();
                ans += 2;
            }
            st.pop_back();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}