#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> a[2009];
bool vs[2009];

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i].first;
    for (int i = 0; i < m; i++) {
        int t1, t2; cin >> t1 >> t2;
        a[t1].second = t2; a[t2].second = t1;
    }
    int t; cin >> t;
    int rp = -1;
    for (int i = 0; i < n; i++) {
        if (t == 2) {
            cin >> rp;
            vs[rp] = true;
        }
        if (rp != -1 && a[rp].second != 0) {
            cout << a[rp].second << '\n';
            a[a[rp].second].second = 0; vs[a[rp].second] = true; a[rp].second = 0; vs[rp] = true;
            if (t == 1) {
                cin >> rp;
                vs[rp] = true;
            }
            continue;
        }
        int m1 = 0, m2 = 0;
        for (int i = 2 * n; i >= 1; i--) {
            if (vs[i]) continue;
            if (a[m1] < a[i]) {
                m2 = m1; m1 = i;
            }
            else if (a[m2] < a[i])
                m2 = i;
        }
        int ms = -100000, ma = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (vs[i]) continue;
            int rm = 0;
            if (a[i].second != 0)
                rm = a[i].second;
            else if (i != m1)
                rm = m1;
            else
                rm = m2;
            if (ms < a[i].first - a[rm].first) {
                ms = a[i].first - a[rm].first;
                ma = i;
            }
        }
        if (a[ma].second != 0) {
            a[a[ma].second].second = 0; vs[a[ma].second] = true;
        }
        a[ma].second = 0; vs[ma] = true;
        cout << ma << '\n';
        if (t == 1) {
            cin >> rp;
            vs[rp] = true;
        }
    }
    return 0;
}