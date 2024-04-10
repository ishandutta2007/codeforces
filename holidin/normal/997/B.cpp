#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i, j, n, x, y, i1, i2, i3, i4;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n < 30) {
        set <int> s;
        for (i1 = 0; i1 <= n; ++i1)
        for (i2 = 0; i2 <= n; ++i2)
        for (i3 = 0; i3 <= n; ++i3)
        for (i4 = 0; i4 <= n; ++i4)
        if (i1 + i2 + i3 + i4 == n)
            s.insert(i1 + i2 * 5 + i3 * 10 + i4 * 50);
        cout << s.size();
        return 0;
    }
    set <long long> s, s1;
    for (i1 = 0; i1 <= 20; ++i1)
    for (i2 = 0; i2 <= 20; ++i2)
    for (i3 = 0; i3 <= 20; ++i3)
    for (i4 = 0; i4 <= 20; ++i4)
    if (i2 * 4 + i3 * 9 + i4 * 49 <= 100  && i2 * 5 + i3 * 10 + i4 * 50 > 0)
        s1.insert(i2 * 4 + i3 * 9 + i4 * 49);
    for (i1 = 0; i1 <= 8; ++i1)
    for (i2 = 0; i2 <= 8; ++i2)
    for (i3 = 0; i3 <= 8; ++i3)
    for (i4 = 0; i4 <= 8; ++i4)
    if (i1 + i2 + i3 + i4 == 8)
        s.insert(i1 + i2 * 5 + i3 * 10 + i4 * 50);
    cout << 50 * (n - 8) + s.size() - n - (100 - s1.size()) + 10;
}