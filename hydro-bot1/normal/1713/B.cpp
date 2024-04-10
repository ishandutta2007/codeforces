// Hydro submission #62fb465a4b7288bafe609cad@1660634715125
#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int t,n,p,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        for(p=1;p<n&&a[p]<=a[p+1];p++);
        for(s=1;s<n&&a[n-s]>=a[n-s+1];s++);
        printf(p+s<n?"NO\n":"YES\n");
    }
    return 0;
}