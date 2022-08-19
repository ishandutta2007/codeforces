#include <cstdio>

int t,n,k,a[200001],b[200001],time[200001],ord[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",a+i),time[i]=0,ord[a[i]]=i;
		for(int i=1;i<=k;i++)scanf("%d",b+i),time[b[i]]=i;
		int ans=1;
		for(int i=1;i<=k;i++){
			int cnt=0;
			if(ord[b[i]]>1&&time[a[ord[b[i]]-1]]<i)++cnt;
			if(ord[b[i]]<n&&time[a[ord[b[i]]+1]]<i)++cnt;
			ans=1ll*ans*cnt%998244353;
		}
		printf("%d\n",ans);
	}
}