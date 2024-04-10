#include<bits/stdc++.h>

using namespace std;

template<typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public :
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = (int) a.size();
        int maxlg = 32 - __builtin_clz(n);
        mat.resize(maxlg);
        mat[0] = a;
        for (int j = 1; j < maxlg; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= (n - (1 << j)); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int l, int r) const {
        if (l > r) return 0;
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 32 - __builtin_clz(r - l + 1) - 1;
        return func(mat[lg][l], mat[lg][r - (1 << lg) + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), pref(n + 1, 0), l(n, -1), r(n, n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    stack<pair<int, int>> stl, str;
    stl.push({1e9, -1});
    str.push({1e9, n});
    for (int i = 0; i < n; i++) {
        while (stl.top().first <= a[i]) stl.pop();
        while (str.top().first <= a[n - i - 1]) str.pop();
        l[i] = stl.top().second;
        r[n - i - 1] = str.top().second;
        stl.push({a[i], i});
        str.push({a[n - i - 1], n - i - 1});
    }
    SparseTable<int> MIN(pref, [&](int i, int j) { return min(i, j); });
    SparseTable<int> MAX(pref, [&](int i, int j) { return max(i, j); });
    for (int i = 0, res; i < n; i++, res = 0) {
        if (l[i] + 1 != i) res += max(0, pref[i] - MIN.get(l[i] + 1, i));
        if (r[i] - 1 != i) res += max(0, MAX.get(i + 2, r[i]) - pref[i + 1]);
        ans = max(ans, res);
    }
    cout << ans;
}