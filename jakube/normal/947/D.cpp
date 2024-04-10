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

    void update(int idx, Segment value) {
        idx += n;
        data[idx] = value;

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

private:
    int n;
    std::vector<Segment> data;
    CombineFkt combine;
};

struct Segment {
    int c = 0, as = 0;
    int size = 1;
};

Segment combine(Segment l, Segment r) {
    Segment res;
    res.size = l.size + r.size;

    if (r.as == r.size) {
        res.as = r.size + l.as;
        res.c = l.c;
    } else {
        res.as = r.as;
        res.c = l.c + r.c;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    
    int n = s.size();
    int m = t.size();
    
    SegmentTree<Segment> st_s(n, combine);
    SegmentTree<Segment> st_t(m, combine);

    for (int i = 0; i < n; i++) {
        Segment seg;
        if (s[i] == 'A')
            seg.as = 1;
        else
            seg.c = 1;
        st_s.update(i, seg);
    }
    for (int i = 0; i < m; i++) {
        Segment seg;
        if (t[i] == 'A')
            seg.as = 1;
        else
            seg.c = 1;
        st_t.update(i, seg);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        auto s1 = st_s.minimum(a-1, b);
        auto s2 = st_t.minimum(c-1, d);

        if (s1.as < s2.as || s1.c % 2 != s2.c % 2 || s1.c > s2.c) {
            cout << 0;
            continue;
        }

        if (s1.c == s2.c) {
            if (s1.as % 3 == s2.as % 3)
                cout << 1;
            else 
                cout << 0;
        } else {
            if (s1.as > s2.as) {
                cout << 1;
            } else {
                if (s1.c)
                    cout << 1;
                else
                    cout << 0;
            }
        }

        // if (s2.c > 0 && s1.c == 0) {
        //     s1.as--;
        //     s1.c += 2;
        // }
        // if (s1.as > s2.as && s1.as % 3 != s2.as % 3) {
        //     int t = (s1.as - s2.as) % 3;
        //     s1.as -= t;
        //     s1.c += 2;
        // }
        // if (s1.as >= s2.as && s1.as % 3 == s2.as % 3 && s1.c <= s2.c && (s2.c - s1.c) % 2 == 0)
        //     cout << 1;
        // else 
        //     cout << 0;
    }
    cout << endl;
}