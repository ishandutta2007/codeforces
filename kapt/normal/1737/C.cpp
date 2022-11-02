#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        set<int> st;
        array<int, 2> corner = {-1, -1};
        bool can_be = true;
        for (int i = 0; i < 3; ++i) {
            int a, b;
            cin >> a >> b;
            if (a == 1 && b == 1) {
                corner = {a, b};
            } else if (a == n && b == 1) {
                corner = {a, b};
            } else if (a == 1 && b == n) {
                corner = {a, b};
            } else if (a == n && b == n) {
                corner = {a, b};
            }
            if (min(abs(a - 1), abs(a - n)) + min(abs(b - 1), abs(b - n)) >= 2) {
                can_be = false;
            }
            st.insert((a % 2) * 2 + (b % 2));
        }
        int a, b;
        cin >> a >> b;
        if (corner[0] == -1 || !can_be) {
            if (st.count((a % 2) * 2 + (b % 2))) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (a == corner[0] || b == corner[1]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}