#include<bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}


int main()
{
    long long x;
    cin >> x;
    if(x == 1)
    {
        cout << "1 1";
        return 0;
    }
    long long ans1 = -1;
    long long ans2 = -1;
    for(long long i = 1; i * i < x; i++)
    {
        if(x % i == 0)
        {
            if(gcd(i, x / i) == 1)
            {
                ans1 = i;
                ans2 = x / i;
            }
        }
    }
    cout << ans1 << " " << ans2;
}