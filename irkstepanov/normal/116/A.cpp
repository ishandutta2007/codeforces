#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    int maxim = 0;
    int kol = 0;

    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        kol -= a;
        kol += b;
        maxim = max (maxim, kol);
    }

    cout << maxim;

}