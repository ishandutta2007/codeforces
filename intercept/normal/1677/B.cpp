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
int n,m;
char s[M];
int b[M],c[M],ans[M];
void work(){
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n*m;++i){
        b[i]=c[i]=ans[i]=0;
    }
    for(int i=1;i<=n*m;++i){
        b[i]=b[i-1]+(s[i]=='1');
        if(i>=m)ans[i]=ans[i-m];
        ans[i]+=((b[i]-b[max(0,i-m)])>0);
    }
    for(int i=1;i<=n*m;++i){
        if(i>=m)c[i]=c[i-m];
        c[i]+=(s[i]=='1');
        b[i]=b[i-1]+(c[i]>0);
        ans[i]+=b[i]-b[max(0,i-m)];
    }
    for(int i=1;i<=n*m;++i){
        printf("%d%c",ans[i]," \n"[i==n*m]);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
2 4
11001101
*/