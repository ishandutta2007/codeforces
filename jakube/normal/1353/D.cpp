#include <bits/stdc++.h>
using namespace std;

struct ZeroSegment {
    int length, left_idx;
    bool operator<(ZeroSegment const& o) const {
        if (length != o.length)
            return length > o.length;
        else
            return left_idx < o.left_idx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n;
        cin >> n;
        set<ZeroSegment> s;
        s.insert({n, 0});
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            auto seg = *s.begin();
            s.erase(s.begin());
            int idx = seg.left_idx + (seg.length-1) / 2;
            a[idx] = i+1;
            ZeroSegment left{idx - seg.left_idx, seg.left_idx};
            ZeroSegment right{seg.left_idx + seg.length - idx - 1, idx + 1};
            if (left.length)
                s.insert(left);
            if (right.length)
                s.insert(right);
        }
        for (auto x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}