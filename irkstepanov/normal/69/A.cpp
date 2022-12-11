#include <iostream>
#include <string>

using namespace std;

int main()
{

    int X = 0, Y = 0, Z = 0;
    int n;
    cin >> n;

    while (n--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        X += x, Y += y, Z += z;
    }

    cout << ((!X && !Y && !Z) ? "YES" : "NO");

}