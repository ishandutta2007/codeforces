#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;
const llint INF = 1000000000000000000LL;

int n;
llint h[MAXN], b[MAXN], dp[MAXN], val[MAXN];
vector <int> v;
multiset <llint> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        val[i] = dp[v.back()];
        while (!v.empty() && h[v.back()] > h[i]) {
            int x = v.back();
            val[i] = max(val[i], val[x]);
            st.erase(st.find(val[x] + b[x]));
            v.pop_back();
        }
        st.insert(val[i] + b[i]);
        v.push_back(i);
        dp[i] = *st.rbegin();
    }
    cout << dp[n];
    return 0;
}