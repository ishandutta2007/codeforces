#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
ll a[maxn],b[maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++)b[i]=read();
    ll g=0;
    for(int i=2;i<=n;i++)g=gcd(g,a[i]-a[1]);
    for(int i=1;i<=m;i++)printf("%lld ",gcd(a[1]+b[i],g));
    return 0;
}