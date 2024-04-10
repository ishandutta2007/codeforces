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
int p[13][12][12];
int dp[25][12][12][12];
int c(int n,int l,int t){
    if(n-l-t+1<=0)return 0;
    int sum=1;
    for(int i=n-l-t+1;i<=n-l;++i)sum=1ll*sum*i%mod;
    return sum;
}
void work(){
    int n,k,x,ans=0;
    cin>>n>>k>>x;
    for(int l=1;l<=min(n,22);++l){
        for(int t=1;t<=11;++t){
            ans=(ans+1ll*dp[l][k][x][t]*c(n,l-t,t)%mod)%mod;
        }
    }
    cout<<ans<<endl;
}
void pre(int s,int k,int x,int la){
    if(k>11||x>11)return;
    int y=__builtin_popcount(s);
    if(s&&!(s>>y)){
        p[y][k][x]++;
        return;
    }
    for(int i=0;i<12;++i){
        if(s>>i&1)continue;
        int kk=__builtin_popcount(s>>i);
        pre(s|(1<<i),k+kk,x+(la>i),i);
    }
}
int inv[13];
int main(){
    pre(0,0,0,-1);
    inv[0]=1;
    for(int i=1;i<=11;++i)inv[i]=kpow(i,mod-2);
    dp[0][0][0][0]=1;
    for(int y=1;y<=12;++y){
        for(int kk=1;kk<=11;++kk){
            for(int xx=1;xx<=kk;++xx){
                for(int l=22;l>=0;--l){
                    int z=1;
                    for(int num=1;num<=11;++num){
                        if(l+num*y>22)break;
                        z=1ll*z*p[y][kk][xx]%mod*inv[num]%mod;
                        for(int k=11-kk*num;k>=0;--k){
                            for(int x=min(11-xx*num,k);x>=0;--x){
                                for(int t=11-num;t>=0;--t){
                                    dp[l+y*num][k+kk*num][x+xx*num][t+num]=(dp[l+y*num][k+kk*num][x+xx*num][t+num]+1ll*z*dp[l][k][x][t]%mod)%mod;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
10 6 4

*/