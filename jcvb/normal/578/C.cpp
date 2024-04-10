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

int n;
int a[222222];
#define eps 1e-6

db b[222222];

db ca(){
    db an=-1e18;
    for (int i=1;i<=n;i++)an=max(an,b[i]);
    db su=0.0;
    for (int i=1;i<=n;i++){
        su+=b[i];
        an=max(an,su);
        if(su<0)su=0.0;
    }
    return an;
}
db gma(db x){
    for (int i=1;i<=n;i++)b[i]=a[i]-x;
    return ca();
}
db gmi(db x){
    for (int i=1;i<=n;i++)b[i]=-(a[i]-x);
    return -ca();
}
db cal(db x){
    db ma=gma(x);
    db mi=gmi(x);
    db an=max(fabs(ma),fabs(mi));
    return an;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    db l=-30000.0,r=30000.0,mid,mid2;
    int t=300;
    while(t--){
        mid=(l+r)/2;
        mid2=(mid+r)/2;
        db f1=cal(mid),f2=cal(mid2);
        if(f1>f2)l=mid;
        else r=mid2;
  
    }
    db an=gma(l);
    printf("%.18lf\n",an);
    return 0;
}