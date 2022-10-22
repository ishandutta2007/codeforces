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
const int M=100009;
int n,m,q;
vector<int>g[M];

int f[30][M],s[30][M];
int find(int *F,int x){
    return F[x]==x?x:F[x]=find(F,F[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=0;j<30;++j)f[j][i]=i;
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        for(int j=0;j<30;++j){
            if(w>>j&1){
                int fu=find(f[j],u);
                int fv=find(f[j],v);
                if(fu!=fv){
                    f[j][fu]=fv;
                    s[j][fv]|=s[j][fu];
                }
                
            }
            if(w%2==0){
                int fu=find(f[j],u);
                int fv=find(f[j],v);
                s[j][fv]=s[j][fu]=1;
             }
        }
    }
    cin>>q;
    for(int i=1;i<=q;++i){
        int u,v;
        cin>>u>>v;
        bool o=0;
        for(int j=0;j<30;++j){
            if(find(f[j],u)==find(f[j],v)){
                o=1;
                puts("0");
                break;
            }
        }
        if(!o){
            for(int j=1;j<30;++j){
                if(s[j][find(f[j],u)]){
                    o=1;
                    puts("1");
                    break;
                }
            }
        }
        if(!o)puts("2");
    }
    return 0;
}
/*
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
1
1 5
*/