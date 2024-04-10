#include "bits/stdc++.h"
using namespace std;

pair<int, int> min(pair<int, int> a, pair<int, int> b) {
    return {min(a.first, b.first), min(a.second, b.second)};
}

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, {n, n});
        digits.assign(2*n, -1);
    }

    void update(int idx, int value) {
        idx += n;
        digits[idx] = value;
        data[idx] = {value == 0 ? idx-n : n, value == 1 ? idx-n : n};

        while (idx > 1) {
            idx /= 2;
            data[idx] = min(data[2 * idx], data[2 * idx + 1]);
        }
    }

    pair<int, int> next(int left, int right) { // interval [left, right)
        left += n;
        right += n;
        pair<int, int> ret{n, n};

        while (left < right) {
            if (left & 1) ret = min(ret, data[left++]);
            if (right & 1) ret = min(ret, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<pair<int, int>> data; // nearest 0 and 1
    std::vector<int> digits;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    string s2 = s;
    string t2 = t;
    sort(s2.begin(), s2.end());
    sort(t2.begin(), t2.end());
    if (s2 != t2) {
        cout << -1 << '\n';
        return 0;
    }

    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && t[i] == '0')
            st.update(i, 1);
        if (s[i] == '0' && t[i] == '1')
            st.update(i, 0);
    }

    int cnt = 0;
    while (true) {
        auto start = st.next(0, n);
        if (start == pair{n, n})
            break;
        int which;
        int cur;
        if (start.first < start.second) {
            cur = start.first;
            which = 0;
        } else {
            cur = start.second;

            which = 1;
        }

        vector<int> v;
        v.push_back(cur);
        while (true) {
            auto next = st.next(v.back() + 1, n);
            int next_idx;
            if (which == 0)
                next_idx = next.second;
            else
                next_idx = next.first;
            which ^= 1;
            if (next_idx == n)
                break;
            v.push_back(next_idx);
        }

        for (int i = 0; i + 1 < v.size(); i+=2) {
            st.update(v[i], -1);
            st.update(v[i+1], -1);
        }
        if (v.size() >= 2)
            cnt++;
    }
    cout << cnt << '\n';
}