#include <cstdio>
#include <algorithm>

int m,n,a[100001],tem[200001],nxt[200001],f[200001],g[200001],b[100001];
int pos(int x){return (x%m+m)%m;}
int vis[200001];
bool solve(int *a,int u){
	for(int i=1;i<=n;i++)tem[i]=a[i],tem[i+n]=a[i]+u;
	tem[(n<<1)+1]=-1;
	int top=0;
	std::sort(tem+1,tem+(n<<1)+2);
	top=std::unique(tem+1,tem+(n<<1)+2)-tem-1;
	for(int i=1;i<=top;i++)vis[i]=1;
	for(int i=top,j=n,last=-1;i;i--){
		nxt[i]=last;
		if(j&&tem[i]==a[j]){
			vis[i]=j;
			last=i;
			--j;
		}
	}
//	puts("");
	for(int i=n;i;i--){
		g[i]=a[i]+u;
		int v=std::upper_bound(a+1,a+n+1,a[i]+u+1)-a-1;
		g[i]=g[v];
//		printf("%d %d\n",a[i],g[i]);
	}
	for(int i=1;i<=top;i++)f[i]=-1;
	f[1]=0;
	if(g[1]>=m-1)return 1;
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
//	printf("%d\n",g[1]);
//	printf("solve %d\n",u);
	tem[1]=0;
	f[std::lower_bound(tem+1,tem+top+1,u)-tem]=0;
	for(int i=1;i<=top;i++){
//		printf("%d %d %d\n",tem[i],f[i],tem[nxt[i]]);
		if(!~f[i])continue;
		if(tem[i]+1+f[i]>=m)return 1;
		if(~nxt[i]&&tem[nxt[i]]-tem[i]<=u+1)f[nxt[i]]=std::max(f[nxt[i]],std::max(f[i],u-tem[nxt[i]]));//,printf("%d\n",tem[nxt[i]]);
		if(~nxt[i]&&tem[nxt[i]]==tem[i]+1){
			int v=std::lower_bound(tem+1,tem+top+1,g[vis[nxt[i]]])-tem;
			f[v]=std::max(f[v],f[i]);
		} 
		if(~nxt[i]&&~nxt[nxt[i]]&&tem[nxt[nxt[i]]]-tem[i]<=u+1){
			int v;
			if(~nxt[nxt[nxt[i]]]&&tem[nxt[nxt[nxt[i]]]]-tem[nxt[i]]<=u+1)v=g[vis[nxt[nxt[nxt[i]]]]];
			else v=tem[nxt[i]]+u;
//			printf("-%d %d %d\n",v,tem[nxt[i]],tem[nxt[nxt[nxt[i]]]]);
			v=std::lower_bound(tem+1,tem+top+1,v)-tem;
			f[v]=std::max(f[v],std::max(f[i],u-tem[nxt[nxt[i]]]));
		}
	}
	return 0;
}
bool judge(int u){
	return solve(a,u)|solve(b,u);
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(int i=n;i;i--)a[i]-=a[1];
	for(int i=1;i<=n;i++)b[i]=(i==1)?a[1]:(m-a[n+2-i]);
//	solve(a,7);
//	solve(b,7);
	int l=0,r=m,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}