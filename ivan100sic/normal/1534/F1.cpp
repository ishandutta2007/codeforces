// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
vector<string> a;
int t[400005];
basic_string<int> e[400005];

int co(int x, int y) {
    return x*m + y;
}

void check(int x, int y, int x2, int y2) {
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) return;
    if (a[x2][y2] == '#') {
        e[co(x, y)] += co(x2, y2);
    }
}

int idx[400005], low[400005], inst[400005], comp[400005], cb, dt;
basic_string<int> st;

void scc(int x) {
    idx[x] = low[x] = ++dt;
    inst[x] = 1;
    st += x;

    for (int y : e[x]) {
        if (idx[y] == 0) {
            scc(y);
            low[x] = min(low[x], low[y]);
        } else if (inst[y]) {
            low[x] = min(low[x], low[y]);
        }
    }

    if (idx[x] == low[x]) {
        cb++;
        while (1) {
            int t = st.back();
            st.pop_back();
            inst[t] = 0;
            comp[t] = cb;
            if (t == x) {
                break;
            }
        }
    }
}

int indeg[400005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<m; i++) {
        cin >> t[i];
    }

    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            if (a[i][j] == '#') {
                check(i, j, i, j-1);
                check(i, j, i, j+1);
                check(i, j, i-1, j);
                int f = -1;
                for (int k=i+1; k<n; k++) {
                    if (a[k][j] == '#') {
                        check(i, j, k, j);
                        f = k;
                        break;
                    }
                    check(i, j, k, j-1);
                    check(i, j, k, j+1);
                }

                if (f == -1) {
                    i = n;
                } else {
                    i = f - 1;
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '#' && idx[co(i, j)] == 0) {
                scc(co(i, j));
            }
        }
    }

    for (int x=0; x<n*m; x++) {
        if (idx[x]) {
            for (int y : e[x]) {
                if (comp[x] != comp[y]) {
                    indeg[comp[y]]++;
                }
            }
        }
    }

    cout << count(indeg+1, indeg+1+cb, 0) << '\n';
}