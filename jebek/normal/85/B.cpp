#include <iostream>
#include<algorithm>

using namespace std;

long long t1,n,t2,t3,a[200000],b[200000],ans;
int n1,n2,n3;

int main()
{
    cin>>n1>>n2>>n3>>t1>>t2>>t3;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    b[0]=a[0]+t1;
    for(int i=1;i<n;i++)
    {
        if(i>=n1)
            b[i]=max(b[i-n1],a[i])+t1;
        else
            b[i]=a[i]+t1;
    }
    b[0]=b[0]+t2;
    for(int i=1;i<n;i++)
    {
        if(i>=n2)
            b[i]=max(b[i-n2],b[i])+t2;
        else
            b[i]=b[i]+t2;
    }
    b[0]=b[0]+t3;
    for(int i=1;i<n;i++)
    {
        if(i>=n3)
            b[i]=max(b[i-n3],b[i])+t3;
        else
            b[i]=b[i]+t3;
    }
    for(int i=0;i<n;i++)
        ans=max(ans,b[i]-a[i]);
    cout<<ans<<endl;
}