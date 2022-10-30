#include <iostream>

using namespace std;

long long n,t,ans,a[200000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    t=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            t++;
        else
        {
            ans+=t*(t+1)/2;
            t=1;
        }
    }
    ans+=t*(t+1)/2;
    cout<<ans<<endl;
}