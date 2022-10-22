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
const int M=1e6+9;

int n;
char s[M];
int f[M],p[M];
vector<int>g[M];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n+1;++i)f[i]=i;
    for(int i=n,l=n+1,r=n+1;i>=1;--i){
        if(s[i]=='1')l=i,p[i]=r-i;
        if(s[i]=='0')r=i,p[i]=l-i;
        if(s[i]=='?')p[i]=max(r-i,l-i);
        g[p[i]].eb(i);
    }
    for(int x=1;x<=n;++x){
        int ans=0,l=1;
        while(l<=n){
            l=find(l);
            if(l>n)break;
            ans++;
            l+=x;
        }
        for(auto o:g[x]){
            f[find(o)]=find(o+1);
        }
        printf("%d%c",ans," \n"[x==n]);
    }
    return 0;
}