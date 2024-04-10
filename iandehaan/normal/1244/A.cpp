#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int neededpencils = b/d;
        if (b % d) neededpencils++;
        int neededpens = a / c;
        if (a % c) neededpens++;

        if (neededpencils + neededpens > k) {
            cout << -1 << endl;
        } else {
            cout << neededpens << ' ' << neededpencils << endl;
        }
    }
}