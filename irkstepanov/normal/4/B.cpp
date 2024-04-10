#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

int main()
{

    int n, sum;
    cin >> n >> sum;

    int a[50], b[50];
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sa += a[i];
        sb += b[i];
    }

    if (sa > sum || sb < sum) {cout << "NO"; return 0;}
    cout << "YES\n";

    int add = sum - sa;

    for (int i = 0; i < n; i++)
    {
        if (add + a[i] <= b[i])
        {
            cout << a[i] + add << " ";
            add = 0;
        }
        else
        {
            cout << b[i] << " ";
            add -= (b[i] - a[i]);
        }
    }

}