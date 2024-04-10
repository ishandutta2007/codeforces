#include <iostream>
#define dmax 100004
#define mod 1000000007
using namespace std;
int t, k, sol[dmax], a[dmax];
void pre()
{
    for(int i=0;i<k;i++)
        sol[i]=1;

    for(int i=k;i<dmax;++i)
    {
        sol[i]=(sol[i-1]+sol[i-k])%mod;
    }
}

void aib(){

for(int i=1;i<=dmax;i++)
a[i]=(a[i-1]+sol[i])%mod;

}

int main()
{
int x, y;
    cin>>t>>k;

    pre();
    aib();
    for(int i=1;i<=t;i++)
    {
        cin>>x>>y;
        int ans=a[y]-a[x-1];
        if (ans<0) ans=mod+ans;
        cout<<ans<<'\n';
    }

    return 0;
}