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
const int M=(1<<19)+9;;
int n,ls[M],rs[M],ans[M];
char s[M];
int pd(int a,int b){
    if(!a)return 0;
    if(s[a]>s[b])return 1;
    if(s[a]<s[b])return -1;
    int o;
    if(o=pd(ls[a],ls[b]))return o;
    if(o=pd(rs[a],rs[b]))return o;
    return 0;
}
int dfs(int u){
    if((u<<1)>=(1<<n)){
        ans[u]=1;
        return u;
    }
    ls[u]=dfs(u<<1);
    rs[u]=dfs(u<<1|1);
    int o=pd(ls[u],rs[u]);
    if(o==1)swap(ls[u],rs[u]);
    ans[u]=(o?2ll:1ll)*ans[ls[u]]%mod*ans[rs[u]]%mod;
    return u;
}
int main(){
    cin>>n>>(s+1);
    dfs(1);
    cout<<ans[1]<<endl;
    return 0;
}
/*
3
BAABABA
*/