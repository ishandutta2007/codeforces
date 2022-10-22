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
const int M=109;
const int sed=131;
const int mod1=1e9+7;
const int mod2=1e9+87;
struct Hash{
    int x1,x2;
    Hash(int t1=0,int t2=0):x1(t1),x2(t2){}
    bool operator != (const Hash&o)const{return x1!=o.x1||x2!=o.x2;}
    bool operator == (const Hash&o)const{return x1==o.x1&&x2==o.x2;}
    bool operator <  (const Hash&o)const{return x1==o.x1?x2<o.x2:x1<o.x1;}
    Hash operator +  (const Hash&o)const{return Hash((x1+o.x1)%mod1,(x2+o.x2)%mod2);}
    Hash operator -  (const Hash&o)const{return Hash((x1-o.x1+mod1)%mod1,(x2-o.x2+mod2)%mod2);}
    Hash operator +  (const int&o)const{return Hash((x1+o)%mod1,(x2+o)%mod2);}
    Hash operator -  (const int&o)const{return Hash((x1+mod1-o)%mod1,(x2+mod2-o)%mod2);}
    Hash operator *  (const int&o)const{return Hash(1ll*x1*o%mod1,1ll*x2*o%mod2);}
    Hash operator *  (const Hash&o)const{return Hash(1ll*x1*o.x1%mod1,1ll*x2*o.x2%mod2);}
}pw[M],p;
int a[M];
int n;
map<Hash,int>mp;
void pre(){
    pw[0]=Hash(1,1);
    for(int i=1;i<n;++i)pw[i]=pw[i-1]*sed;
    for(int i=0;i<n;++i)p=p+pw[i];
}
int main(){
    scanf("%d",&n);
    pre();
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<1<<15;++i){
        Hash t;
        for(int j=0;j<n;++j){
            int x=__builtin_popcount((a[j]>>15)^i);
            t=t*sed+x;
        }
        mp[t]=i;
    }
    for(int i=0;i<1<<15;++i){
        Hash t;
        for(int j=0;j<n;++j){
            int x=__builtin_popcount((a[j]&((1<<15)-1))^i);
            t=t*sed+(30-x);
        }
        for(int k=0;k<=30;++k){
            Hash s=t-p*k;
            if(mp.count(s)){
                printf("%d\n",(mp[s]<<15)+i);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
/*
5
7 4 1 6 2
*/