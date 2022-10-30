// Hydro submission #625cea2681ef68d42bcba8c3@1650256423586
#include<bits/stdc++.h>
using namespace std;
int c[1000],a[1000],s;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    cin>>c[i];
    for(j=0;j<m;j++)
    cin>>a[j];i=0;
    for(j=0;j<m&&i<n;j++)
    if(a[j]<c[i])
    i++,j--;
    else i++,s++;
    printf("%d\n",s);
    return 0;
}