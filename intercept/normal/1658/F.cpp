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
const int M=2e5+9;
int n,m;
char s[M];
int p[M];
void work(){
    int num=0;
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='1')num++;
        p[i]=p[i-1]+(s[i]&1);
    }
    int z=__gcd(num,n-num);
    int x=num/z,y=(n-num)/z;
    if(m%(x+y)){
        puts("-1");
        return;
    }
    for(int i=m;i<=n;++i){
        if(p[i]-p[i-m]==m/(x+y)*x){
            puts("1");
            printf("%d %d\n",i-m+1,i);
            return;
        }
    }
    m=n-m;
    for(int i=m;i<=n;++i){
        if(p[i]-p[i-m]==m/(x+y)*x){
            puts("2");
            printf("%d %d\n%d %d\n",1,i-m,i+1,n);
            return;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
}