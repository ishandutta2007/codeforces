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
const int M=1e6+9;
int n,m;
char s[M];
int a[M],b[M],c[M],vis[M];
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);
    for(int i=1;i<=n;++i){
        c[a[i]]=b[i];
    }
    int m=1;
    ll ans=0;
    for(int i=1;i<=n;++i)vis[i]=0;
    for(int i=1;i<=n;++i){
        int x=i;
        if(vis[x])continue;
        int s=1;
        vis[x]=1;
        x=c[x];
        while(x!=i){
            vis[x]=1;
            s++;
            x=c[x];
        }
        s=s/2;
        for(int i=m;i<m+s;++i){
            ans+=(n-i+1-i);
            if(i==m+s-1){
                ans+=(n-i+1-m);
            }
            else ans+=(n-i+1-(i+1));
        }
        m+=s;
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
2 4
11001101
*/