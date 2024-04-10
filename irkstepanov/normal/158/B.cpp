#include <iostream>
#include <string>

using namespace std;

int main()
{

    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;
        if (x == 1) ++a1;
        if (x == 2) ++a2;
        if (x == 3) ++a3;
        if (x == 4) ++a4;
    }

    int ans = 0;
    ans += a4;
    ans += a3;
    a1 -= min (a1, a3);

    ans += (a2 / 2);
    a2 -= (a2 / 2) * 2;

    if (a2) {++ans; a2 = 0; a1 -= 2;}
    if (a1 > 0)
    {
        cerr << ans;
        ans += (a1 / 4);
        a1 -= (a1 / 4) * 4;
        if (a1) ++ans;
    }

    cout << ans;

}