#include <iostream>
#define MOD 1000000007
using namespace std;

long long a, b, sum;

int main()
{
    cin>>a>>b;

    for(long long i=1; i<b; i++)
    {
        sum+=(a*(a+1)/2)%MOD*b%MOD*i%MOD;
        sum+=(i*a)%MOD;
        sum=sum%MOD;
    }
    cout<<sum;
    return 0;
}