#include <cstdio>
#include <algorithm>

int T,n,m,k,a[100001],b[100001],c[100001],fst[100001],lst[100001];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d%d",&n,&m,&k);
		--m;
		k=std::min(k,m);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=0;i<=m;i++)b[i]=std::max(a[i+1],a[n-m+i]);
		int ans=0;
		for(int i=0;i<=k;i++){
			int tem=0x7f7f7f7f,l=k-i;
			for(int j=0;j<=m;j++)
				if(j>=i&&l<=m-j)tem=std::min(tem,b[j]);
			ans=std::max(ans,tem);
		}
		printf("%d\n",ans);
	}
}