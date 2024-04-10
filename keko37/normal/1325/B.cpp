#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
set <int> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        st.clear();
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            st.insert(x);
        }
        cout << st.size() << '\n';
    }
    return 0;
}