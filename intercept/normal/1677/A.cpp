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
const int M=5009;
int n;
int a[M],b[M][M];
void work(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)b[i][j]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            b[i][j]=b[i-1][j]+(j>=a[i]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ans+=1ll*b[i-1][a[j]-1]*(b[n][a[i]-1]-b[j][a[i]-1]);
        }
    }
    
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}