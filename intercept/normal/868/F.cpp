#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int M=100009;
int n,k;
int a[M],b[M];
ll dp[M],f[M];
int L,R;
ll ans;
void update(int l,int r){
    while(L>l)ans+=b[a[--L]]++;
    while(L<l)ans-=--b[a[L++]];
    while(R>r)ans-=--b[a[R--]];
    while(R<r)ans+=b[a[++R]]++;
}
void solve(int l,int r,int d,int u){
    if(l>r)return;
    int mid=l+r>>1;
    update(d,mid);
    int p=mid;
    for(int i=d;i<=u;++i){
        if(dp[mid]>f[i-1]+ans){
            dp[mid]=f[i-1]+ans;
            p=i;
        }
        update(i+1,mid);
    }
    
    solve(l,mid-1,d,p);
    solve(mid+1,r,p,u);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1]+b[a[i]];
        b[a[i]]++;
    }
    memset(b,0,sizeof(b));
    for(int i=1;i<k;++i){
        for(int j=1;j<=n;++j)f[j]=dp[j],dp[j]=1ll<<60;
        L=1,R=0;
        update(1,0);
        solve(1,n,1,n);
    }
    printf("%lld\n",dp[n]);
    return 0;
}