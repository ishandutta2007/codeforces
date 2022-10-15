#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a[n],ans,bigst=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        long long int total=a[i],smlst=a[i];
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<smlst) smlst=a[j];
            total+=smlst;
        }
        smlst=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<smlst) smlst=a[j];
            total+=smlst;
        }
        if(total>bigst)
        {
            bigst=total;
            ans=i;
        }
    }
    long long int smlst=a[ans];
    for(int j=ans-1;j>=0;j--)
    {
        if(a[j]<smlst) smlst=a[j];
        a[j]=smlst;
    }
    smlst=a[ans];
    for(int j=ans+1;j<n;j++)
    {
        if(a[j]<smlst) smlst=a[j];
        a[j]=smlst;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}