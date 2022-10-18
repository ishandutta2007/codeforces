#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

struct Data {
    int value, cnt;
};

Data combine(Data a, Data b) {
    if (a.value == b.value)
        return {a.value, a.cnt + b.cnt};
    if (a.cnt < b.cnt)
        swap(a, b);
    return {a.value, a.cnt - b.cnt};
}

class SegmentTree {
public:
    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2*n);
        for (int i = 0; i < n; i++)
            data[n+i] = {values[i], 1};
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = combine(data[2 * idx], data[2 * idx + 1]);
    }

    Data query(int left, int right) { // interval [left, right)
        Data ret = {0, 0};
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret = combine(ret, data[left++]);
            if (right & 1) ret = combine(data[--right], ret);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<Data> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    map<int, vector<int>> occ;
    for (int i = 0; i < n; i++)
        occ[v[i]].push_back(i);
    SegmentTree st(v);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int c = st.query(l - 1, r).value;
        int bad = lower_bound(occ[c].begin(), occ[c].end(), r)
            - lower_bound(occ[c].begin(), occ[c].end(), l - 1);
        int good = r + 1 - l - bad;
        int sol = 1;
        bad = max(bad - (good + 1), 0);
        sol += bad;
        cout << sol << '\n';
    }
}