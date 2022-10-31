// Hydro submission #6274c873bda16328ffbaf5db@1651820659604
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n,i;
    cin>>n;
    if(n>44)
    {
        printf("YES\n");
        return 0;
    }
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=2;i<n;i++)
    if(a[i-2]+a[i-1]>a[i])
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}