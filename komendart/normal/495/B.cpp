#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    
    if (a == b)
    {
        cout << "infinity" << endl;
    }
    else if (a < b)
    {
        cout << 0 << endl;
    }
    else
    {
        int result = 0, n = a - b;
        int i = 1;
        for (i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i > b)
                {
                    result += 1;
                }
                if (i * i != n && n > b * i)
                {
                    result += 1;
                }
            }
        }
        cout << result << endl;
    }
}