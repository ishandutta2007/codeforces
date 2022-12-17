#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

long long nod(long long a, long long b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

set <pair<int, int> > s;
long long a[N], b[N], c[N], lx[N], ly[N], rx[N], ry[N], ans;

int main() {
    long long x1, y1, x2, y2;
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        lx[i] = min(x1, x2);
        rx[i] = max(x1, x2);
        ly[i] = min(y1, y2);
        ry[i] = max(y1, y2);
        a[i] = y2 - y1;
        b[i] = x1 - x2;
        c[i] = -a[i] * x1 - b[i] * y1;
        ans += nod(abs(x1 - x2), abs(y1 - y2)) + 1;
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < i; ++j)
        if (a[i] * b[j] - a[j] * b[i] != 0 && (c[i] * b[j] - c[j] * b[i]) % (a[i] * b[j] - a[j] * b[i]) == 0 && (a[i] * c[j] - a[j] * c[i]) % (a[i] * b[j] - a[j] * b[i]) == 0) {
            x1 = -(c[i] * b[j] - c[j] * b[i]) / (a[i] * b[j] - a[j] * b[i]);
            y1 = -(a[i] * c[j] - a[j] * c[i]) / (a[i] * b[j] - a[j] * b[i]);
            if (x1 >= max(lx[i], lx[j]) && x1 <= min(rx[i], rx[j]) && y1 >= max(ly[i], ly[j]) && y1 <= min(ry[i], ry[j]))
            s.insert({x1, y1});

        }
        ans -= s.size();
        s.clear();
    }
    cout << ans;
}