#include <bits/stdc++.h>
using namespace std;

class SegTree
{
public:
    SegTree(int n){
        indexes.assign(4*n, -1);
    }

    void update_single_node(int node, int l, int r, int x) {
        indexes[node] = x;
    }

    void shift(int node, int l, int r) {
        if (indexes[node] != -1) {
            int m = (l + r) / 2;
            update_single_node(2*node, l, m, indexes[node]);
            update_single_node(2*node+1, m, r, indexes[node] + (m - l));
            indexes[node] = -1;
        }
    }

    void copy(int node, int l, int r, int x, int y, int k) {
        int p = y;
        int q = y + k;

        if (p >= r || q <= l)
            return;

        if (p <= l && r <= q) {
            update_single_node(node, l, r, x + (l - p));
            return;
        }

        shift(node, l, r);
        int m = (l + r) / 2;
        copy(2*node, l, m, x, y, k);
        copy(2*node + 1, m, r, x, y, k);
    }

    int index(int node, int l, int r, int x) {
        if (indexes[node] != -1 || l + 1 == r) {
            return indexes[node] + (x - l);
        }

        int m = (l + r) / 2;
        if (x < m)
            return index(2*node, l, m, x);
        else
            return index(2*node+1, m, r, x);
    }

private:
    vector<int> indexes;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    SegTree st(n);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            st.copy(1, 0, n, x, y, k);
        } else {
            int x;
            cin >> x;
            x--;
            int index = st.index(1, 0, n, x);
            if (index >= 0)
                cout << a[index] << '\n';
            else
                cout << b[x] << '\n';
        }
    }
}