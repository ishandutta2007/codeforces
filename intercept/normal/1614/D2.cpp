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
const int M=20000009;
int n,num;
int a[M];
int ans=0,sum=0,ma=0;
ll dp[M],f[M];
int pri[M],vis[M];
int main(){
    for(int i=2;i<M;++i){
        if(!vis[i])vis[i]=i,pri[++num]=i;
        for(int j=1;j<=num&&1ll*i*pri[j]<M;++j){
            vis[i*pri[j]]=pri[j];
            if(i%pri[j]==0)break;
        }
    }    
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        dp[a[i]]+=a[i];
        int s=sqrt(a[i]+1);
        for(int j=1;j<=s;++j){
            if(a[i]%j==0){
                f[j]++;
                f[a[i]/j]++;
                if(j==s&&j*j==a[i])f[j]--;
            }
        }
    }
    
    for(int i=20000000;i>1;--i){
        if(f[i]){
            int x=i;
            while(x>1){
                int y=vis[x];
                dp[i/y]=max(dp[i/y],dp[i]+(f[i/y]-f[i])*(i/y));
                while(x%y==0)x/=y;
            }
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}
/*


*/