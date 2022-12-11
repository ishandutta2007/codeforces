#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main()
{

    int n, d;
    cin >> n >> d;

    int t[120];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int t0 = 0;
    for (int i = 0; i < n; i++)
    {
        t0 += t[i];
        if (i < n - 1) t0 += 10;
    }

    if (t0 > d) {cout << "-1"; return 0;}

    int kol = (n - 1) * 2;
    while (1)
    {
        if (t0 + 5 <= d)
        {
            t0 += 5;
            ++kol;
        }

        else break;
    }

    cout << kol;

}