#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
const ld eps = 0.0000001;
const ld pi = 4 * atan(1.0);

bool geq (ld a, ld b)
{
    return (a - b >= eps || abs(a - b) <= eps);
}

int main()
{

    int n;
    ld l, r;

    cin >> n >> l >> r;

    vector <ld> x(1 << n), y(1 << n), alpha(1 << n);

    vector <ld> ans(1 << n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> alpha[i];
        alpha[i] *= pi / 180.0;
    }

    ans[0] = l;

    for (int mask = 1; mask < (1 << n); mask++)
    {
        ans[mask] = l;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                int j = mask ^ (1 << i);
                ld dx = ans[j] - x[i], dy = 0 - y[i];
                ld dxnew = cos(alpha[i]) * dx - sin(alpha[i]) * dy;
                ld dynew = sin(alpha[i]) * dx + cos(alpha[i]) * dy;
                dx = dxnew;
                dy = dynew;
                if (geq(dy, 0)) ans[mask] = r;
                else ans[mask] = max(ans[mask], min(x[i] - y[i] * dx / dy, r));
            }
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << ans[(1 << n) - 1] - l;

}