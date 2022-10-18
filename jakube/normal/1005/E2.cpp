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

    void update(int idx, int add) {
        idx += n;
        data[idx] += add;

        while (idx > 1) {
            idx /= 2;
            data[idx] = data[2 * idx] + data[2 * idx + 1];
        }
    }

    int sum(int left, int right=-1) { // interval [left, right)
        if (right == -1)
            right = n;

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

long long f(vector<int> v, int m) {
    long long res = 0;
    int n = v.size();

    SegmentTree st(n * 2 + 1);
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= m)
            d++;
        else
            d--;
        st.update(d + n, 1);
    }

    d = 0;
    for (int i = 0; i < n; i++) {
        res += st.sum(1 + d + n);
        if (v[i] >= m)
            d++;
        else
            d--;
        st.update(d + n, -1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << f(v, m) - f(v, m+1) << '\n';
}