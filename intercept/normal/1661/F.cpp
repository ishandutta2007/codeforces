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
const int M=2e5+9;
int n,ans;
int a[M];
ll m,c;
ll cost(int x,int y){
    int d1=x/y,d2=x/y+1,n2=x%y,n1=y-n2;
    return 1ll*d1*d1*n1+1ll*d2*d2*n2;
}
ll red(int x,int y){
    if(y==0)return 0;
    return cost(x,y)-cost(x,y+1);
}
bool check(ll x){
    ans=c=0;
    for(int i=1;i<=n;++i){
        int d=a[i]-a[i-1];
        int l=1,r=d;
        while(l<r){
            int mid=l+r>>1;
            if(red(d,mid)>=x)l=mid+1;
            else r=mid;
        }
        ans+=l-1;
        c+=cost(d,l);
    }
    return c<=m;
}


int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    cin>>m;
    ll l=0,r=1e18;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid+1))l=mid+1;
        else r=mid;
    }
    check(l);
    cout<<ans-(m-c)/l<<endl;
    return 0;
}
/*
50
1 10 31 47 52 66 67 79 84 102 118 137 141 160 171 174 195 197 199 203 215 221 232 235 246 257 275 277 291 292 293 295 300 304 310 312 328 332 392 394 397 408 414 417 426 456 464 479 488 498
5366
*/