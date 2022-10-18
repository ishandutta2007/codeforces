#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
    int result = numeric_limits<int>::max();
};

class SegmentTreeMin {
    public:
        vector<int> data;
        int n;

        SegmentTreeMin(int n) : n(n) {
            data.assign(2*n, numeric_limits<int>::max());
        }

        void setMin(int l, int r, int val) {
            l += n;
            r += n;

            while (l < r) {
                if (l & 1) {
                    data[l] = min(data[l], val);
                    l++;
                }
                if (r & 1) {
                    r--;
                    data[r] = min(data[r], val);
                }
                l >>= 1;
                r >>= 1;
            }
        }

        int getMin(int idx) {
            idx += n;

            int result = data[idx];
            while (idx > 1) {
                idx >>= 1;
                result = min(result, data[idx]);
            }

            return result;
        }
};

class SegmentTree {
public:
    vector<int> data;
    int n;

    SegmentTree(int n) {
        this->n = n;
        data.assign(2*n, -1);
    }

    void update(int idx, int val) {
        idx += n;
        data[idx] = val;

        while (idx > 1) {
            idx >>= 1;
            data[idx] = max(data[idx<<1], data[idx<<1|1]);
        }
    }

    int range(int left, int right) {
        left += n;
        right += n;

        int result = -1;
        while (left < right) {
            if (left & 1) result = max(result, data[left++]);
            if (right & 1) result = max(result, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return result;
    }  
};

class SegmentTree2 {
public:
    vector<int> data;
    int n;

    SegmentTree2(int n) {
        this->n = n;
        data.assign(2*n, numeric_limits<int>::max());
    }

    void update(int idx, int val) {
        idx += n;
        data[idx] = val;

        while (idx > 1) {
            idx >>= 1;
            data[idx] = min(data[idx<<1], data[idx<<1|1]);
        }
    }

    int range(int left, int right) {
        left += n;
        right += n;

        int result = numeric_limits<int>::max();
        while (left < right) {
            if (left & 1) result = min(result, data[left++]);
            if (right & 1) result = min(result, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return result;
    }  
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = numeric_limits<int>::max();

    set<int> se(a.begin(), a.end());
    vector<int> sorted(se.begin(), se.end());
    vector<int> indices(n + 1);
    for (int i = 0; i < n + 1; i++) {
        indices[i] = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
    }

    int Q;
    cin >> Q;
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        Query& q = queries[i];
        cin >> q.l >> q.r;
        q.l--;
        q.r--;
        q.idx = i;
    }

    sort(queries.begin(), queries.end(), [](Query a, Query b){ return a.r < b.r; });
    
    int idx = 0;
    SegmentTreeMin st(n);
    SegmentTree s(n);
    for (int r = 0; r < n; r++) {
        int l = s.range(indices[r], n);
        while (l >= 0) {
            st.setMin(0, l+1, a[l] - a[r]);
            
            int next = lower_bound(sorted.begin(), sorted.end(), (a[l] + a[r] + 1) / 2) - sorted.begin();
            l = s.range(indices[r], next);
        }

        while (idx < Q && queries[idx].r == r) {
            queries[idx].result = min(queries[idx].result, st.getMin(queries[idx].l));
            idx++;
        }

        s.update(indices[r], r);
    }

    sort(queries.begin(), queries.end(), [](Query a, Query b){ return a.l < b.l; });

    st = {n};
    SegmentTree2 s2 = {n};
    idx = Q - 1;
    for (int l = n - 1; l >= 0; l--) {
        int r = s2.range(indices[l], n);
        while (r  < numeric_limits<int>::max()) {
            st.setMin(r, n, a[r] - a[l]);

            int next = lower_bound(sorted.begin(), sorted.end(), (a[l] + a[r] + 1) / 2) - sorted.begin();
            r = s2.range(indices[l], next);
        }

        while (idx >= 0 && queries[idx].l == l) {
            queries[idx].result = min(queries[idx].result, st.getMin(queries[idx].r));
            idx--;
        }

        s2.update(indices[l], l);
    }

    sort(queries.begin(), queries.end(), [](Query a, Query b){ return a.idx < b.idx; });
    for (Query q : queries)
        cout << q.result << '\n';
}