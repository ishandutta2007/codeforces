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
const int M=3e5+9;
int n,x,y,z,t;
int b[6],sg[10000009][4];
ll a[M];

int mex(int u,int v,int w){
    for(int i=0;i<5;++i)b[i]=0;
    b[u]=b[v]=b[w]=1;
    int s=0;
    while(b[s])s++;
    return s;
}
map<ll,int >mp;
int l,r;
int get(ll s,int j){
    if(s<0)return 0;
    if(s<=r)return sg[s][j];
    ll ss=l+(s-l)%(r-l);
    return sg[ss][j];
}
void work(){
    mp.clear();
    scanf("%d%d%d%d",&n,&x,&y,&z);
    t=x*y/__gcd(x,y);
    t=t*z/__gcd(t,z);
    for(int i=1;;++i){
        sg[i][0]=mex(sg[max(i-x,0)][0],sg[max(i-y,0)][1],sg[max(i-z,0)][2]);
        sg[i][1]=mex(sg[max(i-x,0)][0],sg[max(i-z,0)][2],4);
        sg[i][2]=mex(sg[max(i-x,0)][0],sg[max(i-y,0)][1],4);
        ll s=0,st=1;
        for(int j=0;j<x;++j)s+=sg[max(i-j,0)][0]*st,st*=4;
        for(int j=0;j<y;++j)s+=sg[max(i-j,0)][1]*st,st*=4;   
        for(int j=0;j<z;++j)s+=sg[max(i-j,0)][2]*st,st*=4;
        if(mp.count(s)){
            l=mp[s],r=i;
            break;
        }
        mp[s]=i;
    }
    int ans=0,sum=0;
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sum^=get(a[i],0);
    }
    for(int i=1;i<=n;++i){
        int s=sum^get(a[i],0);
        ans+=(!(get(a[i]-x,0)^s))+(!(get(a[i]-y,1)^s))+(!(get(a[i]-z,2)^s));
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*

1
3 2 5 1
1509 1243 9764

*/