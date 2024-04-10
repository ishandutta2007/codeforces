#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=400009;
int n,q;
int p[M],dep[M],f[M<<1];
vector<int>g[M];
struct P{
    int a,b,id;
};
vector<P>h[M];
char c[M];
int vis[M],pd[M][2],in[M<<1];
void dfs(int u,int fa,int d){
    p[u]=fa;
    dep[u]=d;
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u,d+1);
        }
    }
}
int get(int u,int o){
    return u+o*q;
}
int find(int u){
    return f[u]==u?u:f[u]=find(f[u]);
}
void merge(int u,int v){
    u=find(u);
    v=find(v);
    f[u]=v;
}
int main(){
    memset(vis,-1,sizeof(vis));
    cin>>n>>q;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1,0,0);
    for(int i=1;i<=q;++i){
        int u,v;
        cin>>u>>v>>c;
        vector<int>s,t;
        if(dep[u]<dep[v])swap(u,v);
        while(dep[u]>dep[v])s.eb(u),u=p[u];
        while(u!=v)s.eb(u),t.eb(v),u=p[u],v=p[v];
        s.eb(u);
        reverse(t.begin(),t.end());
        for(auto o:t)s.eb(o);
        for(int j=0;j<s.size();++j){
            int o=s[j];
            if(c[j]==c[s.size()-1-j]){
                if(vis[o]==-1)vis[o]=c[j]-'a';
                else if(vis[o]!=c[j]-'a'){
                    puts("NO");
                    return 0;
                }
            }
            else h[o].eb(P{c[j]-'a',c[s.size()-j-1]-'a',i});
        }
    }
    for(int i=1;i<=q*2;++i)f[i]=i;
    for(int i=1;i<=n;++i){
        if(vis[i]==-1&&h[i].size()>1){
            int u[2]={h[i][0].a,h[i][0].b};
            for(auto o:h[i]){
                int v[2]={o.a,o.b},flag=0;
                for(int j=0;j<2;++j){
                    for(int k=0;k<2;++k){
                        if(u[j]==v[k]){
                            merge(get(h[i][0].id,j),get(o.id,k));
                            if(u[j^1]!=v[k^1]){
                                if(vis[i]==-1)vis[i]=u[j];
                                else if(vis[i]!=u[j]){
                                    puts("NO");
                                    return 0;
                                }
                            }
                            flag=1;
                        }
                    }
                }
                if(flag==0){
                    puts("NO");
                    return 0;
                }
            }
        }
        if(vis[i]!=-1&&h[i].size()){
            int u=get(h[i][0].id,h[i][0].b==vis[i]);
            for(auto o:h[i]){
                if(o.a!=vis[i]&&o.b!=vis[i]){
                    puts("NO");
                    return 0;
                }
                int v=get(o.id,o.b==vis[i]);
                merge(u,v);
                pd[o.id][o.b==vis[i]]=1;
            }
        }
    }
    for(int i=1;i<=q;++i){
        if(pd[i][0])in[find(i)]=1;
        if(pd[i][1])in[find(i+q)]=1;
    }
    for(int i=1;i<=q;++i){
        if(find(i)==find(i+q)||(in[find(i)]&&in[find(i+q)])){
            puts("NO");
            return 0;
        }
        if(!in[find(i)]&&!in[find(i+q)])in[find(i)]=1;
    }
    for(int i=1;i<=n;++i){
        if(vis[i]==-1){
            if(h[i].size()){
                if(in[find(h[i][0].id)])vis[i]=h[i][0].a;
                else vis[i]=h[i][0].b;
            }
            else vis[i]=0;
        }
    }
    puts("YES");
    for(int i=1;i<=n;++i){
        putchar(vis[i]+'a');
    }
    return 0;
}
/*
7 3
1 2
2 3
3 4
4 5
5 6
6 7
1 5 abcde
5 6 ae
6 7 ae

*/