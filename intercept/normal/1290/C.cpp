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
const int M=6e5+9;
int n,m;
int g[M][2];
char c[M];
int ans=0;
int f[M],s[M];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y,int u,int v){

    if(find(x)==find(y)||find(x)==find(y+m+1))return;
    ans-=min(s[find(x)],s[find(x+m+1)]);
    ans-=min(s[find(y)],s[find(y+m+1)]);
    
    s[find(y)]+=s[find(x+u)];
    f[find(x+u)]=find(y);
    s[find(y+m+1)]+=s[find(x+v)];
    f[find(x+v)]=find(y+m+1);
    ans+=min(s[find(x)],s[find(x+m+1)]);
}
int main(){
    scanf("%d%d%s",&n,&m,c+1);
    for(int i=1;i<=m;++i){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            int x;
            scanf("%d",&x);
            g[x][(bool)g[x][0]]=i;
        }
    }
    for(int i=1;i<=m*2+1;++i)f[i]=i,s[i]=i<=m;
    for(int i=1;i<=n;++i){

        if(c[i]&1)merge(g[i][0],g[i][1],0,m+1);
        else merge(g[i][0],g[i][1],m+1,0);
        printf("%d\n",ans-min(s[find(0)],s[find(m+1)])+s[find(m+1)]);
    }
    return 0;

}
/*
4 3
0011
2
1 4
2
3 4
2
2 3


*/