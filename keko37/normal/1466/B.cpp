#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int x[MAXN];
set <int> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        st.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (i != 1 && x[i - 1] >= x[i]) x[i]++;
            st.insert(x[i]);
        }
        cout << st.size() << '\n';
    }
    return 0;
}