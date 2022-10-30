#include <iostream>

using namespace std;

long long n,k,a,ans,t[10000];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        t[a]++;
    }
    for(int i=2;i<=2000;i++)
    {
        ans+=2*((n+k-1)/k);
        n-=t[i];
    }
    cout<<ans<<endl;
}