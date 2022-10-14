#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;
const int LIM = 1000005;

int t, n;
int a[MAXN];
multiset <int> st;
vector <pi> v;

bool probaj (int x, int y) {
    st.clear();
    v.clear();
    for (int i = 0; i < n; i++) st.insert(a[i]);
    v.push_back({x, y});
    st.erase(st.find(x));
    st.erase(st.find(y));
    for (int i = 0; i < n/2 - 1; i++) {
        auto it = st.end(); it--;
        int mx = *it;
        st.erase(it);
        if (mx >= x) return 0;
        it = st.find(x - mx);
        if (it != st.end()) {
            v.push_back({mx, *it});
            st.erase(it);
            x = mx;
        } else {
            return 0;
        }
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        n *= 2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        bool ok = 0;
        for (int i = 0; i < n - 1; i++) {
            if (probaj(a[n - 1], a[i])) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            cout << v[0].first + v[0].second << '\n';
            for (auto pp : v) cout << pp.first << " " << pp.second << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}