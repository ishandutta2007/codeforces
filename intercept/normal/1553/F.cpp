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
const int M=6e5+9;
int n;
ll ans[M];
struct P{
    ll bit[M];
    void add(int x,ll v){
        for(;x<M;x+=x&-x)bit[x]+=v;
    }
    ll ask(int x,ll rex=0){
        for(;x;x-=x&-x)rex+=bit[x];
        return rex;
    }
}num,ik,ki;

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        ll x;
        cin>>x;
        ans[i]=ans[i-1];
        for(int j=0;j+x<M;j+=x){
            int m=num.ask(j+x-1)-num.ask(j);
            ans[i]+=ik.ask(j+x-1)-ik.ask(j)-1ll*m*j;
        }
        ans[i]+=(i-1)*x-ki.ask(x);
        num.add(x,1);
        ik.add(x,x);
        for(int j=x;j<M;j+=x){
            ki.add(j,x);
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
    return 0;
}