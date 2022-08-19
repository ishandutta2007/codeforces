#include <cstdio>
#include <algorithm>

int t,n,m,a[100001],orig[100001],tot[100001];
bool vis[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;++i)scanf("%d",a+i),orig[i]=a[i];
		std::sort(orig+1,orig+n*m+1);
		int cnt=std::unique(orig+1,orig+n*m+1)-orig-1;
		for(int i=1;i<=n*m;++i)a[i]=std::lower_bound(orig+1,orig+cnt+1,a[i])-orig;
		for(int i=0;i<=cnt;++i)tot[i]=0;
		for(int i=1;i<=n*m;++i)++tot[a[i]],vis[i]=0;
		for(int i=1;i<=cnt;++i)tot[i]+=tot[i-1];
		int ans=0;
		for(int i=1;i<=n*m;++i){
			int pos=tot[a[i]]--,s=((pos-1)/m)*m+1;
			// printf("%d %d %d %d\n",i,pos,a[i]);
			for(int j=s;j<pos;++j)
				if(vis[j])++ans;
			vis[pos]=1;
		}
		printf("%d\n",ans);
	}
}