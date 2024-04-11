#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

struct Tq {
    int t;
    int x;
    int y;
    int z;
};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);


    int n, m, q;
    cin >> n >> m >> q;

    vector<Tq> qs;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t < 3) {
            int x;
            cin >> x;
            qs.push_back({t, x, 0, 0});
        } else {
            int x, y, z;
            cin >> x >> y >> z;
            qs.push_back({t, x, y, z});
        }
    }

    vector< vector<int> > a(n, vector<int>(m, 0));
    for (int i = ((int)qs.size()) - 1; i >= 0; --i) {
        const auto q = qs[i];
        if (q.t == 3) {
            a[q.x - 1][q.y - 1] = q.z;
        } else
        if (q.t == 1) {
            int row = q.x - 1;

            int t = a[row][m - 1];
            for (int i = m - 1; i > 0; --i) {
                a[row][i] = a[row][i - 1];
            }
            a[row][0] = t;
        } else {
            int col = q.x - 1;

            int t = a[n - 1][col];
            for (int i = n - 1; i > 0; --i) {
                a[i][col] = a[i - 1][col];
            }
            a[0][col] = t;
        }
    }       

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}