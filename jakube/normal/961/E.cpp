#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = data[2 * idx] + data[2 * idx + 1];
    }

    void update(int idx, int value) {
        idx += n;
        data[idx] += value;

        while (idx > 1) {
            idx /= 2;
            data[idx] = data[2 * idx] + data[2 * idx + 1];
        }
    }

    int sum(int left, int right) { // interval [left, right)
        int ret = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret += data[left++];
            if (right & 1) ret += data[--right];
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<int> data;
};

struct Query
{
    int idx, h, ans;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    SegmentTree st(n+2);
    vector<Query> queries(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        auto& q = queries[i];
        q.idx = i;
        cin >> q.h;
        v[i] = q.h;
    }

    sort(queries.begin(), queries.end(), [](auto p, auto q) {
        return p.h < q.h;
    });

    int idx = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        x = min(x, n+1);
        st.update(x, 1);
        // res += st.sum(x, n+2);
        while (idx < n && queries[idx].h == i + 1) {
            auto& q = queries[idx];
            q.ans = st.sum(q.idx+1, n+2);
            idx++;
        }
    }
    while (idx < n) {
        auto& q = queries[idx];
        q.ans = st.sum(q.idx+1, n+2);
        idx++;
    }

    long long res = 0;
    for (auto q : queries) {
        res += q.ans;
        if (q.idx + 1 <= q.h)
            res--;
    }
    cout << res / 2 << endl;
}