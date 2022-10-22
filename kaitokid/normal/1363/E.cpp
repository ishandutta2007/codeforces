#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>v[200009];
ll n,a[200009],b[200009],c[200009],s1[200009],s2[200009];
ll ans;

void go(int pr,int x)
{
    if(x!=1)a[x]=min(a[x],a[pr]);

    for(int i=0;i<v[x].size();i++)
        {if(v[x][i]==pr)continue;
        go(x,v[x][i]);
        s1[x]+=s1[v[x][i]];
        s2[x]+=s2[v[x][i]];
        }
if(b[x]==0&&c[x]==1)s1[x]++;
if(b[x]==1&&c[x]==0)s2[x]++;
ll d=min(s1[x],s2[x]);
ans+=2*d*a[x];
s1[x]-=d;
s2[x]-=d;
}



int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    v[1].push_back(0);
    go(0,1);
    if(s1[1]!=0||s2[1]!=0)cout<<-1;
    else cout<<ans;
    return 0;
}