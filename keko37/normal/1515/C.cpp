#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, m, x;
int sol[MAXN];
set <pi> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        st.clear();
        for (int i = 1; i <= m; i++) {
            st.insert({0, i});
        }
        for (int i = 1; i <= n; i++) {
            int h; cin >> h;
            int val = st.begin() -> first;
            int ind = st.begin() -> second;
            sol[i] = ind;
            st.erase(st.begin());
            st.insert({val + h, ind});
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << sol[i] << " "; cout << '\n';
    }
    return 0;
}