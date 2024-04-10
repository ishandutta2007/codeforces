#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
//typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
/*void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}*/
const int mo=1000000007;
//int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int n;
struct para{
    int x,l;
}a[111];
int cmp(const para&a,const para&b){
    return a.x<b.x;
}
int ll[111],mm[111],rr[111];

int x[333];int tot=0;
int f[111][111][333];
#define inf 1000000000
int de(int x,int y){
    if(x==inf || y==inf)return inf;
    return min(x,y);
}
inline int upd(int l,int r,int j,int lx,int rx){
    if(lx<=j && j<=rx){
        if(l==r)return lx;
        int mi=inf;
        for (int t=r-1;t>=l;t--)mi=min(mi,de(lx,f[l][t][mm[t]>lx?mm[t]:lx]));
        //return de(lx,f[l][r-1][lx]);
        return mi;
    }else{
        if(l==r)return inf;
        int mi=inf;
        for (int t=r-1;t>=l;t--)mi=min(mi,de(lx,f[l][t][j]));
        return mi;
        //return de(lx,f[l][r-1][j]);
    }
}
int g[111][333];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].l);
        x[++tot]=a[i].x-a[i].l;
        x[++tot]=a[i].x;
        x[++tot]=a[i].x+a[i].l;
    }
    sort(a+1,a+1+n,cmp);
    sort(x+1,x+1+tot);
    tot=unique(x+1,x+1+tot)-x-1;
    for (int i=1;i<=n;i++){
        ll[i]=lower_bound(x+1,x+1+tot,a[i].x-a[i].l)-x;
        mm[i]=lower_bound(x+1,x+1+tot,a[i].x)-x;
        rr[i]=lower_bound(x+1,x+1+tot,a[i].x+a[i].l)-x;
    }
    for (int l=1;l<=n;l++)
        for (int r=l;r<=n;r++)
            for (int j=1;j<=tot;j++){
                f[l][r][j]=inf;
                f[l][r][j]=min(f[l][r][j],upd(l,r,j,mm[r],rr[r]));
                f[l][r][j]=min(f[l][r][j],upd(l,r,j,ll[r],mm[r]));
            }
    for (int l=1;l<=n;l++)
        for (int r=l+1;r<=n;r++){
            if(rr[l]>r && ll[r]<l){
                int le=ll[r],ri=rr[l];
                for (int j=le;j<=ri;j++)f[l][r][j]=min(f[l][r][j],le);
            }
        }
    for (int r=1;r<=n;r++)
        for (int j=1;j<=tot;j++){
            if(f[1][r][j]==inf)g[r][j]=-inf;
            else g[r][j]=x[j]-x[f[1][r][j]];
        }
    for (int r=2;r<=n;r++)
        for (int j=1;j<=tot;j++){
            for (int l=2;l<=r;l++)if(f[l][r][j]<inf){
                for (int k=1;k<=f[l][r][j];k++){
                    int nu=x[j]-x[f[l][r][j]]+g[l-1][k];
                    g[r][j]=max(g[r][j],nu);
                }
            }
            if(g[r][j]<0)g[r][j]=-inf;
        }
    int ma=0;
    for (int i=1;i<=tot;i++)ma=max(ma,g[n][i]);
    printf("%d\n",ma);
    return 0;
}