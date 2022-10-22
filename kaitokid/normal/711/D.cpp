#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int n,d,r;

vector<int>v[200009];
int vis[200009];
ll p[200009];

void go(int x,int pr,int u)
{

    vis[x]=u;
    d++;
    bool bl=false;
    for(int i=0;i<v[x].size();i++)
    {
        if(bl==false&&v[x][i]==pr){bl=true;continue;}
     if(vis[v[x][i]]==0)   go(v[x][i],x,u+1);
     else if(r==0)r=u-vis[v[x][i]]+1;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    int x;
    p[0]=1;
    for(int i=1;i<200007;i++)p[i]=(p[i-1]*2)%mod;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        d=0;
r=0;
        go(i,0,1);
//cout<<i<<" "<<d<<" "<<r<<endl;
    ans=(ans*p[d-r])%mod;
    ans*=(p[r]-2);
    ans%=mod;
    }
    cout<<ans;
    return 0;
}