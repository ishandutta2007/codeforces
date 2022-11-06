#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    for (int i = 0; i <= min(a, b); i++)
    {
        if (a - i + b - i == c)
        {
            cout << i << ' ' << b - i << ' ' << a - i << endl;
            return 0;
        }
    }
    
    puts("Impossible");
    
    return 0;
}