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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n;

int a[422222];
int ma[222222];
int bo[422222];
int gc[222222];
int lis[222222];
ll ans=0;
void work(int d){
    for (int i=0;i<d;i++)ma[i]=0;
    for (int i=0,j=0;i<n;i++,(++j)==d?j=0:0){
        if(gc[i]==d)lis[i]=1;else lis[i]=0;
        ma[j]=max(ma[j],a[i]);
    }
    lis[n]=0;
    for (int i=1;i<=n;i++)lis[i]+=lis[i-1];
    for (int i=0,j=0;i<2*n;i++,(++j)==d?j=0:0)bo[i]=(a[i]>=ma[j]);
    for (int i=2*n-2;i>=0;i--){
        if(bo[i])bo[i]+=bo[i+1];
    }
    for (int i=0;i<n;i++)ans+=lis[min(n,bo[i])];
}
int main()
{
    //freopen("1.in","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    for (int i=0;i<n;i++)a[i+n]=a[i];
    for (int i=0;i<n;i++)gc[i]=gcd(i,n);
    for (int d=1;d<n;d++)if(n%d==0)work(d);
    cout<<ans<<endl;
    return 0;
}