// Hydro submission #6259097ecc64917dc46640fe@1650002303112
#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    printf("%d\n",a[(n-1)/2]);
    return 0;
}