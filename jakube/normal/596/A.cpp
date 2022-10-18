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

    int n, x, y, max_x, min_x, max_y, min_y;
    cin >> n;

    FOR(i, n)
    {
        cin >> x >> y;
        if (i == 0)
        {
            max_x = x;
            min_x = x;
            max_y = y;
            min_y = y;
        }
        else
        {
            max_x = max(x, max_x);
            min_x = min(x, min_x);
            max_y = max(y, max_y);
            min_y = min(y, min_y);
        }
    }

    int area = (max_x - min_x) * (max_y - min_y);
    if (area)
        cout << area;
    else
        cout << -1;

}