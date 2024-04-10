#include <vector>
#include <cstdio>
#include <cstring>

int n,p[2000001];
int head[2000001],nxt[4000001],b[4000001],k,d[2000001];
void push(int s,int t){
//	printf("push %d %d\n",s,t);
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int cnt=0;
bool vis[2000001];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]);
}
std::vector<std::pair<int,int> >vec[2000001];
bool did[2000001];
int stk[2000001],top;
void getans(int x){
	for(;vec[x].size();){
		if(did[vec[x].back().first>>1]){
			vec[x].pop_back();
			continue;
		}
		did[vec[x].back().first>>1]=1;
		int now=vec[x].back().second,y=vec[x].back().first;
//		printf("%d->%d\n",x,now);
		vec[x].pop_back();
		getans(now);
		stk[++top]=y;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++)scanf("%d",p+i);
	for(int i=20;~i;i--){
//		printf("%d\n",i);
		memset(head,0,sizeof head);
		memset(d,0,sizeof d);
		memset(vis,0,sizeof vis);
		k=0;
		for(int j=1;j<=(n<<1);j+=2){
			push(p[j]&((1<<i)-1),p[j+1]&((1<<i)-1));
			push(p[j+1]&((1<<i)-1),p[j]&((1<<i)-1));
			++d[p[j]&((1<<i)-1)],++d[p[j+1]&((1<<i)-1)];
		}
		cnt=0;
		for(int j=0;j<(1<<i);j++)
			if(d[j]&&!vis[j]){
				++cnt;
				dfs(j);
			}
		for(int j=0;j<(1<<i);j++)
			if(d[j]%2)cnt=2;
		if(cnt>1)continue;
//		printf("%d\n",i);
		for(int j=1;j<=(n<<1);j+=2){
			int v1=p[j]&((1<<i)-1),v2=p[j+1]&((1<<i)-1);
			vec[v1].push_back(std::make_pair(j-1,v2));
			vec[v2].push_back(std::make_pair(j,v1));
		}
		for(int j=0;j<1<<i;j++)
			if(d[j]){
				getans(j);
				break;
			}
		printf("%d\n",i);
//		for(int j=1;j<=top;j++)printf("%d ",stk[j]);putchar('\n');
		for(int j=1;j<=top;j++){
			stk[j]^=1;
			if(stk[j]%2==0)printf("%d %d ",stk[j]+1,stk[j]+2);
			else printf("%d %d ",stk[j]+1,stk[j]);
		}
		return 0;
	}
}