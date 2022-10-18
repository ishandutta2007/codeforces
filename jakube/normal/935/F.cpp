#include <bits/stdc++.h>
using namespace std;

template<typename Segment>
class SegmentTree {
public:
    using CombineFkt = std::function<Segment(Segment, Segment)>;

    SegmentTree(int count, CombineFkt combine) : combine{combine} {
        n = count;
        data.resize(2 * n);
    }

    SegmentTree(std::vector<Segment> const &values, CombineFkt combine) : combine{combine} {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[n]);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = combine(data[idx * 2], data[idx * 2 + 1]);
    }

    void update(int idx, int add_left, int add_right) {
        idx += n;
        data[idx] = Segment(data[idx].to_left+add_left, data[idx].to_right+add_right);

        while (idx > 1) {
            idx /= 2;
            data[idx] = combine(data[2 * idx], data[2 * idx + 1]);
        }
    }

    Segment minimum(int left, int right) { // interval [left, right)
        left += n;
        right += n;

        if (left + 1 == right)
            return data[left];

        Segment ret_l = data[left++], ret_r = data[--right];

        while (left < right) {
            if (left & 1) ret_l = combine(ret_l, data[left++]);
            if (right & 1) ret_r = combine(data[--right], ret_r);
            left >>= 1;
            right >>= 1;
        }
        return combine(ret_l, ret_r);
    }

    int n;
    std::vector<Segment> data;
    CombineFkt combine;
};

struct S {
    long long to_left = 0, to_right = 0;
    bool has_case_1;
    bool has_case_2;
    bool has_case_3;
    long long case2, case3_big, case3_small;
    S() {}
    S(long long l, long long r) {
        to_left = l;
        to_right = r;

        has_case_1 = to_left >= 0 && to_right >= 0;
        has_case_2 = (to_left >= 0 && to_right < 0)
            || (to_left < 0 && to_right >= 0);
        has_case_3 = to_left < 0 && to_right < 0;
        if (has_case_2) {
            case2 = min(to_left, to_right);
        }
        if (has_case_3) {
            case3_big = min(to_left, to_right);
            case3_small = max(to_left, to_right);
        }
    }
};

S combine(S l, S r) {
    S s;
    s.has_case_1 = l.has_case_1 || r.has_case_1;
    s.has_case_2 = l.has_case_2 || r.has_case_2;
    s.case2 = numeric_limits<long long>::min();
    if (l.has_case_2)
        s.case2 = max(s.case2, l.case2);
    if (r.has_case_2)
        s.case2 = max(s.case2, r.case2);
    s.has_case_3 = l.has_case_3 || r.has_case_3;
    if (l.has_case_3) {
        s.case3_big = l.case3_big;
        s.case3_small = l.case3_small;
    }
    if (r.has_case_3) {
        s.case3_big = r.case3_big;
        s.case3_small = r.case3_small;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<S> segments(n);
    for (int i = 1; i < n - 1; i++)
        segments[i] = S(a[i] - a[i-1], a[i] - a[i+1]);
    SegmentTree<S> st(segments, combine);

    long long cur = 0;
    for (int i = 0; i < n - 1; i++) {
        cur += abs(a[i+1] - a[i]);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        if (t == 1) {
            auto s = st.minimum(l - 1, r);
            if (s.has_case_1) {
                cout << cur + 2 * x << '\n';
            } else {
                long long ma = std::numeric_limits<long long>::min();
                if (s.has_case_2)
                    ma = max(ma, cur + 2*max(0LL, x + s.case2));
                if (s.has_case_3)
                    ma = max(ma, cur + 2*max(0LL, x + s.case3_big) - 2*min(-s.case3_small, (long long)x));
                cout << ma << '\n';
            }
        } else {
            cur -= abs(st.data[n+l-1].to_left);
            st.update(l-2, 0, -x);
            st.update(l-1, x, 0);
            cur += abs(st.data[n+l-1].to_left);
            cur -= abs(st.data[n+r-1].to_right);
            st.update(r-1, 0, x);
            st.update(r, -x, 0);
            cur += abs(st.data[n+r-1].to_right);
        }
    }
}