#include <bits/stdc++.h>

using namespace std;



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int c[5];
        for (int i = 1; i <= 3; i++)
            cin >> c[i];
        int a[7];
        for (int i = 1; i <= 5; i++)
            cin >> a[i];
        c[1] -= a[1];
        c[2] -= a[2];
        c[3] -= a[3];
        if (a[4] && c[1] > 0) {
            int tmp = min(a[4], c[1]);
            c[1] -= tmp;
            a[4] -= tmp;
        }
        if (a[5] && c[2] > 0) {
            int tmp = min (a[5], c[2]);
            c[2] -= tmp;
            a[5] -= tmp;
        }
        c[3] -= (a[5] + a[4]);
        bool no = false;
        for (int i = 1; i <= 3; i++)
            if (c[i] < 0) no = true;
        if (no) puts("NO");
        else puts("YES");
    }
    return 0;
}