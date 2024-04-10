#include <bits/stdc++.h>
using namespace std;

struct Ring {
    int a, b, h;
};

class SegmentTree {
public:
    vector<long long> data;
    int n;

    SegmentTree(int n) {
        this->n = n;
        data.assign(2*n, 0);
    }

    void update(int idx, long long val) {
        idx += n;
        data[idx] = max(data[idx], val);

        while (idx > 1) {
            idx >>= 1;
            data[idx] = max(data[idx<<1], data[idx<<1|1]);
        }
    }

    long long range(int left, int right) {
        left += n;
        right += n;

        long long result = 0;
        while (left < right) {
            if (left & 1) result = max(result, data[left++]);
            if (right & 1) result = max(result, data[--right]);
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
    vector<Ring> rings(n);
    for (int i = 0; i < n; i++) {
        Ring& r = rings[i];
        cin >> r.a >> r.b >> r.h;
    }

    set<int> nums;
    for (auto r : rings) {
        nums.insert(r.a);
        nums.insert(r.b);
    }
    vector<int> sorted(nums.begin(), nums.end());
    for (auto& r : rings) {
        r.a = lower_bound(sorted.begin(), sorted.end(), r.a) - sorted.begin();
        r.b = lower_bound(sorted.begin(), sorted.end(), r.b) - sorted.begin();
    }

    sort(rings.begin(), rings.end(), [](Ring a, Ring b){ 
        if (a.b == b.b) return a.a > b.a;
        return a.b > b.b; 
    });

    SegmentTree st(sorted.size());
    
    for (auto r : rings) {
        long long tmp = st.range(0, r.b);
        tmp += r.h;
        st.update(r.a, tmp);
    }

    cout << st.range(0, sorted.size()) << endl;
}