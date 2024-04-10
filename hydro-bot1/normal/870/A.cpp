// Hydro submission #62591c15cc64917dc4664ff5@1650007061712
#include<bits/stdc++.h>
using namespace std;
int a[9],b[9];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<m;i++)
    cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    if(a[i]==b[j])
    {
        printf("%d\n",a[i]);
        return 0;
    }
    printf("%d%d\n",min(a[0],b[0]),max(a[0],b[0]));
    return 0;
}