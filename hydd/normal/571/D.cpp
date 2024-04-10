#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
int n,m,v4[510000];
vector<pii> v3[510000];
vector<int> vec;
struct UnionSet{
    int fa[510000],sz[510000],t[510000];
    void init(){
        for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    }
    int findset(int u){ return (u==fa[u]?u:findset(fa[u]));}
    void Merge(int u,int v,int i){
        u=findset(u); v=findset(v);
        if (u==v) return; if (sz[u]>sz[v]) swap(u,v);
        fa[u]=v; sz[v]+=sz[u]; t[u]=i;
    }
} T1,T2;
ll calc(int x,int t){
    int pos=lower_bound(v3[x].begin(),v3[x].end(),pii(t,0))-v3[x].begin();
    return v3[x].back().second-v3[x][pos-1].second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    T1.init(); T2.init();
    for (int i=1;i<=n;i++) v3[i].push_back(pii(-1,0));
    char op; int x,y;
    for (int i=1;i<=m;i++){
        cin>>op>>x;
        switch (op){
            case 'U':
                cin>>y;
                T1.Merge(x,y,i);
                break;
            case 'M':
                cin>>y;
                T2.Merge(x,y,i);
                break;
            case 'A':
                x=T1.findset(x);
                v3[x].push_back(pii(i,T1.sz[x]+v3[x].back().second));
                break;
            case 'Z':
                x=T2.findset(x);
                v4[x]=i;
                break;
            case 'Q':
                vec.clear(); int y=x; vec.push_back(y);
                while (T2.fa[y]!=y) y=T2.fa[y],vec.push_back(y);

                int t=v4[x];
                for (int i=1;i<(int)vec.size();i++)
                    if (v4[vec[i]]>T2.t[vec[i-1]]) t=max(t,v4[vec[i]]);

                vec.clear(); y=x; vec.push_back(y);
                while (T1.fa[y]!=y) y=T1.fa[y],vec.push_back(y);
                ll ans=calc(x,t);
                for (int i=1;i<(int)vec.size();i++) ans+=calc(vec[i],max(t,T1.t[vec[i-1]]));
                cout<<ans<<'\n';
                break;
        }
    }
    return 0;
}