#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    void update(int idx, int value) {
        idx += n;
        data[idx] = value;

        while (idx > 1) {
            idx /= 2;
            data[idx] = std::max(data[2 * idx], data[2 * idx + 1]);
        }
    }

    int maximum(int left, int right) { // interval [left, right)
        int ret = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret = std::max(ret, data[left++]);
            if (right & 1) ret = std::max(ret, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<int> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += n - i;
    }

    auto v = a;
    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());

    const int INF = end - v.begin() + 1;
    SegmentTree left(INF);
    vector<int> l_ws, l_cnts;
    for (int i = 0; i < n; i++) {
        // delete i
        int l_w = 0;
        int l_cnt = 0;
        if (i) {
            l_w = lower_bound(v.begin(), end, a[i-1]) - v.begin();
            l_cnt = 1 + left.maximum(0, l_w + 1);
            left.update(l_w, l_cnt);
            l_w = a[i-1];
        }
        l_ws.push_back(l_w);
        l_cnts.push_back(l_cnt);
    }

    int best = 0;

    SegmentTree right(INF);
    for (int i = n-1; i >= 0; i--) {
        // delete i
        if (i == n-1) {
            best = max(best, l_cnts[i]);
        } else {
            int w = lower_bound(v.begin(), end, l_ws[i] - 1) - v.begin();
            int x = right.maximum(w, INF);
            best = max(best, l_cnts[i] + x);
        }
        int w = lower_bound(v.begin(), end, a[i]) - v.begin();
        right.update(w, right.maximum(w, INF) + 1);
    }

    cout << n - (1 + best) << endl;
}