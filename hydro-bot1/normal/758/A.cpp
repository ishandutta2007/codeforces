// Hydro submission #62550f62ac286d0a56b87101@1649741667042
#include<bits/stdc++.h>
using namespace std;
int a[100],s;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    s+=a[n-1]-a[i];
    printf("%d\n",s);
    return 0;
}