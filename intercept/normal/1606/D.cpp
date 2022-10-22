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
const int M=5e5+9;
int n,m;
vector<vector<int>>pma,pmi,sma,smi,c;
struct P{
    int la,lb,ra,rb,id;
}p[M];
int s[M],sp[M];
int ans[M];
void work(){
    c.clear();
    pma.clear();
    pmi.clear();
    sma.clear();
    smi.clear();
    scanf("%d%d",&n,&m);
    c.resize(n+1);
    pma.resize(n+1);
    pmi.resize(n+1);
    sma.resize(n+1);
    smi.resize(n+1);
    for(int i=1;i<=n;++i){

        c[i].resize(m+2);
        pma[i].resize(m+2);
        pmi[i].resize(m+2);
        sma[i].resize(m+2);
        smi[i].resize(m+2);
        pma[i][0]=0;
        pmi[i][0]=1e9;
        sma[i][m+1]=0;
        smi[i][m+1]=1e9;
        for(int j=1;j<=m;++j){
            scanf("%d",&c[i][j]);
        }
        for(int j=1;j<=m;++j){
            pma[i][j]=max(pma[i][j-1],c[i][j]);
            pmi[i][j]=min(pmi[i][j-1],c[i][j]);
        }
        for(int j=m;j>=1;--j){
            sma[i][j]=max(sma[i][j+1],c[i][j]);
            smi[i][j]=min(smi[i][j+1],c[i][j]);
        }
    }
    for(int i=1;i<=n;++i)ans[i]=0;
    for(int j=1;j<m;++j){
        for(int i=1;i<=n;++i)p[i]=P{pma[i][j],pmi[i][j],sma[i][j+1],smi[i][j+1],i};
        sort(p+1,p+n+1,[&](const P&l,const P&r){return l.la<r.la;});
        s[n+1]=0;
        sp[n+1]=1e9;
        for(int i=n;i>=1;--i)s[i]=max(s[i+1],p[i].ra),sp[i]=min(sp[i+1],p[i].lb);
        for(int i=1,mi=1e9;i<n;++i){
            mi=min(mi,p[i].rb);
            if(sp[i+1]>p[i].la&&s[i+1]<mi){
                puts("YES");
                for(int k=1;k<=i;++k)ans[p[k].id]=1;
                for(int k=1;k<=n;++k){
                    putchar(ans[k]?'B':'R');
                }
                printf(" %d\n",j);
                return;
            }
        }
    }
    puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}