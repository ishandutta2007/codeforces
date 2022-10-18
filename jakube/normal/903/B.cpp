#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, a1, c1;
    cin >> h1 >> a1 >> c1;
    int h2, a2;
    cin >> h2 >> a2;

    if (a1 >= h2) {
        cout << 1 << '\n';
        cout << "STRIKE" << '\n';
        return 0;
    }
    
    int L = -1;
    int R = std::numeric_limits<int>::max() / 2;

    // me = h1 + x * c1 - 
    // total = a + 
    int mo = (h2 + a1 - 1) / a1;

    while (L + 1 < R) {
        long long M = (L + R) / 2;
        long long h = h1 + M * (c1 - a2);
        h -= (mo - 1) * (long long)a2;
        if (h > 0)
            R = M;
        else
            L = M;
    }

    cout << R + mo << endl;
    for (int i = 0; i < R; i++) {
        cout << "HEAL" << '\n';
    }
    for (int i = 0; i < mo; i++) {
        cout << "STRIKE" << '\n';
    }
}