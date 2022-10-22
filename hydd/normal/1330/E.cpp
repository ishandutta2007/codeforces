#include<cstdio>
using namespace std;
typedef long long ll;
int t,h,g,n,a[2100000],Log2[2100000];
int cnt,Ans[2100000];
ll ans;
int getd(int u){
	int ls=(u<<1),rs=(ls|1);
	if (!a[ls]&&!a[rs]) return u;
	else if (a[ls]>a[rs]) return getd(ls);
	else return getd(rs);
}
void work(int u){
	int ls=(u<<1),rs=(ls|1);
	if (!a[ls]&&!a[rs]){
		a[u]=0;
	}else
		if (a[ls]>a[rs]){
			a[u]=a[ls];
			work(ls);
		}
		else{
			a[u]=a[rs];
			work(rs);
		}
}
int main(){
	scanf("%d",&t);
	Log2[0]=-1;
	for (int i=1;i<=2097152;i++) Log2[i]=Log2[i>>1]+1;
	while (t--){
		scanf("%d%d",&h,&g);
		n=(1<<(h+1))-1;
		for (int i=1;i<=n;i++) a[i]=0;
		n=(1<<h)-1;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		cnt=0; ans=0;
		n=(1<<g)-1;
		for (int i=1;i<=n;i++)
			while (Log2[getd(i)]+1>g)
				work(i),Ans[++cnt]=i;
		for (int i=1;i<=n;i++) ans+=a[i];
		printf("%lld\n",ans);
		for (int i=1;i<cnt;i++) printf("%d ",Ans[i]);
		printf("%d\n",Ans[cnt]);
	}
	return 0;
}