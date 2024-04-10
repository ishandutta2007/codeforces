// Hydro submission #629fdb6ae4e138563ac4b2c9@1654643562491
#include<bits/stdc++.h>
using namespace std;
int w[3],v[3],f[4001];
int main()
{
    int m,i,j;
    cin>>m;
    for(i=0;i<3;i++)
    cin>>w[i];f[0]=1;
    for(i=0;i<3;i++)
    for(j=w[i];j<=m;j++)
    if(f[j-w[i]]) f[j]=max(f[j],f[j-w[i]]+1);
    printf("%d\n",f[m]-1);
    return 0;
}