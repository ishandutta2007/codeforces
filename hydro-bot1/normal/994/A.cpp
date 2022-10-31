// Hydro submission #625922fe37de167dd82bd739@1650008840636
#include<bits/stdc++.h>
using namespace std;
int x[10],y[10];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    cin>>x[i];
    for(j=0;j<m;j++)
    cin>>y[j];
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    if(x[i]==y[j])
    printf("%d ",x[i]);
    return 0;
}