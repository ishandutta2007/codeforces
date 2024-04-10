#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<long long> data;
    int n;

    SegmentTree(int n) {
        this->n = n;
        data.assign(2*n, 0);
    }

    long long range(int left, int right) {
        left += n;
        right += n;

        long long result = 0;
        while (left < right) {
            if (left & 1) result += data[left++];
            if (right & 1) result += data[--right];
            left >>= 1;
            right >>= 1;
        }

        return result;
    }

    void update(int idx, int val) {
        idx += n;
        data[idx] = val;

        while (idx > 1) {
            idx >>= 1;
            data[idx] = data[idx<<1] + data[idx<<1|1];
        }
    }

    void increase(int idx) {
        idx += n;
        data[idx]++;

        while (idx > 1) {
            idx >>= 1;
            data[idx]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;

    long long psum = 1;
    SegmentTree st(n);

    int last_idx = 0;
    k = min(k, n - k);
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        if (last_idx + k < n) {
            sum = st.range(last_idx + 1, last_idx+k);
        } else {
            sum = st.range(last_idx + 1, n) + st.range(0, (last_idx + k) % n);
        }
        sum++;
        psum += sum;
        cout << psum << " ";

        st.increase(last_idx);
        last_idx = (last_idx + k) % n;
        st.increase(last_idx);
    }

    cout << endl;
    return 0;
}