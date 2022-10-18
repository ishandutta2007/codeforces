#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    public:
        vector<int> par;

        UnionFind(int n) 
        {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
        }

        int find(int i) {
            return (par[i] == i) ? i : (par[i] = find(par[i]));
        }

        void Union(int x, int y) {
            int a = find(x);
            int b = find(y);
            if (a != b) {
                par[a] = b;
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];

    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        uf.Union(i, v[i]-1);
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(uf.find(i));
    }

    cout << s.size() << endl;
    

    return 0;
}