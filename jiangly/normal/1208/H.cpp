#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=1e5+5;
int n,k,q;
vector<int> g[MAX_N];
int block_size;
int boundary[MAX_N][2];
int parent[MAX_N];
int color[MAX_N];
int down[MAX_N];
bool is_in[MAX_N];
vector<int> g_in[MAX_N];
vector<int> g_out[MAX_N];
vector<tuple<int,int,int>> query;
void dfsBuild(int u){
    for(int i=0;i<g[u].size();++i){
        if(g[u][i]==parent[u]){
            swap(g[u][i],g[u].back());
            g[u].pop_back();
            --i;
            continue;
        }
        parent[g[u][i]]=u;
        dfsBuild(g[u][i]);
    }
}
void dfsPrepare(int u){
    if(g[u].size()==0){
        if(is_in[u]){
            down[u]=u;
            boundary[u][0]=-n;
            boundary[u][1]=n+1;
        }else{
            if(color[u]==0){
                boundary[u][0]=-n;
            }else{
                boundary[u][0]=n+1;
            }
        }
        return;
    }
    for(int v:g[u]){
        dfsPrepare(v);
        if(is_in[v]){
            g_in[u].push_back(v);
            is_in[u]=true;
        }else{
            g_out[u].push_back(boundary[v][0]);
        }
    }
    sort(g_out[u].begin(),g_out[u].end());
    if(!is_in[u]){
        int l=-n,r=n+1;
        while(l<r){
            int mid=(l+r)>>1;
            int cb=0,cr=0;
            int res=upper_bound(g_out[u].begin(),g_out[u].end(),mid)-g_out[u].begin();
            cr+=res;
            cb+=g_out[u].size()-res;
            if(cb-cr>=mid){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        boundary[u][0]=l;
    }else if(g_in[u].size()==1){
        down[u]=down[g_in[u][0]];
        for(int c=0;c<=1;++c){
            int l=-n,r=n+1;
            while(l<r){
                int mid=(l+r)>>1;
                int cb=0,cr=0;
                int res=upper_bound(g_out[u].begin(),g_out[u].end(),mid)-g_out[u].begin();
                cr+=res;
                cb+=g_out[u].size()-res;
                if(mid>=boundary[g_in[u][0]][c]){
                    ++cr;
                }else{
                    ++cb;
                }
                if(cb-cr>=mid){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }
            boundary[u][c]=l;
        }
    }else{
        down[u]=u;
        boundary[u][0]=-n;
        boundary[u][1]=n+1;
    }
}
int queryColor(int u,int k){
    if(g[u].size()==0){
        return color[u];
    }else if(down[u]==u){
        int cr=0,cb=0;
        for(int v:g_in[u]){
            if(queryColor(v,k)==0){
                ++cr;
            }else{
                ++cb;
            }
        }
        int res=upper_bound(g_out[u].begin(),g_out[u].end(),k)-g_out[u].begin();
        cr+=res;
        cb+=g_out[u].size()-res;
        return cb-cr>=k?1:0;
    }else{
        return (k>=boundary[u][queryColor(down[u],k)])?0:1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    block_size=sqrt(n);
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        cin>>color[i];
    }
    dfsBuild(1);
    cin>>q;
    for(int i=1;i<=q;i+=block_size){
        for(int j=i;j<=min(i+block_size-1,q);++j){
            int op,x,y;
            cin>>op;
            switch(op){
                case 1:
                    cin>>x;
                    is_in[x]=true;
                    query.emplace_back(1,x,k);
                    break;
                case 2:
                    cin>>x>>y;
                    is_in[x]=true;
                    query.emplace_back(2,x,y);
                    break;
                case 3:
                    cin>>k;
                    break;
            }
        }
        dfsPrepare(1);
        for(auto [op,x,y]:query){
            switch(op){
                case 1:
                    cout<<queryColor(x,y)<<endl;
                    break;
                case 2:
                    color[x]=y;
                    break;
            }
        }
        for(int j=1;j<=n;++j){
            is_in[j]=false;
            g_in[j].clear();
            g_out[j].clear();
        }
        query.clear();
    }
    return 0;
}