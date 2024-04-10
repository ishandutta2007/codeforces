#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

ll n, a, x, b, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> x >> b >> y;
    int g1 = 1, g2 = -1;
    while (1)
    {
        if (a == b)
        {
            cout << "YES";
            return 0;
        }
        if (a == x || b == y)
            break;
        a += g1, b += g2;
        if (a == n + 1)
            a = 1;
        if (b == 0)
            b = n;
        if (a == b)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}