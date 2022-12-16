#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int aa, bb;
        cin >> aa >> bb;

        int outt = 10000000;
        for (int incr = 0; incr < 50; incr++) {
            int a = aa;
            int b = bb;
            int out = incr;
            b += incr;
            if (b == 1) {
                b = 2;
                out++;
            }

            while (a > 0) {
                a /= b;
                out++;
            }
            outt = min(outt, out);
        }
        cout << outt << endl;
    }
}