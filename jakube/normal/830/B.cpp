#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> data;
    int n;

    SegmentTree(int n) {
        this->n = n;
        data.assign(2*n, 0);
    }

    void update(int idx, int val) {
        idx += n;
        data[idx] = val;

        while (idx > 1) {
            idx >>= 1;
            data[idx] = data[idx<<1] + data[idx<<1|1];
        }
    }

    int range(int left, int right) {
        left += n;
        right += n;

        int result = 0;
        while (left < right) {
            if (left & 1) result += data[left++];
            if (right & 1) result += data[--right];
            left >>= 1;
            right >>= 1;
        }
        return result;
    }  
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        st.update(i, 1);
    }

    map<int, vector<int>> indices;
    for (int i = 0; i < n; i++) {
        indices[v[i]].push_back(i);
    }

    auto ordered = v;
    sort(ordered.begin(), ordered.end());
    
    int cur = -1;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int val = ordered[i];
        auto& ind = indices[val];
        auto it = upper_bound(ind.begin(), ind.end(), cur);
        if (it == ind.end()) {
            res += st.range(cur, n);
            cur = 0;
            it = ind.begin();
        }
        int idx = *it;
        if (cur == -1)
            cur = 0;
        res += st.range(cur, idx+1);
        st.update(idx, 0);

        cur = idx;
    }

    cout << res << endl;
}