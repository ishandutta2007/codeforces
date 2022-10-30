// Hydro submission #62fb467c4b7288bafe609cfc@1660634749227
#include<bits/stdc++.h>
using namespace std;
bool f[200001];
int a[200001];
int main()
{
    int t,n,b,i;
    cin>>t;
    while(t--)
    {
        memset(f,false,sizeof(f));
        cin>>n;b=0;
        for(i=1;i<=n;i++)
        cin>>a[i];
        for(i=n;i>=1;i--)
        if(f[a[i]]) break;
        else f[a[i]]=true;
        printf("%d\n",i);
    }
    return 0;
}