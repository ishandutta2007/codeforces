#include <algorithm>
#include <cstdio>
#include <set>

std::set<int>set[1000010];
int h,w,q;
bool map[1010][1010];
int f[1000010],p[11][2],head[1000010],nxt[100001],b[100001],k;
int stk[1000010],top;
int vis[1000010];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void Link(int s,int t){
//	printf("%d %d\n",s,t);
	push(s,t);
	push(t,s);
}
int hash(int i,int j){return (i-1)*w+j;}
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u>v)std::swap(u,v);
	if(u!=v)f[u]=v;
} 
bool get(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return (ch=='#');
}
void link(int u,int v){
	if(u!=v)set[u].insert(v),set[v].insert(u);
}
void dfs(int x,int type){
	if(vis[x])return;
	vis[x]=type;
	stk[++top]=x;
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i],type);
}
int main(){
	scanf("%d%d%d",&h,&w,&q);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			map[i][j]=get();
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(map[i][j]){
				if(i==1||j==w)merge(hash(i,j),h*w+1);
				if(i==h||j==1)merge(hash(i,j),h*w+2);
				for(int k=-1;k<=1;k++)
					for(int l=-1;l<=1;l++)
						if((k||l)&&map[i+k][j+l])merge(hash(i,j),hash(i+k,j+l));
			}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(!map[i][j]){
				for(int k=-1;k<=1;k++)
					for(int l=-1;l<=1;l++){
						for(int m=-1;m<=1;m++)
							for(int n=-1;n<=1;n++)
								if(map[k+i][l+j]&&map[m+i][n+j])
									link(find(hash(k+i,l+j)),find(hash(m+i,n+j)));
						if(map[k+i][l+j]){
							int u=find(hash(k+i,l+j));
							if(i==1||j==w)link(u,h*w+1);
							if(i==h||j==1)link(u,h*w+2);
						}
					}
			}
//	for(int j=1;j<=h;j++,putchar('\n'))
//		for(int k=1;k<=w;k++)
//			printf("%d\t",find(hash(j,k)));
	for(int i=1,K;i<=q;i++){
		scanf("%d",&K);
		for(int j=1;j<=K;j++)scanf("%d%d",&p[j][0],&p[j][1]),map[p[j][0]][p[j][1]]=1;
//		for(int j=1;j<=h;j++,putchar('\n'))
//			for(int k=1;k<=w;k++)
//				putchar(map[j][k]?'#':'.');
		for(int j=1;j<=K;j++)
			for(int l=-1;l<=1;l++)
				for(int m=-1;m<=1;m++)
					if(map[p[j][0]+l][p[j][1]+m])
						head[find(hash(p[j][0]+l,p[j][1]+m))]=0;
		head[h*w+1]=head[h*w+2]=0;
		k=0;
		for(int j=1;j<=K;j++){
			for(int l=-1;l<=1;l++)
				for(int m=-1;m<=1;m++)
					if(map[p[j][0]+l][p[j][1]+m])
						Link(find(hash(p[j][0]+l,p[j][1]+m)),hash(p[j][0],p[j][1]));
			if(p[j][0]==1||p[j][1]==w)Link(h*w+1,hash(p[j][0],p[j][1]));
			if(p[j][0]==h||p[j][1]==1)Link(h*w+2,hash(p[j][0],p[j][1]));
		}
		top=0;
		dfs(h*w+1,1);
		int cnt=top;
		bool ans=0;
		if(vis[h*w+2])ans=1;
		else{
			dfs(h*w+2,2);
			for(int j=1;j<=K;j++){
				for(int l=-2;l<=2;l++)
					for(int m=-2;m<=2;m++)
						if(p[j][0]+l>=1&&p[j][1]+m>=1&&map[p[j][0]+l][p[j][1]+m]){
							int u=find(hash(p[j][0]+l,p[j][1]+m));
							if((vis[hash(p[j][0],p[j][1])]|vis[u])==3){
								ans=1;
								break;
							}
						}
				if(p[j][0]<=2||p[j][1]>=w-1){
					if((vis[hash(p[j][0],p[j][1])]|vis[h*w+1])==3)
						ans=1;
				}
				if(p[j][0]>=h-1||p[j][1]<=2){
					if((vis[hash(p[j][0],p[j][1])]|vis[h*w+2])==3)
						ans=1;
				}
			}
			for(int i=1;i<=cnt;i++)
				for(int j=cnt+1;j<=top;j++)
					if(set[stk[i]].count(stk[j])){
						ans=1;
						break;
					}
		}
		if(ans)puts("NO");
		else puts("YES");
		for(int j=1;j<=top;j++)vis[stk[j]]=0;
		for(int j=1;j<=K;j++)map[p[j][0]][p[j][1]]=0;
		fflush(stdout);
	} 
}