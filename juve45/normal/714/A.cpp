#include <iostream>

using namespace std;
long long l1, r1, l2, r2, k;
int main()
{
cin>>l1>>r1>>l2>>r2>>k;

long long l=max(l1, l2);
long long r=min(r1, r2);

if(l>r)
    cout<<0<<'\n';
else
{
    long long ans=r-l+1;
    if(l<=k && r>=k)
        ans--;
    cout<<ans<<'\n';
}


    return 0;
}