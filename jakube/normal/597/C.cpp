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

    void update(int idx, long long val) {
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

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<SegmentTree> dp(k+2, n+1);
    dp[0].update(0, 1);

    for (int i = 0; i < n; i++) {
        for (int K = k + 1; K > 0; K--) {
            dp[K].update(v[i], dp[K-1].range(0, v[i]));
        }
    }

    cout << dp[k+1].range(0, n+1) << endl;

    return 0;
}