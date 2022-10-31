// Hydro submission #629fe6c1ab7be5564ecfd799@1654646466416
#include<bits/stdc++.h>
using namespace std;
int w[2],v[2],f[10001];
int main()
{
    memset(f,10000,sizeof(f));
    int a,b,s=10000,i,j;
    cin>>v[0]>>v[1]>>w[0]>>a>>b;
    f[0]=0,w[1]=1;
    for(i=0;i<2;i++)
    for(j=w[i];j<=10000;j++)
    f[j]=min(f[j],f[j-w[i]]+v[i]);
    for(i=max(w[0]*a-b,0);i<10001;i++)
    s=min(s,f[i]);
    printf("%d\n",s);
    return 0;
}