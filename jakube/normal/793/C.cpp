#include <bits/stdc++.h>
using namespace std;

struct frac {
    long long a, b;
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

bool bigger(frac x, frac y) {
    return x.a * sgn(x.b) * abs(y.b) > y.a * sgn(y.b) * abs(x.b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    


    frac t_min = {0, 1};
    frac t_max = {10000000000LL, 1};

    for (int i = 0; i < n; i++) {
        int rx, ry, vx, vy;
        cin >> rx >> ry >> vx >> vy;
        
        // double t_mi = 0;
        // double t_ma = 1000000000;

        if (vx) {
            frac t1 = {x1 - rx, vx};
            frac t2 = {x2 - rx, vx};
            if (vx > 0) {
                if (bigger(t1, t_min)) t_min = t1;
                if (!bigger(t2, t_max)) t_max = t2;
            } else {
                if (bigger(t2, t_min)) t_min = t2;
                if (!bigger(t1, t_max)) t_max = t1;
            }
        } else {
            if (x1 < rx && rx < x2) {
                // all ok
            } else {
                cout << -1 << endl;
                return 0;
            }
        }

        if (vy) {
            frac t1 = {y1 - ry, vy};
            frac t2 = {y2 - ry, vy};
            if (vy > 0) {
                if (bigger(t1, t_min)) t_min = t1;
                if (!bigger(t2, t_max)) t_max = t2;
            } else {
                if (bigger(t2, t_min)) t_min = t2;
                if (!bigger(t1, t_max)) t_max = t1;
            }
        } else {
            if (y1 < ry && ry < y2) {
                // all ok
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout.precision(20);
    cout << fixed;
    
    
    if (bigger(t_max, t_min)){
        cout << t_min.a / (double)t_min.b << endl;
    } else {
        cout << -1 << endl;
    }
}