#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> data_left;
    vector<int> data_right;
    vector<int> values;
    int n;

    SegmentTree(int n) {
        this->n = n;
        data_left.assign(2*n, 0);
        data_right.assign(2*n, 0);
        values.assign(n, -2);
    }

    void update(int idx, int val) {
        if (val) {
            values[idx] = val;
            idx += n;
            data_right[idx] = 1;
        } else {
            idx += n;
            data_left[idx] = 1;
        }

        while (idx > 1) {
            idx >>= 1;
            data_left[idx] = data_left[idx<<1];
            data_right[idx] = data_right[idx<<1|1];
            if (data_right[idx<<1] < data_left[idx<<1|1]) {
                data_left[idx] += data_left[idx<<1|1] - data_right[idx<<1];
            } else {
                data_right[idx] += data_right[idx<<1] - data_left[idx<<1|1];
            }
        }
    }

    int search() {
        int idx = 1;
        
        if (data_right[1] == 0) {
            return -1;
        }

        int imbalance = 0;
        while (idx < n) {
            idx <<= 1;
            if (data_right[idx|1] > imbalance) {
                idx |= 1;
            } else {
                imbalance = imbalance + data_left[idx|1] - data_right[idx|1];
            }
        }
        
        return values[idx - n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int m;
    cin >> m;

    int size = 1;
    while (size < m) size <<= 1;
    SegmentTree st(size);

    for (int i = 0; i < m; i++)
    {
        int p, t;
        cin >> p >> t;
        p--;
        if (t == 1) {
            int val;
            cin >> val;
            st.update(p, val);
        } else {
            st.update(p, 0);
        }

        cout << st.search() << '\n';
    }

    return 0;
}