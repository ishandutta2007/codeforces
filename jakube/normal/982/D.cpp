#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        size.assign(n, 1);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (size[xRoot] <= size[yRoot]) {
            p[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        } else {
            p[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
    }

    int getSize(int x) {
        return size[Find(x)];
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

    std::vector<int> p, size;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        m[v[i]].push_back(i);
    }
    
    UnionFind uf(n);
    vector<int> sizes(n+1, 0);
    int components = 0;
    int last = -1;
    int number = 0;
    int result = m.begin()->first + 1;
    for (auto [x, indices] : m) {
        for (int i : indices) {
            last = i;
            if (i > 0 && v[i-1] <= x && i + 1 < n && v[i+1] < x) {
                sizes[uf.getSize(i-1)]--;
                sizes[uf.getSize(i+1)]--;
                uf.Union(i-1, i);
                uf.Union(i+1, i);
                sizes[uf.getSize(i)]++;
                components--;
            } else if (i > 0 && v[i-1] <= x) {
                sizes[uf.getSize(i-1)]--;
                uf.Union(i-1, i);
                sizes[uf.getSize(i)]++;
            } else if (i + 1 < n && v[i+1] < x) {
                sizes[uf.getSize(i+1)]--;
                uf.Union(i+1, i);
                sizes[uf.getSize(i)]++;
            } else {
                sizes[1]++;
                components++;
            }
        }
        if (sizes[uf.getSize(last)] == components) {
            if (components > number) {
                number = components;
                result = x + 1;
            }
        }
    }
    cout << result << '\n';
}