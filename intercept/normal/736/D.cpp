#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define i128 __int128_t
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
const int M=2009;
int n,m;
int c[M],u[500009],v[500009];
bitset<M>b[M],d[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        u[i]=x;
        v[i]=y;
        b[x][y]=1;
    }
    for(int i=1;i<=n;++i){
        d[i][i]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(b[i][j]){
                if(!c[j]){
                    c[j]=i;
                    break;
                }
                else b[i]^=b[c[j]],d[i]^=d[c[j]];
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(c[j]==i)continue;
            if(b[i][j]){
                b[i]^=b[c[j]],d[i]^=d[c[j]];
            }
        }
    }
    for(int i=1;i<=m;++i){
        int x=u[i],y=v[i];
        puts(d[c[y]][x]?"NO":"YES");
    }
    return 0;
}
/*
2 2
11

*/