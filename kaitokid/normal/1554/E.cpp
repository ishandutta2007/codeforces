#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int n;
vector<int>ed[100009];
vector<int> h;
int p[100009],ans[100009],q[100009];
void go(int x,int pr)
{
    p[x]=pr;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=pr)go(ed[x][i],x);
   if(x!=1) h.push_back(x);

}
bool ch(int x)
{
    for(int i=1;i<=n;i++)q[i]=0;
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        int u=h[i];
        if((q[u]%x)==0){q[p[u]]++;continue;}
        q[u]++;
        if((q[u]%x)!=0)return false;
    }
    if((q[1]%x)!=0)return false;
    for(int i=1;i<=n;i++)res=__gcd(res,q[i]);
    return (res==x);
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){ed[i].clear();ans[i]=0;}
        h.clear();
        ll res=1;
        for(int i=1;i<n;i++)
        {
            res=(res*2)%mod;
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        go(1,0);
        for(int i=2;i<=n;i++)
        {
            if((n-1)%i)continue;
            if(ch(i)){ans[i]=1;res=(res+mod-1)%mod;}

        }
        ans[1]=res;
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
         }
    return 0;
}