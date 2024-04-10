#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    vector <long long> a;
    long long n,ni;
    cin>>n;
    ni=n;
    for (long long i=2;i<=sqrt(n);i++)
    {
        if (ni%i==0)
        {
            ni/=i;
            a.push_back(i);
        }
        while (ni%i==0)
        {
            ni/=i;
        }
    }


    if (ni!=1)
        a.push_back(ni);
    long long ans=1;
    for (long long i=0;i<a.size();i++)
     {
        ans*=a[i];
     }
     cout<<ans;
    return 0;
}