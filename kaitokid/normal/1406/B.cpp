#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll>a,b;

int main()
{
    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    a.clear();
    b.clear();
    int n;
    cin>>n;
    ll s=1,x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s*=x;
        if(x<0)b.push_back(x);
        else a.push_back(x);

    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    if(n==5){cout<<s<<endl;continue;}
    ll ans=-1e18;
    int q=b.size();
    if(a.size()==0)
    {
        ll v=1;
        for(int i=b.size()-1;i>b.size()-6;i--)v*=b[i];
        cout<<v<<endl;
        continue;
    }
    for(int i=0;i<min(5,q+1);i+=2)
    {
        int u=5-i;
        //cout<<i<<" "<<u<<endl;
        if(u>a.size())continue;

        ll v=1;
        for(int j=0;j<i;j++)v*=b[j];
        for(int j=0;j<u;j++)v*=a[j];
        ans=max(ans,v);
    }
    cout<<ans<<endl;
}
}