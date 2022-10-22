#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,m;
int num[Maxn+5];
int ans;
void add(int x){
	if(num[x]==0){
		ans--;
	}
	num[x]++;
}
void del(int x){
	num[x]--;
	if(num[x]==0){
		ans++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	ans=n;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u<v){
			std::swap(u,v);
		}
		add(v);
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u<v){
				std::swap(u,v);
			}
			add(v);
		}
		else if(op==2){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u<v){
				std::swap(u,v);
			}
			del(v);
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}