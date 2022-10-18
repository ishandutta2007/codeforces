#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int a[3], b[3];
    FOR(i, 3)
        cin >> a[i];
    FOR(i, 3)
        cin >> b[i];

    int t = 0;
    FOR(i, 3)
        a[i] -= b[i];

    FOR(i, 3) {


        sort(a, a + 3);

        if (a[0] >= 0) {
            cout << "Yes";
            return 0;
        }

        if (a[2] <= 0) {
            cout << "No";
            return 0;
        }

        t = min(-a[0], a[2] / 2);
        a[0] += t;
        a[2] -= 2 * t;

    }


    sort(a, a+3);

    if (a[0] >= 0)
        cout << "Yes";
    else
        cout << "No";
}