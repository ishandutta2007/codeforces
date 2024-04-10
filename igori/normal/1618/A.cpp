#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, e, f, g;
        cin >> a >> b >> c >> d >> e >> f >> g;
        cout << a << " " << b << " " << g - a - b << "\n";
    }
}