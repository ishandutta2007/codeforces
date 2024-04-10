#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T>void reverse(vector<T> &a){
    reverse(a.begin(),a.end());
}
void reverse(string &a){
    reverse(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
int readInt(){
    int x=0;
    bool sign=false;
    char c=getchar();
    while(!isdigit(c)){
        sign=c=='-';
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return sign?-x:x;
}
ll readLong(){
    ll x=0;
    bool sign=false;
    char c=getchar();
    while(!isdigit(c)){
        sign=c=='-';
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return sign?-x:x;
}
string readString(){
    string s;
    char c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(!isspace(c)){
        s+=c;
        c=getchar();
    }
    return s;
}
class Flow{
private:
struct Edge{
int to,f,c,next;
Edge(int to,int f,int c,int next):to(to),f(f),c(c),next(next){}
};
int V;
vector<int> head;
vector<Edge> edges;
vector<int> from,h,dis;
bool SP(int S,int T){
    from.assign(V,-1);
    dis.assign(V,1e9);
    vector<vector<int>> ver(1);
    dis[S]=0;
    ver[0].push_back(S);
    for(int D=0;D<ver.size();++D){
        while(!ver[D].empty()){
            int u=ver[D].back();
            ver[D].pop_back();
            if(dis[u]!=D){
                continue;
            }
            for(int i=head[u];i!=-1;){
                auto [v,f,c,next]=edges[i];
                if(c>0&&dis[v]+h[v]>dis[u]+h[u]+f){
                    dis[v]=dis[u]+h[u]-h[v]+f;
                    from[v]=i;
                    if(dis[v]>=ver.size()){
                        ver.resize(dis[v]+1);
                    }
                    ver[dis[v]].push_back(v);
                }
                i=next;
            }
        }
    }
    return dis[T]!=1e9;
}
public:
Flow(int V):V(V){
    head.assign(V,-1);
}
void insert_edge(int u,int v,int f,int c){
    edges.emplace_back(v,f,c,head[u]);
    head[u]=edges.size()-1;
    edges.emplace_back(u,-f,0,head[v]);
    head[v]=edges.size()-1;
}
int MCMF(int S,int T){
    h.resize(V);
    int cost=0;
    while(SP(S,T)){
        int mn=1e9;
        for(int i=0;i<V;++i){
            h[i]+=dis[i];
        }
        for(int u=T;u!=S;u=edges[from[u]^1].to){
            chkmin(mn,edges[from[u]].c);
        }
        for(int u=T;u!=S;u=edges[from[u]^1].to){
            edges[from[u]].c-=mn;
            edges[from[u]^1].c+=mn;
        }
        cost+=mn*h[T];
    }
    return cost;
}
};
void solve_single_test(int test_id=1){
    int n=readInt();
    vector<int> a(n*2),b(n*2);
    for(int i=0;i<n*2;++i){
        a[i]=readInt();
        b[i]=readInt();
    }
    int l=0,r=1e9+1;
    while(l<r){
        int T=(l+r)/2;
        vector<ll> goal,have;
        bool ok=true;
        ll mx=0;
        vector<tuple<int,ll,char>> stocks(n*2);
        for(int i=0;i<n*2;++i){
            stocks[i]={b[i],-1ll*a[i]*T-b[i],i<n};
        }
        sort(stocks);
        for(auto [x,y,op]:stocks){
            chkmax(mx,-y);
            if(op){
                have.push_back(mx);
            }else{
                goal.push_back(-y);
            }
        }
        sort(goal);
        for(int i=0;i<n;++i){
            if(have[i]<goal[i]){
                ok=false;
                break;
            }
        }
        if(ok){
            r=T;
        }else{
            l=T+1;
        }
    }
    if(r>1e9){
        puts("-1");
        return;
    }
    Flow G(n*4+2);
    int S=n*4,T=S+1;
    for(int i=0;i<n;++i){
        G.insert_edge(S,i,0,1);
        G.insert_edge(i,i+n*2,0,1);
    }
    for(int i=n;i<n*2;++i){
        G.insert_edge(i,T,0,1);
        G.insert_edge(i+n*2,i,0,1);
    }
    vector<int> seq(n);
    for(int i=0;i<n;++i){
        seq[i]=i;
    }
    sort(seq,[&](int x,int y){return b[x]<b[y];});
    for(int i=0;i+1<n;++i){
        G.insert_edge(seq[i+1],seq[i],0,1e9);
    }
    vector<int> tp(n*2);
    for(int i=0;i<n*2;++i){
        tp[i]=i;
    }
    sort(tp,[&](int x,int y){return b[x]<b[y];});
    for(int i=0,j=0;i<n*2;++i){
        int x=tp[i];
        while(j<n&&b[seq[j]]<b[x]){
            ++j;
        }
        if(j<n){
            G.insert_edge(seq[j],x+n*2,1,1e9);
        }
    }
    for(int i=0;i<n;++i){
        seq[i]=i+n;
    }
    sort(seq,[&](int x,int y){return 1ll*a[x]*l+b[x]>1ll*a[y]*l+b[y];});
    for(int i=0;i+1<n;++i){
        G.insert_edge(seq[i],seq[i+1],0,1e9);
    }
    sort(tp,[&](int x,int y){return 1ll*a[x]*l+b[x]>1ll*a[y]*l+b[y];});
    for(int i=0,j=0;i<n*2;++i){
        int x=tp[i];
        while(j<n&&1ll*a[seq[j]]*l+b[seq[j]]>1ll*a[x]*l+b[x]){
            ++j;
        }
        if(j<n){
            G.insert_edge(x+n*2,seq[j],1,1e9);
        }
    }
    printf("%d %d\n",l,G.MCMF(S,T));
}
void solve_multiple_tests(){
    int n_tests=readInt();
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}