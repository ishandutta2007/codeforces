#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

llint t, n, q, sol;
llint a[MAXN];
set <llint> st;

void ubaci (int val) {
    if (st.find(val) != st.end()) return;
    st.insert(val);
    sol += val;
}

void izbaci (int val) {
    if (st.find(val) == st.end()) return;
    st.erase(st.find(val));
    sol -= val;
}

void refresh (int pos, int sign) {
    if (a[pos] > a[pos - 1] && a[pos] > a[pos + 1]) {
        if (sign == 1) ubaci(a[pos]); else izbaci(a[pos]);
    } else if (a[pos] < a[pos - 1] && a[pos] < a[pos + 1]) {
        if (sign == 1) ubaci(-a[pos]); else izbaci(-a[pos]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = a[n + 1] = 0;
        sol = 0;
        st.clear();
        for (int i = 1; i <= n; i++) {
            refresh(i, 1);
        }
        cout << sol << '\n';
        for (int i = 0; i < q; i++) {
            int lef, rig;
            cin >> lef >> rig;
            if (lef != rig) {
                for (int j = -1; j <= 1; j++) {
                    if (lef + j >= 1 && lef + j <= n) refresh(lef + j, -1);
                }
                for (int j = -1; j <= 1; j++) {
                    if (rig + j >= 1 && rig + j <= n) refresh(rig + j, -1);
                }
                swap(a[lef], a[rig]);
                for (int j = -1; j <= 1; j++) {
                    if (lef + j >= 1 && lef + j <= n) refresh(lef + j, 1);
                }
                for (int j = -1; j <= 1; j++) {
                    if (rig + j >= 1 && rig + j <= n) refresh(rig + j, 1);
                }
            }
            cout << sol << '\n';
        }
    }
    return 0;
}