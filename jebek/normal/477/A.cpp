#include <iostream>
#include<algorithm>

using namespace std;

const long long MOD=1000000007;
long long pow(long long a,long long b)
{
    long long c=1;
    while(b)
    {
        if(b%2)
            c=(c*a)%MOD;
        b=b/2;
        a=(a*a)%MOD;
    }
    return c;
}

int main()
{
    long long a,b,ans;
    cin>>a>>b;
    ans=(b*b-b)%MOD;
    ans=(ans*((2*a+((a*(a+1))%MOD)*b)%MOD)%MOD)%MOD;
   // cout<<ans<<endl;
    //cout<<ans<<endl;
    cout<<(ans*pow(4,MOD-2))%MOD<<endl;
}