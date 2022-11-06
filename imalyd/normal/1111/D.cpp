#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005,C=52,M=55;
ll p=1000000007;
#define add(a,b) (((a)+(b))%p)
#define sub(a,b) (((a)-(b)+p)%p)
#define mul(a,b) ((a)*(b)%p)
ll expo(ll a,ll b){
    ll c=1;
    while(b){
        if(b&1)c=c*a%p;
        b>>=1,a=a*a%p;
    }
    return c;
}
int n,q,type[N];ll a[N],b[N],sz[M],ans0,ans[M][M],k=1,fac[N];
char ch[N];
int main(){
	scanf("%s%d",ch+1,&q);n=strlen(ch+1);a[0]=1;
	for(int i=1;i<=n;i++){
		char c=ch[i];int t;
		if('a'<=c&&c<='z')t=c-'a'+1;else t=c-'A'+27;
		type[i]=t,++sz[t];//printf("%d:%d\n",i,t);
	}
	//for(int i=1;i<=C;i++)printf("sz[%d]=%d\n",i,sz[i]);
	//for(int i=1;i<=n;i++)printf("%d ",type[i]);printf("\n");
	for(int i=1;i<=n>>1;i++)k=mul(k,i);k=mul(k,k);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	for(int i=1;i<=C;i++)if(sz[i])k=mul(k,expo(fac[sz[i]],p-2));
	for(int i=1;i<=C;i++)if(sz[i])
		for(int j=n;j>=sz[i];j--)a[j]=add(a[j],a[j-sz[i]]);
	ans0=mul(k,a[n>>1]);k=mul(k,2);
	//printf("a");for(int i=0;i<=n;i++)printf(" %d",a[i]);printf("\n");
	for(int i=1;i< C;i++)if(sz[i])for(int j=i+1;j<=C;j++)if(sz[j]){
		int x=sz[i],y=sz[j];//printf("cal %d %d: %d %d %d\n",i,j,x,y,z);
		for(int i=0;i<=n;i++)b[i]=a[i];
		for(int i=x;i<=n;i++)b[i]=sub(b[i],b[i-x]);
		for(int i=y;i<=n;i++)b[i]=sub(b[i],b[i-y]);
		ans[i][j]=mul(k,b[n>>1]);
	}
	while(q--){
		int l,r;scanf("%d%d",&l,&r);l=type[l];r=type[r];
		if(r<l)swap(l,r);
		if(l==r)printf("%I64d\n",ans0);
		else printf("%I64d\n",ans[l][r]);
	}
	return 0;
}