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

    void increase(int idx, int val) {
        idx += n;
        data[idx] += val;

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
    
    SegmentTree st(3*n+1);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int diff = v[i] - (i + 1);
        sum += abs(diff);
        st.increase(diff + n, 1);
    }

    int best = 0;
    long long min_sum = sum;

    for (int i = 1; i < n; i++) {
        sum -= abs(v[n-i] - n);

        int diff_to_remove = v[n-i] - (n - i + 1);
        st.increase(diff_to_remove + n, -1);

        int lower = st.range(i + n, 2*n+1 + n);
        int other = n - 1 - lower;

        sum -= lower;
        sum += other;

        int new_diff = v[n-i] - 1 + i;
        st.increase(new_diff + n, 1);

        sum += abs(v[n-i] - 1);

        if (sum < min_sum) {
            min_sum = sum;
            best = i;
        }
    }

    cout << min_sum << ' ' << best << '\n';
}