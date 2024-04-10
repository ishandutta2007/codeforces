// Hydro submission #62592072cc64917dc4665368@1650008178569
#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{
    long long n,mn=1000000000000000000;
    int k,i;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>a[i];
        if(n%a[i]<mn)
        mn=n%a[i];
    }
    for(i=0;i<k;i++)
    if(n%a[i]==mn)
    {
        printf("%d %lld\n",i+1,n/a[i]);
        return 0;
    }
    return 0;
}