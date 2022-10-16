#include<cstdio>
#include<cstring>
#define MAX   333
typedef long long ll;
const ll INF=(ll)5e14;
ll s[MAX][MAX];
ll f[MAX][MAX];
int m,n,q;
template<class T> 
    T min(const T &x,const T &y) {
        if (x<y) return (x); else return (y);
    }
template<class T>
    T max(const T &x,const T &y) {
        if (x>y) return (x); else return (y);
    }
void init(void) {
    memset(s,0x3f,sizeof s);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&q);
    int i,j,l,r;
    ll c;
    for (i=1;i<=m;i=i+1) {
        scanf("%d",&l);
        scanf("%d",&r);
        scanf("%I64d",&c);
        s[l][r]=min(s[l][r],c);
    }
    for (i=1;i<=n;i=i+1)
        for (j=n-1;j>=1;j=j-1) s[i][j]=min(s[i][j],s[i][j+1]);
    for (j=1;j<=n;j=j+1)
        for (i=2;i<=n;i=i+1) s[i][j]=min(s[i][j],s[i-1][j]);
/*  for (i=1;i<=n;i=i+1) {
        for (j=1;j<=n;j=j+1) printf("%I64d ",s[i][j]);
        printf("\n");
    }*/
}
void optimize(void) {
    memset(f,0x3f,sizeof f);
    int i,j,k;
    for (i=0;i<=n;i=i+1) f[0][i]=0LL;
    for (i=1;i<=q;i=i+1)
        for (j=1;j<=n;j=j+1) {
            f[i][j]=f[i][j-1];
            for (k=j;(k>=1) && (j-k+1<=i);k=k-1)
                f[i][j]=min(f[i][j],f[i-(j-k+1)][k-1]+s[k][j]);
        //  printf("f(%d,%d)=%I64d\n",i,j,f[i][j]);
        }
    if (f[q][n]>=INF) printf("-1");
    else printf("%I64d",f[q][n]);    
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    optimize();
    return 0;
}