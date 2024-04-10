#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int n,m;
int dis[M],p[M],vis[M];
vector<int>g[M];
set<int>s;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
                p[v]=u;
            }
        }
    }
    if(dis[n]<=3&&dis[n]>=0){
        cout<<dis[n]<<"\n";
        int u=n;
        vector<int>b;
        while(dis[u])b.eb(u),u=p[u];
        cout<<1<<" ";
        reverse(b.begin(),b.end());
        for(auto o:b)cout<<o<<" ";
        return 0;
    }

    for(int i=1;i<=n;++i){
        if(dis[i]==2){
            int x=i;
            cout<<4<<"\n";
            cout<<1<<" "<<p[x]<<" "<<x<<" "<<1<<" "<<n<<"\n";
            return 0;
        }
    }
    int k=0;
    for(int i=1;i<=n;++i){
        if(dis[i]==1){
            k++;
        }
    }
    for(int i=1;i<=n;++i){
        if(dis[i]==1){
            for(auto v:g[i])vis[v]=1;
            for(auto v:g[i]){
                if(v==1)continue;
                for(auto w:g[v]){
                    if(!vis[w]&&w!=i&&w!=1){
                        cout<<"5\n";
                        cout<<1<<" "<<i<<" "<<v<<" "<<w<<" "<<i<<" "<<n<<"\n";
                        return 0;
                    }
                }
            }
            for(auto v:g[i])vis[v]=0;
        }
    }
    cout<<"-1"<<"\n";
    return 0;
}