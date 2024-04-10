#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
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
const int M=1e6+9;
int n,k;
int a[M];
void work(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=n-k+1;i<=n;++i){
        if(a[i]>0){
            puts("0");
            return;
        }
    }
    int ans=1;
    for(int i=1;i<=k;++i)ans=1ll*ans*i%mod;
    for(int i=1;i<=n-k;++i){
        if(a[i]==0)ans=1ll*ans*min(i+k,k+1)%mod;
        if(a[i]==-1)ans=1ll*ans*(i+k)%mod;
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}