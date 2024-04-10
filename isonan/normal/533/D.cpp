#include <cstdio>
#include <algorithm>
using namespace std;

int x[100010],d[100001],R[100010],L[100010],stk[100010],top,n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)scanf("%d",x+i);
	for(int i=1;i<=n;i++)scanf("%d",d+i);
	d[0]=d[n+1]=0x7f7f7f7f;
	for(int i=0;i<=n+1;i++){
		while(top>1&&x[i]-x[stk[top-1]]>(d[stk[top]]<<1))--top;
		stk[++top]=i;
		if(x[i]-x[stk[top-1]]>=(d[i]<<1))R[i]=-0x7f7f7f7f;
		else R[i]=(d[i]<<1)+x[stk[top-1]];
	}
	R[0]=R[n+1]=0x7f7f7f7f;
	if(top>2){
		puts("0");
		return 0;
	}
	top=0;
	for(int i=n+1;~i;i--){
		while(top>1&&x[stk[top-1]]-x[i]>(d[stk[top]]<<1))--top;
		stk[++top]=i;
		if(x[stk[top-1]]-x[i]>=(d[i]<<1))L[i]=0x7f7f7f7f;
		else L[i]=x[stk[top-1]]-(d[i]<<1);
	}
	L[0]=L[n+1]=-0x7f7f7f7f;
	top=0;
	int fin=x[n+1]-x[0];
	for(int i=n+1;i;--i){
		while(top&&L[stk[top]]>=L[i])--top;
		stk[++top]=i;
		if(R[i-1]==-0x7f7f7f7f)continue;
		int l=1,r=top,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(R[i-1]>=L[stk[mid]]&&(L[stk[mid]]!=0x7f7f7f7f))ans=mid,l=mid+1;
			else r=mid-1;
		}
//		if(ans!=-1)printf("%d %d\n",stk[ans],i-1);
		if(ans!=-1)fin=min(fin,x[stk[ans]]-x[i-1]);
	}
//	for(int i=0;i<=n+1;i++)printf("%d ",R[i]);putchar('\n');
//	for(int i=0;i<=n+1;i++)printf("%d ",L[i]);putchar('\n');
	if(fin&1)printf("%d.5",fin>>1);
	else printf("%d",fin>>1);
}