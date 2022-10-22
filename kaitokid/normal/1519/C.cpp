#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u[200009];
vector<ll> v[200009];
ll ans[200009];
ll pr[200009];
bool bl(ll x,ll y)
{
    return (x>y);
}
void go(int x)
{
    if(v[x].empty())return;
    int z=v[x].size();
    sort(v[x].begin(),v[x].end(),bl);
    pr[0]=0;
    for(int i=1;i<=z;i++)
        pr[i]=pr[i-1]+v[x][i-1];
    for(int i=1;i<=z;i++)
    {
        ll d=(z/i)*i;
       ans[i]+=pr[d];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>u[i];v[i].clear();ans[i]=0;}
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        v[u[i]].push_back(x);
    }

    for(int i=1;i<=n;i++)go(i);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
    return 0;
}