#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
int main()
{
    long long ans=0;
    cin>>n>>a>>b>>c;
    if(a<(b-c))
        ans=n/a;
    else{
        ans+=(n-c)/(b-c);
        ans=max(ans,0LL);
        n-=ans*(b-c);
        ans+=n/a;
    }

    cout<<max(ans, 0LL)<<'\n';
    return 0;
}