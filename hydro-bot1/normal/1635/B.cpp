// Hydro submission #62ef22ef74879b352565dcea@1659839215630
#include<bits/stdc++.h>
using namespace std;
int a[200002];
int main()
{
    int t,n,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n;s=0;
        for(i=1;i<=n;i++)
        cin>>a[i];
        for(i=2;i<n;i++)
        if(a[i]>max(a[i-1],a[i+1]))
        a[i+1]=max(a[i],a[i+2]),s++;
        printf("%d\n",s);
        for(i=1;i<=n;i++)
        printf("%d ",a[i]);
        cout<<endl;
    }
    return 0;
}