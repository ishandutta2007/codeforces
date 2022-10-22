#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=2;
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
const int M=1<<21;
int inv[M],fac[M];
int c(int x,int y){
    return !(fac[x]-fac[y]-fac[x-y]);
}
int num,pw[40][M];
map<int,int>mp;
bool C(int x,int y){
    if(y>x||x<0)return 0;
    y=max(y,0);
    if(!mp.count(x)){
        mp[x]=++num;
        pw[num][0]=1;
        for(int i=1;i<=x;++i)pw[num][i]=(pw[num][i-1]+c(x,i))%2;
    }
    int z=mp[x];
    return y?((pw[z][x]-pw[z][y-1])%2+2)%2:pw[z][x];
}
void pre(){
    for(int i=2;i<M;++i){
        if(i%2==0)inv[i]=inv[i/2]+1;
        fac[i]=fac[i-1]+inv[i];
    }
}
int n,k;
int b[M],a[M];
bitset<1<<20>d;
int main(){
    scanf("%d%d",&n,&k);
    pre();
    for(int i=1;i<=n;++i){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;++i){
        int x=b[i],kk=2-(i==1)-(i==n);
        d[x]=d[x]^C(n-1-kk,max(k-kk,0));
        
        for(int j=i+1;j<=n;++j){
            kk=2-(i==1)-(j==n);
            for(int l=1;l<=b[j];++l){
                x=x*2;
                if(x>=1<<20)break;
            }
            if(x>=1<<20)break;
            d[x]=d[x]^C(n-1-(j-i)-kk,max(k-kk,0));
        }
    }
    bool flag=0;
    for(int i=(1<<20)-1;i>=0;--i){
        if(d[i]){
            flag=1;
        }
        if(flag||i==0)putchar('0'+d[i]);
    }
    return 0;
}