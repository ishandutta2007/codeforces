#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    public:
        vector<int> par;

        UnionFind(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
        }

        int find(int u) {
            return u == par[u] ? u : par[u] = find(par[u]);
        }

        void do_union(int u, int v) {
            int a = find(u);
            int b = find(v);
            if (a < b)
                par[b] = a;
            if (b < a)
                par[a] = b;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(k);
    for (int idx = 0; idx < k; idx++)
        cin >> c[idx];
    vector<int> psum(k+1, 0);
    for (int i = 0; i < k; i++) {
        psum[i+1] = psum[i] + c[i];
    }

    
    vector<vector<int>> M(k, vector<int>(k, 1e9));
    for (int i = 0; i < k; i++) {
        if (c[i] == 1) {
            M[i][i] = 0;
        }
    }

    UnionFind uf(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        int idx1 = (upper_bound(psum.begin(), psum.end(), u-1) - psum.begin()) - 1;
        int idx2 = (upper_bound(psum.begin(), psum.end(), v-1) - psum.begin()) - 1;
        M[idx1][idx2] = min(M[idx1][idx2], w);
        M[idx2][idx1] = min(M[idx2][idx1], w);
        if (w == 0) uf.do_union(u-1, v-1);
    }

    // check
    int sum = 0;
    for (int i = 0; i < k; i++) {
        int tp = uf.find(sum);
        for (int j = sum; j < sum + c[i]; j++) {
            if (uf.find(j) != tp) {
                cout << "No" << endl;
                return 0;
            }
        }
        sum += c[i];
    }

    // Floyd-Warshall
    for (int K = 0; K < k; K++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                M[i][j] = min(M[i][j], M[i][K] + M[K][j]);
            }
        }
    }

    // bool b = true;
    // for (int i = 0; i < k; i++) {
    //     b &= M[i][i] == 0;
    // }

    // if (b) {
        cout << "Yes\n";
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cout << (M[i][j] == 1e9 ? -1 : M[i][j]) << ' ';
            }
            cout << '\n';
        }
        cout << flush;
    // } else {
    //     cout << "No" << endl;
    // }

    return 0;
}