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
const int M=100009;
int n,m;
int a[M];
bool cmi(int x){
    for(int i=1,la=0;i<=n;++i){
        if(la>a[i])return 0;
        int y=la+x;
        if(y>=a[i])la=y;
        else la=a[i];
    }
    return 1;
}
int mi(){
    int l=1,r=m;
    while(l<r){
        int mid=l+r>>1;
        if(!cmi(mid))r=mid;
        else l=mid+1;
    }
    return l-1;
}
bool cma(int x){
    for(int i=1,la=0;i<=n;++i){
        if(i==n){
            if(la<a[n])return 0;
            return 1;
        }
        int y=la+x;
        if(y>=a[i])la=min(a[i+1],y);
        else return 0;
    }
    return 1;
}
int ma(){
    int l=1,r=m;
    while(l<r){
        int mid=l+r>>1;
        if(cma(mid))r=mid;
        else l=mid+1;
    }
    return l;
}
int s[M],f[M];
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    a[++n]=m;
    int l=mi(),r=ma();
    int la=0,ra=0;
    for(int i=1;i<n;++i){
        int nl=la+l,nr=ra+r;
        nl=max(nl,a[i]);
        nr=min(nr,a[i+1]);
        la=nl;
        ra=nr;
        s[i]=la;
        f[i]=ra;
    }
    for(int x=m,i=n-2;i>=0;--i){
        int nl=x-r,nr=x-l;
        int nx=min(nr,f[i]);
        s[i+1]=nx;
        f[i+1]=x;
        x=nx;
    }
    for(int i=1;i<n;++i)
        cout<<s[i]<<" "<<f[i]<<endl;
    return 0;
}
/*
4 1
5 9 1 2
TOTIENT 3 4
*/