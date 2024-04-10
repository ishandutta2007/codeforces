#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, opposite;

    UnionFind(int n) {
        parent.resize(n);
        opposite.assign(n, -1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    int find_opposite(int i) {
        find(i);
        if (opposite[parent[i]] == -1) return -1;
        return opposite[parent[i]] = find(opposite[parent[i]]);
    }

    bool make_union(int i, int j) {
        int x = find(i);
        int y = find(j);
        int X = find_opposite(i);
        int Y = find_opposite(j);

        if (x == Y || y == X) {
            // i and j are already opposite
            return false;
        }

        // make union of the normal sets
        // x becomes the representant of both sets
        parent[y] = x;

        // make union of the opposite sets if necessary
        if (X != -1 && Y != -1) {
            parent[min(X, Y)] = max(X, Y);
        }

        // set linker to opposite
        opposite[x] = max(X, Y);

        return true;
    }

    bool make_opposite(int i, int j) {
        int x = find(i);
        int y = find(j);
        int X = find_opposite(i);
        int Y = find_opposite(j);

        if (x == y || (X == Y && X != -1)) {
            // i and j are in the same set 
            // or their opposite are in the same set
            return false;
        }

        // union of x and Y
        if (Y != -1) {
            parent[Y] = x;
        }

        // union of y and X
        if (X != -1) {
            parent[X] = y;
        }

        // set links to opposites
        opposite[x] = y;
        opposite[y] = x;

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, q;
    cin >> n >> m >> q;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words.begin(), words.end());
    auto get_index = [&words](const string s){ return lower_bound(words.begin(), words.end(), s) - words.begin(); };

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        string a, b;
        cin >> a >> b;
        int idx1 = get_index(a);
        int idx2 = get_index(b);
        if (type == 1) {
            bool ok = uf.make_union(idx1, idx2);
            cout << (ok ? "YES" : "NO") << '\n';
        } else {
            bool ok = uf.make_opposite(idx1, idx2);
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }

    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        int idx1 = get_index(a);
        int idx2 = get_index(b);
        if (uf.find(idx1) == uf.find(idx2)) {
            cout << "1\n";
        } else if (uf.find(idx1) == uf.find_opposite(idx2)) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }

    return 0;
}