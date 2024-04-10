#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=0){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e6+9;
const int inf=0x3f3f3f3f;
int n;
int a[M],vis[M];
int dp[M][2][2],p[M][2][2],pp[M][2][2],ans[M];
void d(int i,int j,int k,int y,int l,int r){
    if(dp[i][j][k]>y){
        dp[i][j][k]=y;
        p[i][j][k]=l;
        pp[i][j][k]=r;
    }
}
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        vis[i]=0;
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k)dp[i][j][k]=inf;
        }
    }
    dp[1][0][0]=dp[1][1][0]=-n-1;
    dp[1][0][1]=dp[1][1][1]=inf;
    for(int i=2;i<=n;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                int x=j?a[i-1]:-a[i-1],y,z=k?a[i]:-a[i];
                y=dp[i-1][j][0];
                if(x>z&&z>y&&y!=inf){
                    d(i,k,1,x,j,0);
                }
                if(x<z&&y!=inf){
                    d(i,k,0,y,j,0);
                }
                y=dp[i-1][j][1];
                if(z>y&&y!=inf){
                    d(i,k,0,x,j,1);
                }
                if(z<y&&z>x&&y!=inf){
                    d(i,k,1,y,j,1);
                }
            }
        }
    }
    for(int j=0;j<2;++j){
        for(int k=0;k<2;++k){
            if(dp[n][j][k]!=inf){
                puts("YES");
                for(int i=n;i>=1;--i){
                    ans[i]=j?a[i]:-a[i];
                    int nj=p[i][j][k],nk=pp[i][j][k];
                    j=nj,k=nk;
                }
                for(int i=1;i<=n;++i){
                    printf("%d%c",ans[i]," \n"[i==n]);

                }
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
/*
1
6
1 3 2 6 5 4
*/