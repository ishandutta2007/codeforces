#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=200000;
bool mark[MAXN];
long long t[MAXN],h[MAXN],ans,MAX,q,x,y,k,p,n;
vector<int>G[MAXN];

void dfs(int v)
{
    mark[v]=true;
    t[h[v]]++;
    MAX=max(MAX,h[v]);
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            h[u]=h[v]+1;
            dfs(u);
        }
    }
}

int main()
{
    cin>>n>>k>>p;
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1);
    q=MAX;
    x=t[MAX];
   // y=t[MAX];
    for(int i=MAX;i>0;i--)
    {
       // cout<<i<<endl;
        while(q>1)
        {
            if(x+t[q-1]<=k && y+(i-q+1)*t[q-1]<=p)
            {
                y+=(i-q+1)*t[q-1];
                x+=t[q-1];
                q--;
            }
            else
                break;
        }
        //cout<<x<<" "<<y<<" "<<i<<" "<<q<<endl;
        if(q>i)
        {
            q=i+1;
            ans=max(ans,min(k,t[i]));
        }
        else if(q>1)
            ans=max(ans,min(k,x+(p-y)/(i-q+1)));
        else
            ans=max(ans,x);
        y-=x-t[i];
        x-=t[i];
    }
    cout<<ans<<endl;
}