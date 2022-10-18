#include <bits/stdc++.h>
using namespace std;

int rem = 60;
int oppo;

auto get(int idx) {
    // vector<int> v = {1, 0, 1, 2, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 7, 8, 7, 6, 5, 4, 5, 4, 3, 4, 3, 2, 1, 0, 1, 0, -1, 0, -1, 0, 1, 2, 3, 2, 1, 0, 1, 2, 1, 0, -1, 0, -1, 0, 1, 0, -1, 0, 1, 2, 1, 0, -1, -2, -1, 0};
    cout << "? " << idx + 1 << endl;
    rem--;
    int x;
    cin >> x;
    // x = v[idx];
    cout << "? " << idx + 1 + oppo << endl;
    int y;
    cin >> y;
    // y = v[idx+oppo];
    if (x == y) {
        cout << "! " << idx + 1 << '\n';
        exit(0);
    }
    return make_pair(x, y);
}

int main() {
    int n;
    cin >> n;
    oppo = n / 2; 

    if (oppo % 2) {
        cout << "! -1" << endl;
        return 0;
    }

    int L = 0;
    auto [l1, l2] = get(L);
    int R = oppo - 1;
    auto [r1, r2] = get(R);
    while (L + 1 != R) {
        int M = (L + R) / 2;
        auto [m1, m2] = get(M);
        if ((m1 > m2 && l2 > l1 && l2 >= m2 && l1 <= m1) ||
             (m2 > m1 && l1 > l2 && l1 >= m1 && l2 <= m2) || 
             (min(l1, m1) <= min(l2, m2) && max(l1, m1) >= max(l2, m2)) ||
             (min(l2, m2) <= min(l1, m1) && max(l2, m2) >= max(l1, m1))) {
            r1 = m1;
            r2 = m2;
            R = M;
        } else {
            l1 = m1;
            l2 = m2;
            L = M;
        }
    }
}