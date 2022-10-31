// Hydro submission #625921b437de167dd82bd3ba@1650008500907
#include<bits/stdc++.h>
using namespace std;
int a[50],b[50],s;
bool f[1000];
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=n-1;i+1;i--)
    if(!f[a[i]-1])
    b[s]=a[i],s++,
    f[a[i]-1]=true;
    printf("%d\n",s);
    for(i=s-1;i+1;i--)
    printf("%d ",b[i]);
    cout<<endl;
    return 0;
}