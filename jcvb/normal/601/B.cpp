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
const int inf=1061109567;
//const ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n,q;
int a[111111];
int b[111111];


int qu[111111];
int lef[111111],rig[111111];
ll work(int *a,int n){
    int q=0;
    int o2=a[n+1],o1=a[0];
    a[n+1]=a[0]=inf;
    for (int i=1;i<=n+1;i++){
        while(q && a[i]>a[qu[q-1]])
            rig[qu[--q]]=i;
        qu[q++]=i;
    }
    q=0;
    for (int i=n;i>=0;i--){
        while(q && a[i]>=a[qu[q-1]])
            lef[qu[--q]]=i;
        qu[q++]=i;
    }
    a[n+1]=o2;
    a[0]=o1;
    ll ans=0;
    for (int i=1;i<=n;i++)ans=ans+1ll*a[i]*(i-lef[i])*(rig[i]-i);
    return ans;
}
int main()
{
    gn(n);gn(q);
    for (int i=1;i<=n;i++)gn(a[i]);
    for (int i=1;i<n;i++)b[i]=abs(a[i]-a[i+1]);
    while(q--){
        int l,r;
        gn(l),gn(r);
        cout<<work(b+l-1,r-l)<<endl;
    }
    return 0;
}