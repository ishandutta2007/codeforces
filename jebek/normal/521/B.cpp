#include <iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>

using namespace std;

const int MOD=1000000009;
typedef long long ll;
typedef pair<int,int> pii;
map<pii,int>m;
ll n,p[200000],x[200000],y[200000],ans;
set<int>s,G[200000],G1[200000];

void ok(int v)
{
    if(G1[v].size()==1)
        s.erase(*(G1[v].begin()));
}

int main()
{
    cin>>n;
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=(p[i-1]*n)%MOD;
        s.insert(i);
        cin>>x[i]>>y[i];
        m[pii(x[i],y[i])]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(y[i]==0)
            continue;
        int v=m[pii(x[i]-1,y[i]-1)];
        if(v)
        {
            G[v].insert(i);
            G1[i].insert(v);
        }
        v=m[pii(x[i],y[i]-1)];
        if(v)
        {
            G[v].insert(i);
            G1[i].insert(v);
        }
        v=m[pii(x[i]+1,y[i]-1)];
        if(v)
        {
            G[v].insert(i);
            G1[i].insert(v);
        }
    }
    for(int i=1;i<=n;i++)
        if(G1[i].size()==1)
            s.erase(*(G1[i].begin()));
    for(int i=0;i<n;i++)
    {
        int v;
        if(i%2==0)
        {
            v=*(--s.end());
            s.erase(--(s.end()));
        }
        else
        {
            v=*(s.begin());
            s.erase(s.begin());
        }
        ans=(ans+(v-1)*p[n-i-1])%MOD;
        s.erase(v);
        while(G[v].size())
        {
            int u=*(G[v].begin());
            G[v].erase(G[v].begin());
            G1[u].erase(v);
            ok(u);
        }
        while(G1[v].size())
        {
            int u=*(G1[v].begin());
            G1[v].erase(G1[v].begin());
            G[u].erase(v);
            s.insert(u);
            set<int>::iterator it=(G[u].begin());
            while(it!=G[u].end())
            {
                ok(*it);
                it++;
            }
        }
    }
    cout<<ans<<endl;
}