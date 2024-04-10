#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct dsu {
    int connComps;
    vector<int> par, siz;
    dsu(int n) {
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        connComps = n;
    }
    int get(int x) {
        if(x == par[x]) return x;
        return par[x] = get(par[x]);
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y) return false;
        connComps--;
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> mat(n, vector<int>(n));
    if(n <= 4) { // Brute force
        int ed = ((n * n - n) / 2);
        for(int x = 0; x < (1 << ed); x++) {
            int g = 0;
            dsu uf1(n), uf2(n);
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    // I know union find is overkill but it's the first thing I thought of lol
                    if((1 << g) & x) {
                        uf1.unite(i, j);
                        mat[i][j] = mat[j][i] = 1;
                    }
                    else {
                        uf2.unite(i, j);
                        mat[i][j] = mat[j][i] = 0;
                    }
                    g++;
                }
            }
            if(uf1.connComps == a && uf2.connComps == b) {
                cout << "YES\n";
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        cout << mat[i][j];
                    }
                    cout << '\n';
                }
                return 0;
            }
        }
        cout << "NO\n";
    }
    else { // The actual thing
        if(min(a, b) != 1) {
            cout << "NO\n";
            return 0;
        }
        int comp = max(a, b);
        if(comp == 1) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(abs(i - j) == 1 || abs(i - j) == n-1) {
                        mat[i][j] = 1;
                    }
                    else {
                        mat[i][j] = 0;
                    }
                }
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i != j && min(i, j) >= comp-1) {
                        mat[i][j] = 1;
                    }
                    else {
                        mat[i][j] = 0;
                    }
                }
            }
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) cout << 0;
                else if(comp == a) cout << mat[i][j];
                else cout << !mat[i][j];
            }
            cout << '\n';
        }
    }
}