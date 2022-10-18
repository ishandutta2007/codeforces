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
    vector<string> M(n);
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }
    
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 'A')
                uf.Union(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 'X' && uf.Find(i) == uf.Find(j)) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    vector<int> size(n, 0);
    for (int i = 0; i < n; i++) {
        size[uf.Find(i)]++;
    }

    vector<int> comps;
    vector<int> in_comps(n, -1);
    for (int i = 0; i < n; i++) {
        if (size[i] > 1) {
            in_comps[i] = comps.size();
            comps.push_back(i);
        }
    }

    int m = comps.size();

    if (m < 2) {
        cout << n - 1 + m << '\n';
        return 0;
    }

    vector<vector<bool>> disallow(m, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        if (in_comps[uf.Find(i)] < 0) continue;
        for (int j = 0; j < n; j++) {
            if (in_comps[uf.Find(j)] < 0) continue;
            if (M[i][j] == 'X') {
                disallow[in_comps[uf.Find(i)]][in_comps[uf.Find(j)]] = true;
                disallow[in_comps[uf.Find(j)]][in_comps[uf.Find(i)]] = true;
            }
        }
    }

    vector<int> perm(m);
    iota(perm.begin(), perm.end(), 0);

    auto t1 = std::chrono::high_resolution_clock::now();
    int mn = m;
    long long milli;
    do {
        random_shuffle(perm.begin(), perm.end());
        int cnt = 1;
        vector<int> color(n, 0);
        for (int i = 0; i < m; i++) {
            vector<bool> color_forbidden(n, false);
            for (int j = 0; j < i; j++) {
                if (disallow[perm[i]][perm[j]])
                    color_forbidden[color[j]] = true;
            }
            int c = find(color_forbidden.begin(), color_forbidden.end(), false) - color_forbidden.begin();
            cnt = max(c + 1, cnt);
            color[i] = c;
        }
    
        mn = min(mn, cnt);

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
        milli = duration.count();
    } while (milli < 4800);

    cout << n - 1 + mn << '\n';
}