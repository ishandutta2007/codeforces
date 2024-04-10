// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

/*
4 1
2-2 1-0
y: 3 2
n: 

*/

array<int, 4> move_helper(int fs, int js, int fy, int jy) {
    int fn = fs - fy;
    int jn = js - jy;

    // we got yes
    // cerr << "yes: " << fy + jy << ' ' << fn << '\n';

    // we got no
    // cerr << "no:  " << fn + jn << ' ' << fy << '\n';

    return {fy + jy, fn, fn + jn, fy};
}

void ii() {
    while (1) {
        int fs, js, f, j;
        cin >> fs >> js >> f >> j;
        move_helper(fs, js, f, j);
    }
}

int dist[11][11];
pair<int, int> mv[11][11];

void calc_dists() {
    for (int i : ra(0, 11)) {
        for (int j : ra(0, 11)) {
            if (i + j <= 10) {
                if (i + j <= 2) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = 10000;
                }
            }
        }
    }

    for (int rep : ra(0, 1000)) {
        for (int i : ra(0, 11)) {
            for (int j : ra(0, 11)) {
                if (i + j <= 10) {
                    for (int x : ra(0, i+1)) {
                        for (int y : ra(0, j+1)) {
                            auto [p, q, r, s] = move_helper(i, j, x, y);
                            int d2 = 1 + max(dist[p][q], dist[r][s]);

                            if (d2 < dist[i][j]) {
                                dist[i][j] = d2;
                                mv[i][j] = {x, y};
                            }
                        }
                    }
                }
            }
        }
    }
}

template<class T>
void operator+= (vector<int>& v, const T& u) {
    R::copy(u, back_inserter(v));
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    calc_dists();
    // ii();

    int n;
    cin >> n;

    vector<int> full(n), jail;
    iota(begin(full), end(full), 1);

    int fs = n;
    int js = 0;

    while (fs + js > 2) {

        int fy, jy;
        if (fs + js > 10) {
            // whatever
            fy = fs / 2;
            jy = (js + 1) / 2;
        } else {
            tie(fy, jy) = mv[fs][js];
        }

        // ask
        cout << "? " << fy + jy;
        for (int x : R::take_view(full, fy)) {
            cout << ' ' << x;
        }
        for (int x : R::take_view(jail, jy)) {
            cout << ' ' << x;
        }

        cout << "\n" << flush;

        string resp;
        cin >> resp;
        
        vector<int> f2, j2;
        if (resp == "YES") {
            f2 += R::take_view(full, fy);
            f2 += R::take_view(jail, jy);
            j2 += R::drop_view(full, fy);
        } else {
            f2 += R::drop_view(full, fy);
            f2 += R::drop_view(jail, jy);
            j2 += R::take_view(full, fy);
        }
        swap(full, f2);
        swap(jail, j2);
        fs = ssize(full);
        js = ssize(jail);
    }

    full += jail;
    for (int x : full) {
        cout << "! " << x << '\n' << flush;
        string resp;
        cin >> resp;
        if (resp == ":)") {
            return 0;
        }
    }
}