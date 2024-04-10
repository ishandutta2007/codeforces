#include <bits/stdc++.h>

using namespace std;
long long a[100005];
int main()
{
    long n,i;
    long long br=0,x,k,b1,b,d,v,k1;
    cin>>n>>x>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++){
    k1=k;
    if(a[i]%x==0)k1--;
    b=(a[i]-a[i]%x)+x*k1;
    b1=b+x-1;
    b=max(b,a[i]);
    d=lower_bound(a,a+n,b)-a;
    v=upper_bound(a,a+n,b1)-a;
    if(v>=d)br+=v-d;
    }
    cout<<br;
    return 0;
}