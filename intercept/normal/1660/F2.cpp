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
const int M=200009;
int n;
char s[M];
int bit[3][M<<1];
void add(int *b,int x,int v){
    for(;x<M<<1;x+=x&-x)b[x]+=v;
}
int ask(int *b,int x,int rex=0){
    for(;x;x-=x&-x)rex+=b[x];
    return rex;
}
void work(){
    cin>>n>>(s+1);
    int p=n+5;
    ll ans=0;
    add(bit[p%3],p,1);
    for(int i=1;i<=n;++i){
        if(s[i]=='+')p--;
        else p++;
        ans+=ask(bit[p%3],p);
 //       cout<<ans<<endl;
        add(bit[p%3],p,1);
    }
    p=n+5;
    add(bit[p%3],p,-1);
    for(int i=1;i<=n;++i){
        if(s[i]=='+')p--;
        else p++;
        add(bit[p%3],p,-1);
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
20
------+-++++--++++--



*/