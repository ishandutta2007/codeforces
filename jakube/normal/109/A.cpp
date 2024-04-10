#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int best = -1;
    int a = 0;
    int b = 0;
    for (int i = 0; i * 7 <= n; i++)
    {
        int m = n - 7*i;
        if (m%4==0)
        {
            if (best < 0 || i + m/4 < best)
            {
                best = i + m/4;
                a = i;
                b = m/4;
            }
        }
        
    }
    
    if (best == -1)
        cout << -1;
    else
    {
        for (int i = 0; i < b; i++)
            cout << 4;
        for (int i = 0; i < a; i++)
            cout << 7;
    }
}