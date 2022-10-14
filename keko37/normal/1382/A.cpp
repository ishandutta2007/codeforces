#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, m;
set <int> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        st.clear();
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            st.insert(x);
        }
        int res = -1;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (st.count(x)) res = x;
        }
        if (res == -1) cout << "NO\n"; else cout << "YES\n1 " << res << '\n';
    }
    return 0;
}