// Hydro submission #6274d02f997df5291339db21@1651822640978
#include<bits/stdc++.h>
using namespace std;
int a[400001],s[400001];
int main()
{
    int t,n,i,j;
    long long m;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=1;j<=2*n;j++)
        s[j]=0;m=0;
        for(j=1;j<=n;j++)
        cin>>a[j],a[j]-=j;
        for(j=1;j<=n;j++)
        {
            m+=s[a[j]+n];
            s[a[j]+n]++;
        }
        printf("%lld\n",m);
    }
    return 0;
}