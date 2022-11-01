#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[100000],p[100000],pmin[100000],sum;
    for (int i=0;i<n;i++)
    pmin[i]=200;
    for (int i=0;i<n;i++)
    {
        cin>>a[i]>>p[i];
        sum+=a[i];
        if (i==0)
        pmin[i]=p[i];
        else
        {
            pmin[i]=min(p[i],pmin[i-1]);
        }

    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        ans+=a[i]*pmin[i];
    }
    cout<<ans;
    return 0;
}