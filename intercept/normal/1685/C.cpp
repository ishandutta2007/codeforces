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
const int M=2e5+9;
int n;
char s[M];
int a[M],b[M];
void work(){
    vector<pii>ans;
    scanf("%d%s",&n,s+1);
    int mi=1e9,p=-1;
    n*=2;
    for(int i=1;i<=n;++i){
        a[i]=a[i-1]+((s[i]=='(')?1:-1);
        mi=min(mi,a[i]);
    }
    if(mi>=0){
        puts("0");
        return;
    }
    int l=n+1,r=0;
    for(int i=1;i<=n;++i){
        if(a[i]<0)l=min(l,i),r=max(r,i);
    }
    int p0=-1,p1=-1,p2=-1;
    for(int i=0;i<l;++i){
        if(p0==-1||a[p0]<a[i])p0=i;
    }
    for(int i=r+1;i<=n;++i){
        if(p1==-1||a[p1]<a[i])p1=i;
    }
    for(int i=l;i<=r;++i){
        if(p2==-1||a[p2]<a[i])p2=i;
    }
    if(a[p0]+a[p1]-a[p2]>=0){
        puts("1");
        printf("%d %d\n",p0+1,p1);
        return;
    }
    for(int i=0;i<=n;++i){
        if(p==-1||a[p]<a[i])p=i;
    }
    puts("2");
    printf("%d %d\n%d %d\n",1,p,p+1,n);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*

1
6
()()()))()((

*/