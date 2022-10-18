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

    void update(int idx, int val) {
        idx += n;
        data[idx] = val;

        while (idx > 1) {
            idx >>= 1;
            data[idx] = data[idx<<1] + data[idx<<1|1];
        }
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }

    double segment_cnt = (double)n * (n + 1) / 2;

    vector<int> inv_greater_before(n, 0);
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        inv_greater_before[i] = st.range(v[i], n);
        st.update(v[i], 1);
    }
    double all_inversions = accumulate(inv_greater_before.begin(), inv_greater_before.end(), 0LL);
    
    // now compute all segments
    vector<long long> s(n, 0);
    SegmentTree st2(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1)
            s[i] = s[i+1];
        s[i] += st2.range(0, v[i]);
        st2.update(v[i], n - i);
    }
    double all_segments = 0;
    for (int i = 0; i < n; i++)
        all_segments += s[i] / segment_cnt;

    double all_random_segments = 0;
    for (int length = 1; length <= n; length++) {
        all_random_segments += (double)length * (length - 1) / 4 * (n - length + 1) / segment_cnt;
    }

    cout << all_inversions + all_random_segments - all_segments << endl;

    return 0;
}