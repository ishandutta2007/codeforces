#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 100005;

llint t, n, m, sum;
pi p[MAXN];
multiset <llint> st;

void ubaci (llint val) {
    st.insert(val);
    sum += val;
    if (st.size() > n-1) {
        sum -= *st.begin();
        st.erase(st.begin());
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        sum = 0; st.clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> p[i].second >> p[i].first;
        }
        sort(p, p + m);
        llint sol = 0;
        for (int i = 0; i < m; i++) {
            while (!st.empty() && *st.begin() < p[i].first) {
                sum -= *st.begin();
                st.erase(st.begin());
            }
            llint res = p[i].second + sum + (n-1 - st.size()) * p[i].first;
            sol = max(sol, res);
            ubaci(p[i].second);
        }
        cout << sol << '\n';
    }
    return 0;
}