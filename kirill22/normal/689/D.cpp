#include<bits/stdc++.h>

using namespace std;

#define int long long

template<typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public :
    int n;
    vector<vector<T>> st;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = (int) a.size();
        int maxlg = 32 - __builtin_clz(n);
        st.resize(maxlg);
        st[0] = a;
        for (int i = 1; i < maxlg; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get(int l, int r) const {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 32 - __builtin_clz(r - l + 1) - 1;
        return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    SparseTable<int> A(a, [&] (int x, int y) {return max(x, y);});
    SparseTable<int> B(b, [&] (int x, int y) {return min(x, y);});
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int L = -1, R = -1;
        {
            int l = -1, r = i + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (A.get(m, i) < B.get(m, i)) r = m;
                else l = m;
            }
            R = r;
        }
        {
            int l = -1, r = i + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                int res = A.get(m, i);
                int res2 = B.get(m, i);
                if (A.get(m, i) > B.get(m, i)) l = m;
                else r = m;
            }
            L = l;
        }
        //cout << L << " " << R << endl;
        ans += R - L - 1;
    }
    cout << ans;
}