#include <cstdio>
#include <set>
#include <vector>
#include <cstring>

int n,m,head[300001],nxt[1000010],b[1000010],k=1,T,con[500001][2];
std::set<int>set[300001],ans1,ans2;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void add(int x){
	for(int i=head[x];i;i=nxt[i])
		set[b[i]].insert(i>>1);
}
void del(int x){
	for(int i=head[x];i;i=nxt[i])
		set[b[i]].erase(i>>1);
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d",&n,&m);
		memset(head,0,(n*3+1)<<2);
		k=1;
		ans1.clear(),ans2.clear();
		for(int i=1;i<=n*3;i++)set[i].clear();
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			con[i][0]=u,con[i][1]=v;
			push(u,v);
			push(v,u);
		}
		for(int i=1;i<=n*3;i++){
			if(set[i].size()){
				int now=*set[i].begin();
				ans1.insert(now);
				if(con[now][0]==i)del(con[now][1]),ans2.erase(con[now][1]);
				else del(con[now][0]),ans2.erase(con[now][0]);
			}
			else{
				add(i);
				ans2.insert(i);
			}
		}
		if(ans1.size()>=n){
			puts("Matching");
			for(int i=0;i<n;i++)printf("%d ",*ans1.begin()),ans1.erase(*ans1.begin());putchar('\n');
		}
		else if(ans2.size()>=n){
			puts("IndSet");
			for(int i=0;i<n;i++)printf("%d ",*ans2.begin()),ans2.erase(*ans2.begin());putchar('\n');
		}
	}
}