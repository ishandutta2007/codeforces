#include <iostream>
#include <string>

using namespace std;

int main()
{

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % a == 0) ++ans;
        else if (i % b == 0) ++ans;
        else if (i % c == 0) ++ans;
        else if (i % d == 0) ++ans;
    }

    cout << ans;

}