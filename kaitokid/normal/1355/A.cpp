#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        k--;
        while(k--)
        {
            ll u=9,v=0;
            ll d=n;
            while(d>0){u=min(u,d%10);v=max(v,d%10);d/=10;}
            if(u==0)break;
            n+=u*v;
                    }
cout<<n<<endl;
    }
    return 0;
}