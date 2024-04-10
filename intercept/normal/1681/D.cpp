#include<bits/stdc++.h>
#define ll __int128_t
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
ll kpow(ll x,ll y,ll rex=1){
    for(;y;y>>=1,x=x*x)if(y&1)rex=x*rex;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
int n,ans;
ll x;
int get(ll t){
    int p=0;
    while(t)t/=10,p++;
    return p;
}
map<ll,int>mp;
int dfs(ll x){
    if(mp.count(x))return mp[x];
    ll y=x,b=0;
    while(y){
        if(y%10>1)b|=1<<(y%10-2);
        y/=10;
    }
    if(get(x)==n){
        return 0;
    }
    int rex=1e9;
    for(int i=9;i>=2;--i){
        if(b>>(i-2)&1)rex=min(rex,dfs(x*i)+1);
    }
    return mp[x]=rex;
}
int main(){
    unsigned long long y;
    cin>>n>>y;
    x=y;
    int rex=dfs(x);
    cout<<(rex>=1e9?-1:rex)<<endl;
    return 0;
}