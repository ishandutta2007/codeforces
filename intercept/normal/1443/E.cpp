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
const int M=200009;
int n,q;
ll s,p[M],fac[M];
int bit[M];
void add(int x,int v){
    for(;x<=n;x+=x&-x)bit[x]+=v;
}
int ask(int x,int rex=0){
    for(;x;x-=x&-x)rex+=bit[x];
    return rex;
}
int kth(int k,int y=0){//find k_th element
    for(int i=1<<20;i;i>>=1)
        if(y+i<n&&bit[y+i]<k)k-=bit[y+=i];
    return y+1;
}
int main(){
    scanf("%d%d",&n,&q);
    int L=max(1,n-14);
    fac[0]=1;
    for(int i=1;i<=15;++i)fac[i]=fac[i-1]*i;
    for(int i=1;i<=n;++i)p[i]=p[i-1]+i;
    for(int i=1;i<=q;++i){
        int o;
        scanf("%d",&o);
        if(o==1){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",p[r]-p[l-1]);
        }
        else{
            int x;
            scanf("%d",&x);
            s+=x;
            for(int i=L;i<=n;++i){
                bit[i]=0;
            }
            for(int i=L;i<=n;++i){
                add(i,1);
            }
            for(int i=L;i<=n;++i){
                int y=(s%fac[n-i+1])/fac[n-i]+1;
                int z=kth(y);
                add(z,-1);
                p[i]=p[i-1]+z;
            }
        }
    }
    return 0;
}