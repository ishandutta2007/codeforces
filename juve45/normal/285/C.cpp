#include <bits/stdc++.h>

using namespace std;

long long n, p[300009];

long long abso(long long k)
{
    if(k<0)
        return -k;
    return k;
}

int main()
{
cin>>n;

for(long long i=1;i<=n;i++)
    cin>>p[i];

sort(p+1, p+n+1);
long long ans=0;
for(long long i=1;i<=n;i++)
    ans+=abso(p[i]-i);

cout<<ans;

    return 0;
}