#include <bits/stdc++.h>
using namespace std;

int x;

struct Segment {
    long long ans;
    vector<pair<int, int>> data_left, data_right;
    // data_left = [(0, ...
    // data_right = [(11101, 0), (10001, 2), (00001, 8)] reverse!
    int size;

    Segment(int value) {
        ans = value >= x ? 1 : 0;
        data_left.push_back({value, 0});
        data_right.push_back({value, 0});
        size = 1;
    }
    Segment() {}
};

Segment combine(Segment left, Segment right) {
    Segment res;
    res.ans = left.ans + right.ans;
    res.size = left.size + right.size;
    res.data_left = left.data_left;
    int last_mask = left.data_left.back().first;
    for (auto [mask, idx] : right.data_left) {
        if ((mask | last_mask) > last_mask) {
            last_mask |= mask;
            res.data_left.push_back({last_mask, left.size + idx});
        }
    }
    for (auto [mask, idx] : right.data_right) {
        res.data_right.push_back({mask, idx + left.size});
    }
    last_mask = res.data_right.back().first;
    for (auto [mask, idx] : left.data_right) {
        if ((mask | last_mask) > last_mask) {
            last_mask |= mask;
            res.data_right.push_back({last_mask, idx});
        }
    }

    auto& L = left.data_right;
    int n = L.size();
    auto& R = right.data_left;
    int m = R.size();
    int idx2 = m - 1;
    for (int idx1 = 0; idx1 < n; idx1++) {
        auto [mask, real_idx1] = L[idx1];

        while (idx2 > 0 && (mask | R[idx2-1].first) >= x) {
            idx2--;
        }

        int prev = idx1 == n - 1 ? 0 : L[idx1+1].second + 1;
        if ((mask | R[idx2].first) >= x) {
            int ls = L[idx1].second - prev + 1;
            int rs = right.size - R[idx2].second;
            res.ans += ls * (long long)rs;
        }
    }

    return res;
}

class SegmentTreeRec
{
public:
    SegmentTreeRec(std::vector<int> const &values)
    {
        n = values.size();
        data.resize(4 * n);
        build(values);
    }

    void build(std::vector<int> const &values, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l + 1 == r) {
            data[id] = Segment(values[l]);
        } else {
            int m = (l + r) >> 1;
            build(values, id << 1, l, m);
            build(values, id << 1 | 1, m, r);
            data[id] = combine(data[id << 1], data[id << 1 | 1]);
        }
    }

    Segment answer(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x <= l && r <= y) {
            return data[id];
        } else {
            int m = (l + r) >> 1;
            if (y <= m)
                return answer(x, y, id << 1, l, m);
            if (x >= m)
                return answer(x, y, id << 1 | 1, m, r);

            return combine(answer(x, y, id << 1, l, m),
                            answer(x, y, id << 1 | 1, m, r));
        }
    }

    void update(int pos, int value, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (pos < l || pos >= r) {
        } else if (l == pos && pos + 1 == r) {
            data[id] = Segment(value);
        } else {
            int m = (l + r) >> 1;
            update(pos, value, id << 1, l, m);
            update(pos, value, id << 1 | 1, m, r);
            data[id] = combine(data[id << 1], data[id << 1 | 1]);
        }
    }

private:
    int n;
    std::vector<Segment> data;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegmentTreeRec st(v);

    for (int q = 0; q < m; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, y;
            cin >> i >> y;
            st.update(i-1, y);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.answer(l-1, r).ans << '\n';
        }
    }
}