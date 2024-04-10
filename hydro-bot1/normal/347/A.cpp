// Hydro submission #6253d2b148f7830132792891@1649660593948
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    printf("%d",a[n-1]);
    for(i=1;i<n-1;i++)
    printf(" %d",a[i]);
    printf(" %d\n",a[0]);
    return 0;
}