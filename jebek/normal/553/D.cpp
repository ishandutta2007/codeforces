#include <iostream>
#include<algorithm>
#include<set>
#include<vector>
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef pair<int,int> pii;
typedef long double ld;

const int MAXN=200000;
int n,m,k,ind,t[MAXN];
ld MAX,now;
bool mark[MAXN];
vector<int>G[MAXN],ans;
set<pair<ld,int> >s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        int v;
        cin>>v;
        mark[v]=true;
    }
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            for(int j=0;j<G[i].size();j++)
                if(!mark[G[i][j]])
                    t[i]++;
            s.insert(MP((ld)t[i]/(ld)G[i].size(),i));
        }
    while(s.size())
    {
        int v=s.begin()->Y;now=s.begin()->X;
        if(now>=MAX)
            MAX=now,ind=s.size();
        s.erase(s.begin());
        mark[v]=true;
        ans.push_back(v);
        for(int i=0;i<G[v].size();i++)
            if(!mark[G[v][i]])
            {
                int u=G[v][i];
                s.erase(MP((ld)t[u]/(ld)G[u].size(),u));
                t[u]--;
                s.insert(MP(((ld)t[u]/(ld)G[u].size()),u));
            }
    }
    cout<<ind<<endl;
    for(int i=0;i<ind;i++)
        cout<<ans[ans.size()-i-1]<<" ";
    cout<<endl;
}