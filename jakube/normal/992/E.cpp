#include <bits/stdc++.h>
using namespace std;

class SegmentTreeSum {
public:
    SegmentTreeSum(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = data[2 * idx] + data[2 * idx + 1];
    }

    void update(int idx, int value) {
        idx += n;
        data[idx] = value;

        while (idx > 1) {
            idx /= 2;
            data[idx] = data[2 * idx] + data[2 * idx + 1];
        }
    }

    long long sum(int left, int right) { // interval [left, right)
        long long ret = 0;
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
    std::vector<long long> data;
};

class SegmentTreeRecMax
{
public:
    SegmentTreeRecMax(std::vector<int> const &values)
    {
        n = values.size();
        data.assign(4 * n, 0);
        build(values);
    }

    void build(std::vector<int> const &values, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l + 1 == r) {
            data[id] = values[l];
        } else {
            int m = (l + r) >> 1;
            build(values, id << 1, l, m);
            build(values, id << 1 | 1, m, r);
            data[id] = std::max(data[id << 1], data[id << 1 | 1]);
        }
    }

    int find_greater_or_equal(int l_bound, int x, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (data[id] < x || r <= l_bound)
            return n;

        if (l + 1 == r) {
            return l;
        }

        int m = (l + r) >> 1;
        if (data[id << 1] >= x) {
            int res = find_greater_or_equal(l_bound, x, id << 1, l, m);
            if (res != n)
                return res;
        }
        return find_greater_or_equal(l_bound, x, id << 1 | 1, m, r);
    }

    void update(int pos, int x, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (pos < l || pos >= r) {
        } else if (l == pos && pos + 1 == r) {
            data[id] = x;
        } else {
            int m = (l + r) >> 1;
            update(pos, x, id << 1, l, m);
            update(pos, x, id << 1 | 1, m, r);
            data[id] = std::max(data[id << 1], data[id << 1 | 1]);
        }
    }

private:
    int n;
    std::vector<int> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    SegmentTreeSum st_sum(a);
    SegmentTreeRecMax st_max(a);

    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        a[p] = x;
        st_sum.update(p, x);
        st_max.update(p, x);

        long long sum = 0;
        int j = 0;
        bool king = false;
        while (j < n && sum <= 1'000'000'000) {
            if (a[j] == sum) {
                cout << j + 1 << '\n';
                king = true;
                break;
            }
            j = st_max.find_greater_or_equal(j + 1, a[j] + sum);
            sum = st_sum.sum(0, j);
        }
        if (!king)
            cout << -1 << '\n';
    }
}