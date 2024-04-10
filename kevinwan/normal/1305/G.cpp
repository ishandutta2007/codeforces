#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=1<<18;
int a[mn];
int num[mn];
ll ans;
int p[mn],ad;
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
inline void u(int a,int b){
    a=f(a),b=f(b);
    if(a==b)return;
    if(!num[a]||!num[b])return;
    ans+=1LL*(ad)*(num[a]+num[b]-1);
    p[b]=a;
    num[a]=1;
}
int main(){
    int n;
    scanf("%d",&n);
    num[0]++;
    for(int i=1;i<=n;i++)scanf("%d",a+i),ans-=a[i],num[a[i]]++;
    iota(p,p+mn,0);
    for(int i=mn-1;i;i--){
        ad=i;
        for(int j=0;j*2<=i;){
            int k=i-j;
            u(j,k);
            int lo=i&(~j);
            lo=lo&-lo;
            j&=~(lo-1);
            j|=lo;
        }
    }
    printf("%lld",ans);
}