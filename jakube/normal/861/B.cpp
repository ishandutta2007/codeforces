#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int fmin = 1, fmax = 1000;
    while (m-- > 0) {
        int k, f;
        cin >> k >> f;
        // flats * (f - 1) + 1 <= k <= flats * f
        // ==>
        // flats <= (k - 1) / (f - 1)
        // flats >= k / f

        fmin = max(fmin, (k + f - 1) / f);
        if (f > 1) {
            fmax = min(fmax, (k - 1) / (f - 1));
        }
    }

    int assuming_low = (n + fmin - 1) / fmin;
    int assuming_high = (n + fmax - 1) / fmax;
    if (assuming_low == assuming_high)
        cout << assuming_low << endl;
    else
        cout << -1 << endl;
}