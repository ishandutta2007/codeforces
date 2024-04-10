#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, n;
set <int> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        st.clear();
        st.insert(0);
        for (int i = 1; i * i <= n; i++) {
            st.insert(i);
            st.insert(n / i);
        }
        cout << st.size() << endl;
        for (auto x : st) cout << x << " "; cout << endl;
    }
    return 0;
}