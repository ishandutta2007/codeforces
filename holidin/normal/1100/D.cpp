#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int x[N], y[N], t[N];
set <pair<int, int> > s;

int main() {
    int i, j, n, k, xk, yk, a, b;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> xk >> yk;
    n = 666;
    for (i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        //x[i] = rand() % 999 + 1;
        //y[i] = rand() % 999 + 1;
        s.insert({x[i], y[i]});
    }
    while (xk != 500 || yk != 500) {
        int xk1 = xk, yk1 = yk;
        if (xk < 500)
            ++xk1;
        if (xk > 500)
            --xk1;
        if (yk < 500)
            ++yk1;
        if (yk > 500)
            --yk1;
        if (s.find({xk1, yk1}) != s.end())
            cout << xk1 << ' ' << yk << endl;
        else
            cout << xk1 << ' ' << yk1 << endl;
        xk = xk1;
        yk = yk1;
        cin >> k >> a >> b;
        --k;
        if (k < 0)
            return 0;
        s.erase({x[k], y[k]});
        x[k] = a;
        y[k] = b;
        s.insert({x[k], y[k]});
    }
    int dx, dy, tp1 = 0, tp2 = 0;
    for (i = 0; i < n; ++i) {
        if (x[i] < 500)
            t[i] = 1;
        else
            t[i] = 2;
        if (t[i] == 1)
            ++tp1;
        else
            ++tp2;
    }
    int ans = 0;
    if (tp1 > tp2)
        dx = -1;
    else
        dx = 1;
    ans += max(tp1, tp2);
    tp1 = 0, tp2 = 0;
    for (i = 0; i < n; ++i)
    if ((dx == -1 && t[i] == 2) || (dx == 1 && t[i] == 1)){
        if (y[i] < 500)
            ++tp1;
        else
            ++tp2;
    }
    if (tp1 > tp2)
        dy = -1;
    else
        dy = 1;
    ans += max(tp1, tp2);
    while (true) {
        int xk1 = xk + dx, yk1 = yk + dy;
        if (s.find({xk1, yk1}) != s.end())
            cout << xk1 << ' ' << yk << endl;
        else
            cout << xk1 << ' ' << yk1 << endl;
        cin >> k >> a >> b;
        --k;
        if (k < 0)
            return 0;
        s.erase({x[k], y[k]});
        x[k] = a;
        y[k] = b;
        s.insert({x[k], y[k]});
        xk = xk1;
        yk = yk1;
    }
}