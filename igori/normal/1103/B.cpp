const int N = 999999;

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ask(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    char t;
    cin >> t;
    if (t == 'x') return 0;
    return 1;
}

void solve()
{
    int z = ask(0, 1);
    if (z == 0)
    {
        cout << "! 1" << endl;
        return;
    }
    int L = 1, R = 2;
    while (1)
    {
        int t = ask(L, R);
        if (t == 0) break;
        L *= 2, R *= 2;
    }
    int b = L;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        int z = ask(b, M);
        if (z == 0) R = M;
        else L = M;
    }
    cout << "! " << R << endl;
}

signed main()
{
    while (1)
    {
        string s;
        cin >> s;
        if (s == "start") solve();
        else return 0;
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/