#include<bits/stdc++.h>
#define int long long
using namespace std;
int parent[200005];
int finder(int x)
{if(x==parent[x]){return x;}
 int j=finder(parent[x]);
 parent[x]=j;
 return j;
}
void Union(int a,int b)
 {int x=finder(a);
  int y=finder(b);
  if(x==y){return;}
  parent[x]=y;
  return;
 }
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin>>t;
 while(t--)
    {int n,m,k;
     cin>>n>>m>>k;
     vector<pair<int,int>>adj[n];
     vector<tuple<int,int,int>> op;
     int u,v,w;
     for(int i=0;i<m;i++)
        {cin>>u>>v>>w;
         u--;
         v--;
         op.push_back(make_tuple(w,v,u));
         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));
        }
    sort(op.begin(),op.end());
    int visited[n];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0]=1;
    int maxa=0;
    for(int i=0;i<n;i++){parent[i]=i;}
    while(!q.empty())
        {int z=q.front();
         for(auto x:adj[z])
            {if(visited[x.first]==0 && x.second<=k)
               {visited[x.first]=1;
                q.push(x.first);
                maxa=max(maxa,x.second);
               }
            }
        q.pop();
        }
    //for(int i=0;i<n;i++){cout<<parent[i]<<" ";}cout<<"\n";
    int poss=1;
    int mina=1e17;
    for(int i=0;i<n;i++)
        {if(visited[i]==0){poss=0;break;}
        }
    //cout<<poss<<" "<<maxa<<"\n";
    if(poss)
        {for(auto x:op)
          {
            int w=(get<0>)(x);
            if(w<=k){mina=min(mina,k-w);}
            }
        }
    int ans=0;
    int done=0;
    for(auto x:op)
        {int w=(get<0>)(x);
         int u=(get<1>)(x);
         int v=(get<2>)(x);
         if(finder(u)!=finder(v) && w<=k)
            {Union(u,v);
            }
        }
    for(auto x:op)
        {int w=(get<0>)(x);
         int u=(get<1>)(x);
         int v=(get<2>)(x);
         if(finder(u)!=finder(v))
            {ans+=(w-k);Union(u,v);done=1;
             //cout<<u<<" "<<v<<"\n";
            }
        }
    if(done){mina=min(mina,ans);}
    if(done==0)
        {int lol=1e17;
         for(auto x:op)
            {int w=(get<0>)(x);
            if(w>=k){lol=min(lol,w-k);}
            }
        mina=min(mina,lol);
        }
    cout<<mina<<"\n";
    }
}