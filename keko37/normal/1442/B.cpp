#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MOD = 998244353;

int t, n, k;
int a[MAXN], b[MAXN], pos[MAXN], ok[MAXN];
set <int> st;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int upd (int ind) {
    auto it = st.find(ind);
    int br = 0;
    if (it != st.begin()) {
        it--;
        if (ok[a[*it]] == 0) br++;
        it++;
    }
    it++;
    if (it != st.end()) {
        if (ok[a[*it]] == 0) br++;
    }
    it--;
    st.erase(it);
    ok[a[ind]] = 0;
    return br;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        st.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
            ok[i] = 0;
            st.insert(i);
        }
        for (int i = 1; i <= k; i++) {
            cin >> b[i];
            ok[b[i]] = 1;
        }
        int sol = 1;
        for (int i = 1; i <= k; i++) {
            sol = mul(sol, upd(pos[b[i]]));
        }
        cout << sol << '\n';
    }
    return 0;
}