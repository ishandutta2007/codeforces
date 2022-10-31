// Hydro submission #62592272cc64917dc4665736@1650008691781
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    printf("%d\n",a[n/2+n%2-1]);
    return 0;
}