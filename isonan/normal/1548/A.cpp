#include <cstdio>

int n,m;
int cnt[200001],ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(u>v)++cnt[v];
		else ++cnt[u];
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=n;++i)if(!cnt[i])++ans;
	for(int i=1,opt,u,v;i<=q;++i){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&u,&v);
			if(!cnt[u])--ans;
			if(!cnt[v])--ans;
			if(u>v)++cnt[v];
			else ++cnt[u];
			if(!cnt[u])++ans;
			if(!cnt[v])++ans;
		}
		else if(opt==2){
			scanf("%d%d",&u,&v);
			if(!cnt[u])--ans;
			if(!cnt[v])--ans;
			if(u>v)--cnt[v];
			else --cnt[u];
			if(!cnt[u])++ans;
			if(!cnt[v])++ans;
		}
		else printf("%d\n",ans);
	}
}