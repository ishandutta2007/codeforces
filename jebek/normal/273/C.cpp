#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstdio>

using namespace std;

typedef pair<int,int> pii;
set<pii>s;
int n,m,d[400000],ans[400000];
vector<int>G[400000];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int v,u;
        scanf("%d %d",&v,&u);
        G[v].push_back(u);
        G[u].push_back(v);
        d[v]++;
        d[u]++;
    }
    for(int i=1;i<=n;i++)
        s.insert(pii(d[i],i));
    while(1)
    {
        int i=(--s.end())->second;
        s.erase(--s.end());
        if(d[i]<=1)
            break;
        d[i]=3-d[i];
        ans[i]=1-ans[i];
        for(int j=0;j<G[i].size();j++)
        {
            s.erase(pii(d[G[i][j]],G[i][j]));
            if(ans[G[i][j]]==ans[i])
                d[G[i][j]]++;
            else
                d[G[i][j]]--;
            s.insert(pii(d[G[i][j]],G[i][j]));
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d",ans[i]);
    printf("\n");
}