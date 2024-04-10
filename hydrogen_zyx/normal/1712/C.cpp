#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        stack<int> stk;
        int ans = 0;
        set<int> st;
        for (int i = 1; i <= n; i++) {
            if (st.count(a[i])) {
                a[i] = 0;
            }
            if (!stk.empty() && stk.top() > a[i]) {
                while (!stk.empty()) {
                    ans++;
                    st.insert(stk.top());
                    stk.pop();
                }
            }
            if (st.count(a[i])) {
                a[i] = 0;
            }
            if (a[i] && (stk.empty() || stk.top() != a[i])) stk.push(a[i]);
        }
        cout << ans << endl;
    }
}