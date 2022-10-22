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
    else y-=1ll*a/b*x%(mod-1);
    return t;
}
const int M=2e5+9;
int n,k,m;
struct mat{
    int a[109][109];
    mat(){
        for(int i=1;i<=k;++i)
        for(int j=1;j<=k;++j)
            a[i][j]=0;
    }
    int* operator [] (int x){return a[x];}
    void operator = (int x){
        for(int i=1;i<=k;++i)a[i][i]=x;
    }
    mat operator * (mat&o){
        mat rex;
        for(int i=1;i<=k;++i)
        for(int j=1;j<=k;++j)
        for(int t=1;t<=k;++t)
            rex[i][j]=(rex[i][j]+1ll*a[i][t]*(o[t][j])%(mod-1))%(mod-1);
        return rex;
    }
}b;
mat kpow(mat x,int t){
    mat rex;
    rex=1;
    for(;t;t>>=1,x=x*x){
        if(t&1)rex=rex*x;
    }
    return rex;
}
int bsgs(int a,int b,int p){
    map<int,int>mp;
    int l=ceil(sqrt(p));
    for(int i=1;i<=l;++i){
        mp[kpow(a,i*l)]=i*l;
    }
    for(int i=0;i<l;++i){
        int x=1ll*b*kpow(a,i)%mod;
        if(mp.count(x))return mp[x]-i;
    }
    return -1;
}
int main(){
    scanf("%d",&k);
    for(int i=1;i<=k;++i){
        scanf("%d",&b[k-i+1][k]);
    }
    for(int i=2;i<=k;++i){
        b[i][i-1]=1;
    }
    scanf("%d%d",&n,&m);
    b=kpow(b,n-k);
    int t=b[k][k];
    int ans=bsgs(3,m,mod);
    if(ans==-1||ans%__gcd(mod-1,t))puts("-1");
    else{
        int x,y;
        exgcd(t,mod-1,x,y);
        x=(x+mod-1)%(mod-1);
        x=1ll*x*ans/__gcd(t,mod-1)%(mod-1);
        x=kpow(3,x);
        printf("%d\n",x);
    }
    return 0;
}
/*
4 4
1 2
1 3
1 4


*/