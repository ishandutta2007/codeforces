#include <cstdio>
#include <vector>

int n,con[1000001][2],bel[1000001],sum,head[1000001],nxt[1000001],b[1000001],k,num[1000001],top;
bool vis[1000001],ans[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	if(vis[x])return;
	vis[x]=1;
	num[++top]=x;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
int main(){
	scanf("%d",&n);
	if(n%2==0){
		puts("First");
		fflush(stdout);
		for(int i=1;i<=n;i++)printf("%d ",i);
		for(int i=1;i<=n;i++)printf("%d ",i);putchar('\n');
		fflush(stdout);
		return 0;
	}
	else{
		puts("Second");
		fflush(stdout);
		for(int i=1;i<=(n<<1);i++)scanf("%d",bel+i);
		for(int i=1;i<=(n<<1);i++)
			if(con[bel[i]][0])con[bel[i]][1]=i;
			else con[bel[i]][0]=i;
		for(int i=1;i<=n;i++){
			if(bel[i]!=bel[i+n])push(bel[i],bel[i+n]),push(bel[i+n],bel[i]);
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				top=0;
				dfs(i,0);
				int last;
				if(top>1&&con[num[1]][0]%n!=con[num[2]][0]%n&&con[num[1]][0]%n!=con[num[2]][1]%n){
						(sum+=con[num[1]][1])%=(n<<1);
						ans[con[num[1]][1]]=1;
						last=con[num[1]][1];
				}
				else{
						(sum+=con[num[1]][0])%=(n<<1);
						ans[con[num[1]][0]]=1;
						last=con[num[1]][0];
				}
				for(int j=2;j<=top;j++){
					if(con[num[j]][0]%n!=last%n){
						(sum+=con[num[j]][0])%=(n<<1);
						ans[con[num[j]][0]]=1;
					last=con[num[j]][0];
					}
					else{
						(sum+=con[num[j]][1])%=(n<<1);
						ans[con[num[j]][1]]=1;
					last=con[num[j]][1];
					}
				}
			}
		if(sum==0){
			for(int i=1;i<=(n<<1);i++)
				if(ans[i])printf("%d ",i);
		}
		else{
			for(int i=1;i<=(n<<1);i++)
				if(!ans[i])printf("%d ",i);
		}
		fflush(stdout);
	}
}