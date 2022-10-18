#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> data;

    SegmentTree(int n) : n(n) {
        data.assign(n*2, 0);
    }

    void update(int idx) {
        idx += n;
        data[idx] = 1;

        while (idx > 0) {
            idx >>= 1;
            data[idx] = data[idx<<1] + data[idx<<1|1];
        }
    }

    int range(int left, int right) {
        left += n;
        right += n;

        int total = 0;
        while (left < right) {
            if (left & 1) total += data[left++];
            if (right & 1) total += data[--right];
            left >>= 1;
            right >>= 1;
        }
        return total;
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
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());

    SegmentTree st1(n), st2(n);

    vector<long long> cnt(n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
        cnt[i] = st1.range(idx, n);
        st1.update(idx);
    }

    vector<long long> cnt2(n);
    for (int i = n-1; i >= 0; i--) {
        int idx = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
        cnt2[i] = st2.range(0, idx);
        st2.update(idx);
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += cnt[i] * cnt2[i];
    }

    cout << total << endl;


    return 0;
}