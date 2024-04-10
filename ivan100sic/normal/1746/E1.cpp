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

void move_helper(int fs, int js, int fy, int jy) {
    int fn = fs - fy;
    int jn = js - jy;

    // we got yes
    cerr << "yes: " << fy + jy << ' ' << fn << '\n';

    // we got no
    cerr << "no:  " << fn + jn << ' ' << fy << '\n';
}

void ii() {
    while (1) {
        int fs, js, f, j;
        cin >> fs >> js >> f >> j;
        move_helper(fs, js, f, j);
    }
}

template<class T>
void operator+= (vector<int>& v, const T& u) {
    R::copy(u, back_inserter(v));
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    // ii();

    int n;
    cin >> n;

    vector<int> full(n), jail;
    iota(begin(full), end(full), 1);

    int fs = n;
    int js = 0;

    while (fs + js > 2) {

        int fy, jy;
        if (fs + js > 5 || js == 0) {
            // whatever
            fy = fs / 2;
            jy = (js + 1) / 2;
        } else if (fs + js == 5) {
            fy = 2, jy = 1;
        } else if (fs + js == 4) {
            fy = 1, jy = 1;
        } else if (fs == 2 && js == 1) {
            fy = 2, jy = 0;
        } else if (fs == 1 && js == 2) {
            fy = 1, jy = 1;
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