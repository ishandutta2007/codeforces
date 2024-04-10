// Hydro submission #62590cd937de167dd82bb123@1650003170251
#include<bits/stdc++.h>
using namespace std;
int a[2200];
int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=1;i<k;i++)
    a[0]+=a[i];
    printf("%d\n",a[0]);
    return 0;
}