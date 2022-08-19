#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#pragma GCC optimize(2)

std::set<std::pair<int,int> >set[2];
std::vector<int>leaves[40001];
int head[40001],nxt[40001],b[40001],k,d[40001],ds[40001],leaf[2],p[40001];
bool vis[40001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int n;
int end(int i){return set[i].rbegin()->second;}
int skd(int i){return (++set[i].rbegin())->second;}
int get(int x){int tem=leaves[x].back();leaves[x].pop_back();return tem;}
std::pair<int,int> pa(int x){return std::make_pair(ds[x],x);}
bool con[41][41];
int num[41];
void brute(int n,bool bb=0){
	if(!bb)for(int i=1,u,v;i<=((n-1)<<1);i++)scanf("%d%d",&u,&v),con[u][v]=con[v][u]=1;
	for(int i=1;i<=n;i++)num[i]=i+n;
	bool cando=1;
	do{
		cando=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(con[i][j]&&con[num[i]][num[j]])cando=0;
		if(cando)break;
	}while(std::next_permutation(num+1,num+n+1));
	if(!bb){
		if(!cando)puts("No");
		else{
			puts("Yes");
			for(int i=1;i<=n;i++)printf("%d ",num[i]);
		}
	}
}
int ord[20001],ind[40001],cn[2];
void getans(int cnt){
	if(cnt<=6){
		cn[1]=cnt;
		for(int i=0;i<2;i++)
			for(int j=1;j<=n;j++)
				if(d[i*n+j])ord[ind[i*n+j]=++cn[i]]=i*n+j;
		for(int i=1;i<=(n<<1);i++)
			if(d[i])
				for(int j=head[i];j;j=nxt[j])
					if(d[b[j]])con[ind[i]][ind[b[j]]]=1;
		brute(cnt,1);
		for(int i=1;i<=cnt;i++)p[ord[i]]=ord[num[i]];
		return;
	}
	for(int i=0;i<2;i++){
		if(cnt==ds[end(i)]+3){
			int now=end(i),P=0,other=get(skd(i)),t;
			p[P=get(end(i^1))]=now;
			for(int i=head[P];i;i=nxt[i])if(d[b[i]])p[b[i]]=other,t=b[i];
			for(int i=head[t];i;i=nxt[i])if(d[b[i]]&&!p[b[i]])p[b[i]]=get(now);
			for(int i=head[other];i;i=nxt[i])if(d[b[i]])leaves[now].push_back(b[i]);
			for(int j=1;j<=n;j++)if(!p[(i^1)*n+j]&&d[(i^1)*n+j])p[(i^1)*n+j]=get(now);
			for(int j=1;j<=n;j++)p[p[(i^1)*n+j]]=(i^1)*n+j;
			return;
		}
	}
	int node[4]={end(0),skd(0),end(1),skd(1)},extra[4]={0};
	for(int i=0;i<4;i++)extra[i]=get(node[i]),--d[extra[i]];
	for(int i=0;i<4;i++){
		set[(i&2)!=0].erase(pa(node[i]));
		--ds[node[i]];
		if((--d[node[i]])==1){
			for(int j=head[node[i]];j;j=nxt[j])
				if(d[b[j]]){
					set[(i&2)!=0].erase(pa(b[j]));
					++ds[b[j]];
					set[(i&2)!=0].insert(pa(b[j]));
					leaves[b[j]].push_back(node[i]);
				}
		}
//		printf("%d %d\n",node[i],extra[i]);
		set[(i&2)!=0].insert(pa(node[i]));
	}
//	puts("-------------");
	getans(cnt-2);
//	for(int i=1;i<=n;i++)printf("%d %d\n",i,p[i]);putchar('\n');
	if(p[node[0]]==node[2]||p[node[1]]==node[3])p[extra[0]]=extra[3],p[extra[1]]=extra[2];
	else p[extra[0]]=extra[2],p[extra[1]]=extra[3];
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	if(n<=5){brute(n);return 0;}
	for(int i=1,u,v;i<=((n-1)<<1);i++){
		scanf("%d%d",&u,&v);
		push(u,v),push(v,u);
		++d[u],++d[v];
	}
	for(int i=0;i<2;i++){
		for(int j=1;j<=n;j++){
			int v=i*n+j;
			if(d[v]==1){
				for(int i=head[v];i;i=nxt[i])
					++ds[b[i]],leaves[b[i]].push_back(v);
			}
		}
		for(int j=1;j<=n;j++)
			set[i].insert(std::make_pair(ds[i*n+j],i*n+j));
		if(ds[end(i)]==n-1){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	getans(n);
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
}