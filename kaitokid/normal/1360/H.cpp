#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,m;
vector<ll>k;
void f(ll x)
{
    for(ll i=m-1;i>=0;i--)
    {
        if(x&(1LL<<i))cout<<1;else cout<<0;
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
cin>>t;

while(t--)
{
    cin>>n>>m;
    k.clear();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        ll u=0,v=1;
        for(int i=0;i<m;i++)
        {
            if(s[i]=='1')u+=v;
            v*=2;
        }
        k.push_back(u);
    }
    sort(k.begin(),k.end());
    ll l=0,r=(1LL<<m)-1;
    ll p=(r-n)/2;
    while(r>=l)
    {

        ll mid=(l+r)/2;
    ll e=mid;
    vector<ll>::iterator it=lower_bound(k.begin(),k.end(),mid);

    e-=(it-k.begin());
    //cout<<l<<" "<<r<<" "<<mid<<" "<<e<<endl;
    if(e>p){r=mid-1;continue;}
    if(e<p){l=mid+1;continue;}
    if(it!=k.end()&&((*it)==mid)){l=mid+1;continue;}
    f(mid);
    break;
    }
}

    return 0;
}