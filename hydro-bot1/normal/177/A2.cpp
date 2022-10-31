// Hydro submission #6253c54248f7830132791cc1@1649657154851
#include<bits/stdc++.h>
using namespace std;
int a[101][101],s;
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    for(i=0;i<n;i++)
    s+=a[i][n-i-1]+a[i][i]+a[n/2][i]+a[i][n/2];
    s-=3*a[n/2][n/2];
    printf("%d\n",s);
    return 0;
}