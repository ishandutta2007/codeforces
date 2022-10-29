#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n; i >= 1; i--) a[i] = a[i] - a[i - 1];
//        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//        cout << endl;
        set<int> st;
        for (int i = 1; i <= n; i++) st.insert(i);
        for (int i = 1; i <= n; i++) {
            auto it = st.lower_bound(-a[i]);
            ans[*it] = i;
            st.erase(it);
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    }
}