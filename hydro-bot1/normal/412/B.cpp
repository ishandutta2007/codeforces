// Hydro submission #6253ddb448f7830132793554@1649663412420
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n); 
    printf("%d\n",a[n-k]);
    return 0;
}