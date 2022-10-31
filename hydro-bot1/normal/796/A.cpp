// Hydro submission #62590c9437de167dd82bb0a4@1650003092939
#include<bits/stdc++.h>
using namespace std;
int a[100],s;
int main()
{
    int n,m,k,i,t=999;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    if(a[i]&&a[i]<=k)
    t=min(t,abs(i-m+1)*10);
    printf("%d\n",t);
    return 0;
}