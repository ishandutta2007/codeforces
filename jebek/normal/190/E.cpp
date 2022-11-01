#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>

using namespace std;

typedef pair<int,int> pii;
const int MAXN=600000;
int n,m,ind,t[MAXN];
vector<int>G[MAXN],ans[MAXN];
set<pii>s;
bool mark[MAXN];

void solve()
{
    while(s.size())
    {
        ans[ind].push_back(s.begin()->second);
        mark[s.begin()->second]=true;
        s.erase(s.begin());
        for(int i=0;s.size()>0 && (i<ans[ind].size() || (s.size()>0 && s.begin()->first<n-s.size()));)
        {
            if((s.begin()->first)<(n-s.size()-ans[ind].size()+i))
            {
                mark[s.begin()->second]=true;
                ans[ind].push_back(s.begin()->second);
                s.erase(s.begin());
            }
            else
            {
                int v=ans[ind][i];
                for(int j=0;j<G[v].size();j++)
                {
                    int u=G[v][j];
                    if(!mark[u])
                    {
                        s.erase(pii(t[u],u));
                        t[u]++;
                        s.insert(pii(t[u],u));
                    }
                }
                i++;
            }
        }
        ind++;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int v,u;
        scanf("%d %d",&v,&u);
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
       s.insert(pii(0,i));
    solve();
    printf("%d\n",ind);
    for(int i=0;i<ind;i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
}