#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    string hh, mm;
    cin >> hh >> mm;
    
    int h = (hh[0] - '0') * 10 + (hh[1] - '0');
    int m = (mm[0] - '0') * 10 + (mm[1] - '0');

    for (int i = 0; i < 1e6; i++) {
        if (h % 10 == 7 || m % 10 == 7) {
            cout << i << '\n';
            return 0;
        }
        m -= x;
        if (m < 0) {
            h--;
            m += 60;
        }
        if (h < 0)
            h += 24;
    }
}