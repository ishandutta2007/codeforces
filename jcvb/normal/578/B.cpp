#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}

ll a[222222],b[222222];
ll pr[222222],su[222222];
int n;int k,x;
int main()
{
    scanf("%d",&n);
    scanf("%d%d",&k,&x);
    ll mi=1;
    for (int i=1;i<=k;i++)mi*=x;
    for (int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        a[i]=t;
        b[i]=1ll*t*mi;
    }
    pr[0]=su[n+1]=0;
    for (int i=1;i<=n;i++)pr[i]=a[i]|pr[i-1];
    for (int i=n;i>=1;i--)su[i]=a[i]|su[i+1];
    ll ma=0;
    for (int i=1;i<=n;i++){
        ll an=pr[i-1]|su[i+1]|b[i];
        ma=max(ma,an);
    }
    cout<<ma<<endl;
    return 0;
}