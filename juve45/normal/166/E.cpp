#include <iostream>
#define mod 1000000007
using namespace std;

int solve(int k)
{
    long long nd=1, nabc=0;
    for(int i=1;i<=k;i++)
    {
        long long d=nd;
        nd=nabc;
        nabc=(3LL*d+2LL*nabc)%mod;
    }
return nd;

}

int n;
int main()
{
    cin>>n;
    cout<<solve(n);

    return 0;
}