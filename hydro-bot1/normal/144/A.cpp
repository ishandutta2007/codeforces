// Hydro submission #6253c2c3ca530601467159a3@1649656516256
#include<bits/stdc++.h>
using namespace std;
int a[100],mx,mn;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>a[mx]) mx=i;
        if(a[i]<=a[mn]) mn=i;
    }
    if(mx<mn)
    printf("%d\n",mx-mn+n-1);
    else
    printf("%d\n",mx-mn+n-2);
    return 0;
}