#include <cstdio>
#include <vector>
#include <cstring>

int T;
int n,m;
bool get(){
	char ch=getchar();
	while(ch!='O'&&ch!='X')ch=getchar();
	return (ch=='X');
}
int map[21][21],con[4001][2],top,cnt[4001],head[401],nxt[100001],b[100001],k=1,dis[4001],pre[4001];
char ans[41][41];
int q[4001],h,t;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool iscut[4001],chosen[4001],lim[4001],good[4001][4001];
std::vector<int>vec[4001];
int Cnt;
int hash(int i,int j){return (i-1)*m+j;}
void dfs(int x,bool *vis){
	if(vis[x])return;
	++Cnt;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!chosen[i>>1])dfs(b[i],vis);
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d",&n,&m);
		int all=0;
		top=0;
		memset(chosen,0,sizeof chosen);
		memset(lim,0,sizeof lim);
		memset(head,0,sizeof head);
		k=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				map[i][j]=get(),all+=(!map[i][j]);
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++)
				if(!map[i][j]&&!map[i+1][j]){
					++top;
					con[top][0]=hash(i,j);
					con[top][1]=hash(i+1,j);
					push(hash(i,j),hash(i+1,j));
					push(hash(i+1,j),hash(i,j));
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++)
				if(!map[i][j]&&!map[i][j+1]){
					++top;
					con[top][0]=hash(i,j);
					con[top][1]=hash(i,j+1);
					push(hash(i,j),hash(i,j+1));
					push(hash(i,j+1),hash(i,j));
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if((i+j)%2==0&&(i>1||j>1))lim[hash(i,j)]=1;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=top;i++){
			++cnt[con[i][0]],++cnt[con[i][1]];
		}
		bool cando=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(lim[hash(i,j)]&&cnt[hash(i,j)]<=1&&!map[i][j]){
					cando=0;
				}
		memset(good[0],0,sizeof good[0]);
		Cnt=0;
		dfs(1,good[0]);
		if(Cnt<all)cando=0;
		if(!cando)puts("NO");
		else{
	//		for(int i=1;i<=top;i++)printf("%d %d\n",con[i][0],con[i][1]);
			for(;;){
				memset(cnt,0,sizeof cnt);
				for(int i=1;i<=top;i++)
					if(!chosen[i]){
						if(lim[con[i][0]])++cnt[con[i][0]];
						else ++cnt[con[i][1]];
						Cnt=0;
						chosen[i]=1;
						memset(good[i],0,sizeof good[i]);
						dfs(1,good[i]);
						iscut[i]=(Cnt<all);
	//					printf("%d %d\n",i,iscut[i]);
						chosen[i]=0;
					}
				for(int i=1;i<=top;i++)vec[i].clear();
				for(int i=1;i<=top;i++)
					if(chosen[i])
						for(int j=1;j<=top;j++)
							if(!chosen[j]){
								int u=(lim[con[i][0]]?con[i][0]:con[i][1]),v=(lim[con[j][0]]?con[j][0]:con[j][1]);
								if(u==v||cnt[v]>=3){
	//								printf("edge %d %d\n",j,i);
									vec[j].push_back(i);
								}
								if(!iscut[j]||good[j][con[i][0]]!=good[j][con[i][1]]){
	//								printf("edge %d %d\n",i,j);
									vec[i].push_back(j);
								}
							}
				h=t=0;
				for(int i=1;i<=top;i++){
					dis[i]=0x7f7f7f7f;
					pre[i]=0;
					if(!chosen[i]&&!iscut[i])dis[i]=0,q[++t]=i;
				}
				while(h<t){
					++h;
					for(int i=0;i<vec[q[h]].size();i++)
						if(dis[vec[q[h]][i]]==0x7f7f7f7f){
							dis[vec[q[h]][i]]=dis[q[h]]+1;
							q[++t]=vec[q[h]][i];
							pre[vec[q[h]][i]]=q[h];
						}
				}
				int p=0;
				for(int i=1;i<=top;i++){
					if(!chosen[i]&&(cnt[con[i][0]]>=3||!lim[con[i][0]])&&(cnt[con[i][1]]>=3||!lim[con[i][1]])&&dis[i]!=0x7f7f7f7f){
	//					printf("%d %d\n",con[i][0],con[i][1]);
						if(!p||dis[p]>dis[i])p=i;
					}
				}
				if(!p)break;
				while(p){
					chosen[p]^=1;
					p=pre[p];
				}
			}
			Cnt=0;
			for(int i=1;i<=top;i++)Cnt+=(!chosen[i]);
			if(Cnt!=all-1)puts("NO");
			else{
				puts("YES");
				for(int i=1;i<=(n<<1);i++)
					for(int j=1;j<=(m<<1);j++)
						ans[i][j]=' ';
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)
						ans[(i<<1)-1][(j<<1)-1]=(map[i][j])?'X':'O';
				for(int i=1;i<=top;i++)
					if(!chosen[i]){
						int u=con[i][0],v=con[i][1];
		//				printf("%d %d\n",u,v);
						if(v==u+1)ans[(((u-1)/m+1)<<1)-1][((u-1)%m+1)<<1]='O';
						else ans[(((u-1)/m+1)<<1)][(((u-1)%m+1)<<1)-1]='O';
					}
				for(int i=1;i<(n<<1);i++,putchar('\n'))
					for(int j=1;j<(m<<1);j++)
						putchar(ans[i][j]);
			}
		}
	}
}