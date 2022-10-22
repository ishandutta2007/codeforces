#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
double a[mn],ra[mn];
double dp[2][mn];
int cl=1,cr=0;
double cur=0,cs=0,cis=0;
void ru(){cr++;cs+=a[cr];cis+=ra[cr];cur+=cs*ra[cr];}
void rd(){cur-=cs*ra[cr];cis-=ra[cr];cs-=a[cr];cr--;}
void ld(){cl--;cs+=a[cl];cis+=ra[cl];cur+=cis*a[cl];}
void lu(){cur-=cis*a[cl];cis-=ra[cl];cs-=a[cl];cl++;}
void hail(int l,int r,int pl,int pr){
    if(r<l)return;
    int mid=(l+r)>>1;
    while(cr>mid)rd();
    while(cr<mid)ru();
    while(cl<pl+1)lu();
    while(cl>pl+1)ld();
    int bes=-1;
    for(int i=pl;i<=min(pr,mid-1);i++,lu()){
        if(dp[0][i]+cur<dp[1][mid])dp[1][mid]=dp[0][i]+cur,bes=i;
    }
    hail(l,mid-1,pl,bes),hail(mid+1,r,bes,pr);
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lf",a+i),ra[i]=1/a[i];
    for(int i=1;i<=n;i++)dp[0][i]=dp[1][i]=1e300;
    for(int i=0;i<k;i++){
        hail(1,n,0,n-1);
        memcpy(dp[0],dp[1],sizeof(dp[0]));
        for(int i=1;i<=n;i++)dp[1][i]=1e300;
    }
    printf("%.20lf",dp[0][n]);
}