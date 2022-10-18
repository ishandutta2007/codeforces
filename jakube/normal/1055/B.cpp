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
        } else {
            p[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

private:
    std::vector<int> p, rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int l;
    cin >> l;
    vector<long long> a(n);
    for (auto& x : a)
        cin >> x;

    UnionFind uf(n);
    int c = 0;
    for (int x : a) {
        if (x > l)
            c++;
    }

    for (int i = 1; i < n; i++) {
        if (a[i-1] > l && a[i] > l) {
            uf.Union(i-1, i);
            c--;
        }
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << c << '\n';
        } else {
            int p, d;
            cin >> p >> d;
            p--;
            a[p] += d;
            if (a[p] > l && a[p] - d <= l) {
                c++;
            }
            if (p > 0 && a[p-1] > l && a[p] > l) {
                if (uf.Find(p-1) != uf.Find(p)) {
                    c--;
                    uf.Union(p-1, p);
                }
            }
            if (p + 1 < n && a[p+1] > l && a[p] > l) {
                if (uf.Find(p+1) != uf.Find(p)) {
                    c--;
                    uf.Union(p+1, p);
                }
            }
        }
    }
}