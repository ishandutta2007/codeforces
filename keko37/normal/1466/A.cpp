#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 55;

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
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            for (int j = 0; j < i; j++) {
                st.insert(x[i] - x[j]);
            }
        }
        cout << st.size() << '\n';
    }
    return 0;
}