#include<cstdio>
#include<cassert>
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


int fac[222222];
int ifac[222222];
inline int calc(int m,int n){
    return 1ll*fac[m+n]*ifac[m]%mo*ifac[n]%mo;
}
int h,w,n;
struct pt{
    int x,y;
}a[2222];
int cmp(const pt&a,const pt&b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
inline int dis(int i,int j){
    if(a[i].x>a[j].x || a[i].y>a[j].y)return 0;
    return calc(a[j].x-a[i].x,a[j].y-a[i].y);
}

int f[2222][2];
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    ifac[0]=fac[0]=1;
    for (int i=1;i<=211111;i++){
        fac[i]=1ll*fac[i-1]*i%mo;
        ifac[i]=qp(fac[i],mo-2);
    }
    for (int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++){
        f[i][1]=calc(a[i].x-1,a[i].y-1);
        for (int j=1;j<i;j++){
            f[i][0]=(f[i][0]+1ll*f[j][1]*dis(j,i))%mo;
            f[i][1]=(f[i][1]+1ll*f[j][0]*dis(j,i))%mo;
        }
    }
    int ans=calc(h-1,w-1);
    for (int i=1;i<=n;i++){
        ans=(ans+1ll*f[i][0]*calc(h-a[i].x,w-a[i].y))%mo;
        ans=(ans-1ll*f[i][1]*calc(h-a[i].x,w-a[i].y))%mo;
    }
    ans=(ans+mo)%mo;
    printf("%d\n",ans);
    return 0;
}