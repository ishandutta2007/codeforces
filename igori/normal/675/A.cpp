#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (c == 0 && a == b)
    {
        cout << "YES";
        return 0;
    }
    int w = b - a;
    if ((w >= 0 && w % c == 0 && c > 0) || (w <= 0 && w % c == 0 && c < 0))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}