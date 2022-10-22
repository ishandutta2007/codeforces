#include <bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
const int mn=1e5+10;
int a[mn],num[mn],uni,lo[mn];
int dp[51][35001];
int seg[1<<18],laz[1<<18];
inline void prop(int n){
    seg[n]+=laz[n];
    laz[n*2]+=laz[n];
    laz[n*2+1]+=laz[n];
    laz[n]=0;
}
inline void eval(int n){
    prop(n*2);
    prop(n*2+1);
    seg[n]=max(seg[n*2],seg[n*2+1]);
}
void update(int n,int l,int r,int a,int b,int c){
    prop(n);
    if(a==l&&b==r)laz[n]=c;
    else{
        if(b<=mid)update(n*2,l,mid,a,b,c);
        else if(a>mid)update(n*2+1,mid+1,r,a,b,c);
        else update(n*2,l,mid,a,mid,c),update(n*2+1,mid+1,r,mid+1,b,c);
        eval(n);
    }
}
int main()
{
    int n,k,i,j,x;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=1;i<=k;i++){
        memset(seg,0xc0,sizeof(seg));
        memset(laz,0,sizeof(laz));
        memset(lo,0,sizeof(lo));
        for(j=1;j<=n;j++){
            update(1,0,n,j-1,j-1,dp[i-1][j-1]-0xc0c0c0c0);
            update(1,0,n,lo[a[j]],j-1,1);
            lo[a[j]]=j;
            eval(1);
            dp[i][j]=seg[1];
        }
    }
    printf("%d",dp[k][n]);
}