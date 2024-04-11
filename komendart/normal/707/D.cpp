#include <bits/stdc++.h>

using namespace std;

const int maxq = 100005;
int n, m, q;

struct State {
    int cnt;
    char **a;

    State() {}

    void init() {
        cnt = 0;
        a = new char*[n];
        for (int i = 0; i < n; i++) {
            a[i] = new char[m];
            for (int j = 0; j < m; j++) {
                a[i][j] = 0;
            }
        }
    }

    void inverse(int x) {
        char **na = new char*[n];
        for (int i = 0; i < n; i++) {
            na[i] = a[i];
        }
        na[x] = new char[m];
        for (int j = 0; j < m; j++) {
            cnt -= a[x][j];
            na[x][j] = a[x][j] ^ 1;
            cnt += na[x][j];
        }
        a = na;
    }

    void assign(int x, int y, int v) {
        char **na = new char*[n];
        for (int i = 0; i < n; i++) {
            na[i] = a[i];
        }
        na[x] = new char[m];
        for (int j = 0; j < m; j++) {
            cnt -= a[x][j];
            na[x][j] = a[x][j];
            if (j == y) na[x][j] = v;
            cnt += na[x][j];
        }
        a = na;
    }
};

State states[maxq];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> q;

    states[0].init();
    for (int i = 1; i <= q; i++) {
        int tp; cin >> tp;
        states[i] = states[i - 1];
        if (tp == 1) {
            int x, y;
            cin >> x >> y;
            states[i].assign(x - 1, y - 1, 1);
        } else if (tp == 2) {
            int x, y;
            cin >> x >> y;
            states[i].assign(x - 1, y - 1, 0);
        } else if (tp == 3) {
            int x;
            cin >> x;
            states[i].inverse(x - 1);
        } else {
            int k; cin >> k;
            states[i] = states[k];
        }
        cout << states[i].cnt << '\n';
    }
}