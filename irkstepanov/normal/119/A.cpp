#include <iostream>
#include <string>

using namespace std;

int gcd (int a, int b)
{
    if (a < b) swap (a, b);
    while (b)
    {
        a %= b;
        swap (a, b);
    }
    return a;
}

int main()
{

    int a, b, n;
    cin >> a >> b >> n;
    int pos = 0;

    while (n)
    {
        if (!pos) n -= gcd (n, a);
        else n -= gcd (n, b);
        pos = 1 - pos;
    }

    cout << 1 - pos;

}