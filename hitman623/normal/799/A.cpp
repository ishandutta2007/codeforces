#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,t,k,d,t1,t2,i;
    cin>>n>>t>>k>>d;
    t1=t*(n/k+!!(n%k));
    for(t2=0;t2<2e6;++t2)
    {
        if(k*(t2/t)+k*((t2-d)/t)>=n)
        break;
    }
    if(t1<=t2) cout<<"NO";
    else cout<<"YES";
    return 0;
}