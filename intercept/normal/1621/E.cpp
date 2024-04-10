#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e5+9;
int n,m;
int k[M],id[M],ps[M];
ll sum[M],a[M];
vector<int>b[M];
int dp[M][3],p[M],s[M],t[M][2];
bool ans[M<<1];
double c(int x){
    return 1.0*sum[x]/k[x];
}
void work(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=m;++i)a[i]=a[i+n-m];
    n=m;
    for(int i=1;i<=n;++i){
        id[i]=i;
        scanf("%d",&k[i]);
        ps[i]=ps[i-1]+k[i];
        b[i].clear();
        b[i].resize(k[i]+1);
        b[i][0]=0;
        sum[i]=0;
        for(int j=1;j<=k[i];++j)scanf("%d",&b[i][j]),sum[i]+=b[i][j];
    }
    sort(id+1,id+n+1,[&](const int&l,const int&r){return sum[l]*k[r]<sum[r]*k[l];});
    for(int i=1;i<=n;++i){
        dp[i][0]=dp[i][1]=dp[i][2]=0;
        int x=id[i];
        if(sum[x]<=a[i-1]*k[x])dp[i][0]=1;
        if(sum[x]<=a[i]*k[x])dp[i][1]=1;
        if(sum[x]<=a[i+1]*k[x])dp[i][2]=1;
    }
    p[0]=1;
    for(int i=1;i<=n;++i){
        if(dp[i][1])p[i]=p[i-1];
        else p[i]=0;
    }
    s[n+1]=1;
    for(int i=n;i>=1;--i){
        if(dp[i][1])s[i]=s[i+1];
        else s[i]=0;
    }
    t[n+1][0]=t[n+1][1]=0;
    for(int i=n;i>=1;--i){
        if(dp[i][0])t[i][0]=max(i,t[i+1][0]);
        else t[i][0]=0;
        if(dp[i][2])t[i][1]=max(i,t[i+1][1]);
        else t[i][1]=0;
    }
    for(int i=1;i<=ps[n];++i)ans[i]=0;
    for(int i=1;i<=n;++i){
        int x=id[i];
        for(int j=1;j<=k[x];++j){
            int z=ps[x-1]+j;
            int l=1,r=n;
            while(l<=r){        
                int mid=l+r>>1;
                if((sum[x]-b[x][j])*k[id[mid]]<sum[id[mid]]*(k[x]-1))r=mid-1;
                else l=mid+1;
            }
            int y=l;
            if(i==y||i==y-1){
                if(p[i-1]&&s[i+1]&&(sum[x]-b[x][j])<=a[i]*(k[x]-1))ans[z]=1;
            }
            else if(i<y){
                if(p[i-1]&&s[y]&&(sum[x]-b[x][j])<=a[y-1]*(k[x]-1)&&t[i+1][0]>=y-1)ans[z]=1;
            }
            else if(i>y){
                if(s[i+1]&&p[y-1]&&(sum[x]-b[x][j])<=a[y]*(k[x]-1)&&t[y][1]>=i-1)ans[z]=1;
            }
        }
    }
    for(int i=1;i<=ps[n];++i)putchar(ans[i]?'1':'0');
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
1
7 4
8 5 8 12 8 19 6
5
1 2 3 4 5
5
19 15 23 11 27
5
5 8 8 8 8
4
8 8 8 9
*/