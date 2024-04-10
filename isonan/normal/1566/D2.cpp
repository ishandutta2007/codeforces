#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,m,a[100001],orig[100001],tot[100001],now[100001];
bool vis[100001];
std::vector<int>s[100001];
bool cmp(int a,int b){
	if((a-1)/m==(b-1)/m)return a<b;
	else return a>b;
}
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
		for(int i=1;i<=cnt;++i){
			s[i].clear();
			for(int j=tot[i-1]+1;j<=tot[i];++j)s[i].push_back(j);
			std::sort(s[i].begin(),s[i].end(),cmp);
		}
		int ans=0;
		for(int i=1;i<=n*m;++i){
			int pos=::s[a[i]].back(),s=((pos-1)/m)*m+1;
			::s[a[i]].pop_back();
			// printf("%d %d %d %d\n",i,pos,a[i]);
			for(int j=s;j<pos;++j)
				if(vis[j])++ans;
			vis[pos]=1;
		}
		printf("%d\n",ans);
	}
}