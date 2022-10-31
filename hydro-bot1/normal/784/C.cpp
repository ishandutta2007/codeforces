// Hydro submission #625909f4cc64917dc46641cf@1650002430808
#include<bits/stdc++.h>
using namespace std;
int a[10],s;
int main()
{
    int n,i;cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    s=a[n-1];
    sort(a,a+n);
    s^=a[n-1];
    printf("%d\n",s);
    return 0;
}