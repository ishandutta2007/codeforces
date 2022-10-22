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
const int M=400009;
int a[M],sz;
int c[M][2];
int mi(int x){
    int rex=0,u=0;
    for(int i=16;i>=0;--i){
        int o=x>>i&1;
        if(c[u][o])u=c[u][o];
        else u=c[u][o^1],rex|=1<<i;
    }
    return rex;
}
int ma(int x){
    int rex=0,u=0;
    for(int i=16;i>=0;--i){
        int o=x>>i&1;
        if(c[u][o^1])u=c[u][o^1],rex|=1<<i;
        else u=c[u][o];
    }
    return rex;
}
void work(){
    int l,r;
    sz=0;
    cin>>l>>r;
    for(int i=l;i<=r;++i){
        int x;
        cin>>x;
        a[i]=x;
        int u=0;
        for(int j=16;j>=0;--j){
            int o=x>>j&1;
            if(!c[u][o])c[u][o]=++sz;
            u=c[u][o];
        }
    }
    int ans;
    for(int i=l;i<=r;++i){
        int x=a[i]^l;
        if(mi(x)==l&&ma(x)==r)ans=x;
    }
    cout<<ans<<endl;
    for(int i=0;i<=sz;++i)c[i][0]=c[i][1]=0;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
4 7
4 7 6 5


------+-++++--++++--



*/