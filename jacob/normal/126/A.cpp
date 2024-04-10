#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll t1, t2, x1, x2, t0;

ll bestCandP, bestCandQ;
ll my1, my2;

void CheckCand(ll py1, ll py2) {
    if (py1 == 0 && py2 == 0) return;
    if (py2 < 0 || py2 > x2) return;
    ll cP = t0 * (py1 + py2) - t1 * py1 - t2 * py2;
    if (cP > 0) return;
    cP = -cP;
    ll cQ = py1 + py2;
    if (cP * bestCandQ < cQ * bestCandP) {
        bestCandP = cP;
        bestCandQ = cQ;
        my1 = py1;
        my2 = py2;
    } else if (cP * bestCandQ == cQ * bestCandP) {
        if (my1 + my2 <= py1 + py2) {
            bestCandP = cP;
            bestCandQ = cQ;
            my1 = py1;
            my2 = py2;
        }
    }
}

int main(void) {
    bestCandP = ll(1e+6);
    bestCandQ = 0;
    my1 = my2 = 0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t2 == t0) {
        cout <<  ((t1 == t0) ? x1 : 0) << " " << x2 << endl;
        return 0;
    }
    for (ll f = 0; f <= x1; f++) {
        // t0 * (f + x) = t1 * f + t2 * x
        ll c = t2 - t0;
        ll r = (t0 - t1) * f;
        CheckCand(f, r / c);
        CheckCand(f, 1 + r / c);
        CheckCand(f, 0);
        CheckCand(f, x2);
    }
    cout << my1 << " " << my2 << endl;
    return 0;
}