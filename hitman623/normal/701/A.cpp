#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,s=0,a[100],i,b[100],j,m;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>a[i];b[i]=a[i];}
    sort(a,a+n);
    for(i=0;i<n;++i)
    {   if(b[i]==0) continue;
        cout<<i+1;
        m=n-(upper_bound(a,a+n,b[i])-a);
        for(j=i+1;j<n;++j)
        {
            if(b[j]==a[m])
            {cout<<" "<<j+1<<endl;b[j]=0;break;}
        }
    }
    return 0;
}