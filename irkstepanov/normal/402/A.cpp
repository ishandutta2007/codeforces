#include <iostream>

using namespace std;

int main()
{

    int k, a, b, v, n, i;

    cin >> k >> a >> b >> v;

    for (n = 1; n <= 1200; n++)
    {
        int ots = 0, bnew = b;
        for (i = 1; i <= n; i++)
        {
            if (bnew >= k - 1) {ots += k; bnew -= (k - 1);}
            else {ots += (bnew + 1); bnew = 0;}
        }
        if (ots * v >= a) {cout << n; return 0;}
    }

}