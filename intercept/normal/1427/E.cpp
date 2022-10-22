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
const int M=1000009;
int n;
vector<ll>v;
mt19937 rd(time(0));
struct P{
    ll x;
    char o;
    ll y;
};
vector<P>ans;
void out(ll x){
    if(x==1){
        cout<<ans.size()<<endl;
        for(auto o:ans){
            cout<<o.x<<" "<<o.o<<" "<<o.y<<endl;
        }
        exit(0);
    }
}



const int X=60;
int lbt0;
ll lb[X+9],lbt[X+9];
void add(ll x){
    for(int i=X;i>=0;--i){
        if(x>>i&1){
            if(!lb[i]){
                lb[i]=x;
                break;
            }
            ans.eb(P{x,'^',lb[i]});
            x^=lb[i];
            out(x);
        }
    }
}
bool check(ll x){
    for(int i=X;i>=0;--i){
        if(x>>i&1){
            if(!lb[i])return 0;
            x^=lb[i];
        }
    }
    return 1;
}
void con(){
    for(int i=0;i<=X;++i){
        for(int j=0;j<i;++j){
            if(lb[i]&&lb[i]>>j&1)lb[i]^=lb[j];
        }
        if(lb[i])lbt[lbt0++]=lb[i];
    }
}
ll kth(ll k,ll rex=0){
    if(k>=1ll<<lbt0)return -1;
    for(int i=0;i<lbt0;++i){
        if(k>>i&1)rex^=lbt[i];
    }
    return rex;
}

void get(){
    int len=v.size();
    ll l=v[rd()%len],r=v[rd()%len],p;
    char o=(rd()%2==0)?'+':'^';
    if(o=='+')p=l+r;
    else p=l^r;
    if(p<=1e18&&!check(p)){
        ans.eb(P{l,o,r});
        v.eb(p);
        out(p);
        add(p);
    }
}

int main(){
    ll x;
    cin>>x;
    add(x);
    v.eb(x);
    while(1)get();
    return 0;
}
/*
8 2000
100 100 100 100 100 900 900 900
*/