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
        data[idx] = std::max(data[idx], value);

        while (idx > 1) {
            idx /= 2;
            data[idx] = std::max(data[2 * idx], data[2 * idx + 1]);
        }
    }

    int max(int left, int right) { // interval [left, right)
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

    int n, m;
    cin >> n >> m;
    vector<int> arr(m, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        arr[l-1]++;
        if (r < m)
            arr[r]--;
    }
    for (int i = 1; i < m; i++) {
        arr[i] += arr[i-1];
    }
    
    vector<int> dp_left(m, 0), dp_right(m, 0);
    SegmentTree st_left(n+m+1), st_right(n+m+1);
    for (int i = 0; i < m; i++) {
        dp_left[i] = st_left.max(0, arr[i] + 1);
        st_left.update(arr[i], dp_left[i] + 1);
    }
    for (int i = m-1; i >= 0; i--) {
        dp_right[i] = st_right.max(0, arr[i] + 1);
        st_right.update(arr[i], dp_right[i] + 1);
    }

    int mm = 0;
    for (int i = 0; i < m; i++) {
        mm = max(dp_left[i] + dp_right[i] + 1, mm);
    }
    cout << mm << endl;
}