#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
        real_leader.resize(n);
        std::iota(real_leader.begin(), real_leader.end(), 0);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot]) {
            p[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            p[yRoot] = xRoot;
            real_leader[xRoot] = real_leader[yRoot];
        } else {
            p[yRoot] = xRoot;
            real_leader[xRoot] = real_leader[yRoot];
            rank[xRoot]++;
        }
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

    std::vector<int> p, rank, real_leader;

    int next(int x) {
        if (x >= (int)p.size())
            return std::numeric_limits<int>::max();
        return real_leader[Find(x)];
    }
};

void computePrimesLargest(int n, std::vector<int> &largest)
{
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}


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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> largest;
    computePrimesLargest(1'000'000, largest);
    vector<int> D(1'000'001, 1);
    for (int i = 2; i <= 1'000'000; i++) {
        int num = i;
        int l = largest[i];
        int cnt = 1;
        while (num % l == 0) {
            num /= l;
            cnt++;
        }
        D[i] = D[num] * cnt;
    }

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    UnionFind uf(n);
    SegmentTree st(v);

    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            for (int x = uf.next(l); x <= r; x = uf.next(x + 1)) {
                v[x] = D[v[x]];
                st.update(x, v[x]);
                if (v[x] <= 2 && x < n - 1)
                    uf.Union(x, x + 1);
            }
        } else {
            cout << st.sum(l, r + 1) << '\n';
        }
    }
    
}