#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 402
using namespace std;
short p[N][N*N];
int a[N][N],n,m,l,r,j,i,d[N][N],f[N][N],ans;
int main(){
//    freopen("test20\\matrix.inp","r",stdin);
//    freopen("test20\\matrix.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
    for(j=1;j<=m;++j){
        for(l=n;l>=1;--l)
            for(r=l;r<=n;++r){
                f[l][r]=max((int)max(p[r][a[l][j]],p[l][a[r][j]]),max(f[l+1][r],f[l][r-1]));
                if(l!=r && a[l][j]==a[r][j])f[l][r]=j;
                d[l][r]=max(d[l][r],f[l][r]);
                ans=max(ans,(r-l+1)*(j-d[l][r]));
            }
        for(i=1;i<=n;++i)p[i][a[i][j]]=j;
    }
    printf("%d\n",ans);
}