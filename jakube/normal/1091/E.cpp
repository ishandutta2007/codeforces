#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    SegmentTree(std::vector<long long> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = std::min(data[idx * 2], data[idx * 2 + 1]);
    }

    int minimum(int left, int right) { // interval [left, right)
        long long ret = std::numeric_limits<int>::max();
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret = std::min(ret, data[left++]);
            if (right & 1) ret = std::min(ret, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<long long> data;
};

class SegmentTreeMax {
public:
    SegmentTreeMax(std::vector<long long> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = std::max(data[idx * 2], data[idx * 2 + 1]);
    }

    int maximium(int left, int right) { // interval [left, right)
        long long ret = 0;
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
    std::vector<long long> data;
};

vector<int> d;
vector<int> d_rev;
vector<long long> psum, psum_rev;
long long sum(int x, int y) {
    return psum[y+1] - psum[x];
};
long long sum_rev(int x, int y) {
    return psum_rev[y+1] - psum_rev[x];
};
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    d.resize(n);
    for (auto& x : d)
        cin >> x;
    sort(d.begin(), d.end());
    d_rev = d;
    reverse(d.begin(), d.end());
    psum.assign(d.size() + 1, 0);
    psum_rev.assign(d.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < d.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + d[psum_idx];
        psum_rev[psum_idx+1] = psum_rev[psum_idx] + d_rev[psum_idx];
    }

    vector<long long> inequality1(n + 1);
    vector<long long> inequality2(n + 1);
    for (int i = 0; i < n + 1; i++) {
        long long k = i + 1;
        int start = k - 1;
        auto smaller = lower_bound(d_rev.begin(), d_rev.begin() + (n - 1 - start) + 1, k) - d_rev.begin();
        long long m = k * (k-1);
        long long bigger = n - start - smaller;
        m += k * bigger + sum_rev(0, smaller - 1);
        m -= sum(0, start - 1);
        inequality1[i] = m;

        start = k;
        smaller = lower_bound(d_rev.begin(), d_rev.begin() + (n - 1 - start) + 1, k) - d_rev.begin();
        bigger = n - start - smaller;
        m = 0;
        m += sum(0, start - 1);
        m -= k * (k - 1);
        m -= k*bigger + sum_rev(0, smaller - 1);
        // cout << m << '\n';
        inequality2[i] = m;
    }
    SegmentTree upper_bound_tree(inequality1);
    SegmentTreeMax lower_bound_tree(inequality2);

    vector<int> possibilities;
    for (int x = accumulate(d.begin(), d.end(), 0LL) % 2; x <= n; x += 2) {
        int t = lower_bound(d_rev.begin(), d_rev.end(), x) - d_rev.begin();
        // d_rev[t] >= i;
        // d_rev[n-1] >= i;
        int bigger = n - 1 - t + 1;
        int k = bigger;
        bool b = true;
        b &= x <= upper_bound_tree.minimum(k, n + 1);
        // for (int K = 1; K < k; K++) {
        //     if (x < K)
        //         b &= x >=
        // }
        // if (x < k) {
            b &= x >= lower_bound_tree.maximium(0, k);
        // } else {

        // }
        
        if (b) {
            possibilities.push_back(x);
        }
    }

    if (possibilities.empty()) {
        cout << -1 << '\n';
    } else {
        for (auto x : possibilities) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}