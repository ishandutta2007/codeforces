#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define mo 1000000007
typedef long long ll;
int qp(int a,int b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);
    return ans;
}
int n,q;
int a[2000005];


int fa[2000005];
int nex[2000005];
int h[2000005];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
int work(int b){
    a[2*n+1]=10000000000000000ll;
    ll su=0;
    for (int i=1,j=0;i<=2*n;i++){
        while(su<=b)su+=a[++j];
        nex[i]=j;
        su-=a[i];
    }
    h[2*n+1]=0;
    for (int i=2*n;i>=1;i--)h[i]=h[nex[i]]+1;
    int ans=int(1e9);
    for (int i=1;i<=2*n+1;i++)fa[i]=i;
    for (int i=1;i<=n;i++){
        while(gf(i)<i+n){
            fa[gf(i)]=nex[gf(i)];
        }
        ans=min(ans,h[i]-h[gf(i)]);
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=n+1;i<=2*n;i++)a[i]=a[i-n];
    while(q--){
        int b;scanf("%d",&b);
        printf("%d\n",work(b));
    }
    return 0;
}