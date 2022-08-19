#include <cstdio>
#include <vector> 

int head[1000001],nxt[2000001],b[2000001],k=1,n,m;
int d[1000001],q[1000001],h,t;
bool cnt[1000001],vis[1000001],need[1000001];
std::vector<int>vec;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u];
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			need[i]=1;
			for(int j=head[i];j;j=nxt[j])
				if(!(j&1))vis[b[j]]=1;
		}
	for(int i=n;i;i--){
		if(!need[i])continue;
		bool hav=0;
		for(int j=head[i];j;j=nxt[j])
			if(j&1)hav|=cnt[b[j]];
		if(!hav){
			vec.push_back(i);
			cnt[i]=1;
		} 
	}
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++)printf("%d ",vec[i]);
}