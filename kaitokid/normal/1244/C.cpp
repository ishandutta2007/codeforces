    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    int main()
    {
     ios::sync_with_stdio(0);
    ll n,p,w,d;
    cin>>n>>p>>w>>d;

    ll q=100090;
    q=min(q,n);
    for(ll i=0;i<=q;i++)
    {
    if(p%w==0)
    {
    if((i+p/w)>n){cout<<-1;return 0;}
    cout<<p/w<<" "<<i<<" "<<n-(p/w)-i;
    return 0;
    }
    p-=d;
    if(p<0)break;
    }
     cout<<-1;
        return 0;
    }