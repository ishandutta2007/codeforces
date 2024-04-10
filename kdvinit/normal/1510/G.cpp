#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> adj[105];
map<int,int> ok;
vector<int> ans;
int req;
void DFS(int v,int par)
{
    ans.push_back(v);
    if(ok.find(v)==ok.end())
        {req--;
        }
    //cout<<v<<" "<<req<<"\n";
    int done=0;
    int on_path=-1;
    for(auto x:adj[v])
        {if(x==par){continue;}
        if(ok.find(x)!=ok.end()){on_path=x;continue;}
        if(req>0)
            {DFS(x,v);
             done=1;
             ans.push_back(v);
            }
        }
    /*if(done)
    {ans.push_back(v);}*/
    if(on_path>=0){DFS(on_path,v);}
}
int32_t main()
{
ios::sync_with_stdio(0);
 cin.tie(0);
int t;
cin>>t;
while(t--)
    {int n,k;
     cin>>n>>k;
     ok.clear();
     ans.clear();
     for(int i=0;i<n;i++){adj[i].clear();}
     for(int i=0;i<n-1;i++)
        {int u,v;
         cin>>u;
         v=i+2;
         u--;
         v--;
         adj[u].push_back(v);
         adj[v].push_back(u);
        }
    int visited[n];
    int dist[n];
    int parent[n];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(0);
    parent[0]=-1;
    visited[0]=1;
    dist[0]=0;
    while(!q.empty())
        {int a=q.front();
         for(auto x:adj[a])
            {if(visited[x]==0)
                {q.push(x);
                 visited[x]=1;
                 dist[x]=dist[a]+1;
                 parent[x]=a;
                }
            }
        q.pop();
        }
    int maxa=0;
    int index=0;
    for(int i=0;i<n;i++)
        {if(dist[i]>maxa){index=i;maxa=dist[i];}
        }
    vector<int> path;
    while(index!=-1)
        {path.push_back(index);
         index=parent[index];
        }
    reverse(path.begin(),path.end());
    if(k-1<=maxa)
        {cout<<k-1<<"\n";
         for(int i=0;i<k;i++)
            {cout<<path[i]+1<<" ";
            }cout<<"\n";
         continue;
        }
    else
        {cout<<maxa+2*(k-1-maxa)<<"\n";
        }
    for(auto x:path)
        {ok[x]=1;
        }
    req=k-1-maxa;
    DFS(0,-1);
    assert(ans.size()==(maxa+2*(k-1-maxa)+1));
    for(auto x:ans){cout<<x+1<<" ";}
    cout<<"\n";
    }
}