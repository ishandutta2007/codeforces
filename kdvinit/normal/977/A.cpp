#include <iostream>

using namespace std;

int main()
{
   long long int n,k;
    cin >> n >> k;
    long long int a = n;
    int b = k;
    while(b>0)
    {
        while (a%10!=0)
        {
            if (b>0)
            {
                a--;
                b--;
            }
            else break;
        }
        while (a%10==0)
        {
            if (b>0)
            {
                a=a/10;
                b--;
            }
            else break;
        }
    }

    cout << a;
    return 0;
}