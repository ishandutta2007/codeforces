#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c,m;
//ll pr[300009];
ll mx[2000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    //vector<pair<ll,ll> >v;
    for(int i=0;i<n;i++)
    {
        ll u,d,h;
        cin>>u>>d>>h;
        mx[u]=max(mx[u],d*h);
    }

    for(int i=1;i<=c;i++)
    {
        if(mx[i]==0)continue;
        for(int j=2;j*i<=c;j++)
            mx[i*j]=max(mx[i*j],j*mx[i]);
    }
    for(int i=1;i<=c;i++)mx[i]=max(mx[i],mx[i-1]);
   /* sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
        pr[i]=max(v[i].second,pr[i+1]);
    */
    cin>>m;
    while(m--)
    {
        ll d,h;
        cin>>d>>h;
        d*=h;
        if(mx[c]<=d){cout<<-1<<" ";continue;}
        int u=(upper_bound(mx,mx+c+1,d)-mx);
        cout<<u<<" ";
    }

}