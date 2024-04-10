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

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    UnionFind uf(26);
    vector<pair<char, char>> res;
    for (int i = 0; i < n; i++) {
        if (uf.Find(s[i] - 'a') != uf.Find(t[i] - 'a')) {
            res.push_back({s[i], t[i]});
            uf.Union(s[i] - 'a', t[i] - 'a');
        }
    }
    cout << (int)res.size() << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
}