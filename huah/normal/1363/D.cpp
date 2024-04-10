#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int res[N];
char s[N];
bool vis[N];
vector<int>v[N],q;
int query()
{
    printf("? %d\n",q.size());
    for(int i=0;i<q.size();i++) printf(i==q.size()-1?"%d\n":"%d ",q[i]);
    fflush(stdout);
    int x;scanf("%d",&x);
    return x;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,k,f;scanf("%d%d",&n,&k);f=k;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=k;i++)
        {
            v[i].clear();
            int x;scanf("%d",&x);
            while(x--)
            {
                int y;scanf("%d",&y);v[i].push_back(y);vis[y]=true;
            }
        }
        v[k+1].clear();
        for(int i=1;i<=n;i++) if(!vis[i]) v[k+1].push_back(i);
        if(v[k+1].size()) k++;
        q.clear();
        for(int i=1;i<=n;i++) q.push_back(i);
        int mx=query(),ans=k;
        for(int i=1<<9;i;i>>=1)
            if(ans-i>=1)
            {
                q.clear();
                for(int j=1;j<=ans-i;j++)
                    q.insert(q.end(),v[j].begin(),v[j].end());
                if(query()==mx) ans-=i;
            }
        q.clear();
        for(int i=1;i<=k;i++)
        {
            res[i]=mx;
            if(i!=ans) q.insert(q.end(),v[i].begin(),v[i].end());
        }
        res[ans]=query();
        printf("! ");
        for(int i=1;i<=f;i++)
            printf(i==f?"%d\n":"%d ",res[i]);
        fflush(stdout);
        scanf("%s",s);
        assert(s[0]=='C');
    }
}