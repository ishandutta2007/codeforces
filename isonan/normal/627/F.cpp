#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm> 

int n,A[200001],B[200001],head[200001],nxt[400001],b[400001],k,S,T,pre[200001],next[200001];
int num[200001],top,tem1[200001],tem2[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int dfs(int x,int f,int dis=0){
	if(x==T)return dis;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			int u=dfs(b[i],x,dis+1);
			if(~u)return u;
		}
	return -1;
}
bool getpath(int x,int f,int end){
	num[++top]=x;
	if(x==end)return 1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&getpath(b[i],x,end))return 1;
	--top;
	return 0;
}
bool vis[200001];
int d[200001];
int check(int len){
	int p=-1;
	for(int i=0;i<len;i++)if(tem2[i]==tem1[0])p=i;
	for(int i=0;i<len;i++)
		if(tem2[(i+p)%len]!=tem1[i]){
			puts("-1");
			exit(0);
		}
	return std::min(p,len-p);
}
int getdis(int x,int f,int dis=0){
	if(!vis[x])return dis;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			int u=getdis(b[i],x,dis+1);
			if(~u)return u;
		}
	return -1;
}
void addone(int x,int f){
	if(!vis[x]){
//		printf("%d %d\n",x,d[x]);
		if(d[x]>1){
			puts("-1");
			exit(0);
		}
		vis[f]=0;
		A[f]=B[f]=0;
		return;
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			addone(b[i],x);
		}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",A+i);
	for(int i=1;i<=n;i++)scanf("%d",B+i);
	for(int i=1;i<=n;i++)pre[i]=next[i]=-1;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	bool cando=1;
	for(int i=1;i<=n;i++)
		if(A[i]!=B[i]||!A[i]){
			if(!A[i])S=i;
			if(!B[i])T=i;
			for(int j=head[i];j;j=nxt[j])
				if(A[b[j]]==B[i]&&B[i])pre[i]=b[j],next[b[j]]=i;
			if(!~pre[i]&&i!=T)cando=0;
		}else vis[i]=1;
	int tem=S;
//	for(int i=1;i<=n;i++)printf("%d %d %d\n",i,next[i],pre[i]);
	long long ans=0;
	int pp1,pp2;
//			putchar('*');
	while(~pre[tem]){
		vis[tem]=1;
		++ans;
		tem=pre[tem];
	}
	pp1=tem;
	A[tem]=0;
	tem=T;
	while(~next[tem]){
		vis[tem]=1;
		++ans;
		tem=next[tem];
	}
	B[tem]=0;
	pp2=tem;
	if(pp1!=pp2&&!vis[pp1]&&!vis[pp2]){
		int cnt=0;
		for(int i=1;i<=n;i++)if(!vis[i])++cnt;
		if(cnt==2){
			if(pp1>pp2)std::swap(pp1,pp2);
			printf("%d %d %d\n",pp1,pp2,ans+1);
			return 0;
		}
	}
	bool bb=0;
//	printf("%d %d %d\n",S,T,tem);
	if((tem==S&&vis[S])||(S==T)){
		vis[S]=1;
		bool over=1;
		for(int i=1;i<=n;i++)if(!vis[i])over=0;//,printf("%d\n",i);
		if(over){
			printf("0 %d\n",dfs(S,0));
			return 0;
		}
		else{
			bb=1;
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(!vis[i])
					for(int j=head[i];j;j=nxt[j])
						if(!vis[b[j]])++d[b[j]];
			for(int i=1;i<=n;i++)
				if(!vis[i]){
					if(d[i]>2){
						puts("-1");
						return 0;
					}
					if(d[i]==1)++cnt;
				}
			if(cnt>4){
				puts("-1");
				return 0;
			}
			if(cnt==4){
				int node=-1;
				for(int i=1;i<=n;i++)
					if(vis[i]){
						int cnt=0;
						for(int j=head[i];j;j=nxt[j])
							if(d[b[j]]==1)++cnt;
						if(cnt==2)node=i;
					}
				if(!~node){
					puts("-1");
					return 0;
				}
				vis[node]=0;
				A[node]=B[node]=0;
			}
			else
				addone(S,0);
			ans=getdis(S,0)+getdis(T,0);
			memset(d,0,sizeof d);
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			for(int j=head[i];j;j=nxt[j])
				if(!vis[b[j]])++d[b[j]];
	int p1=-1,p2=-1;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
//			printf("%d %d\n",i,d[i]);
			if(d[i]>2||!d[i]){
				puts("-1");
				return 0;
			}
			if(d[i]==1){
				if(!~p1)p1=i;
				else if(!~p2)p2=i;
				else{
					puts("-1");
					return 0;
				}
			}
		}
	if(!~p2){
		puts("-1");
		return 0;
	}
	getpath(p1,0,p2);
	int added=1;
	int pos1=-1,pos2=-1;
	for(int i=1;i<=top;i++)
		if(A[num[i]])tem1[i-added]=A[num[i]];
		else added++,pos1=i-1;
	added=1;
	for(int i=1;i<=top;i++)
		if(B[num[i]])tem2[i-added]=B[num[i]];
		else added++,pos2=i-1;
	long long fin=1e18;
//	printf("%d %d\n",pos1,pos2);
	fin=std::min(fin,1ll*top*check(top-1)+abs(pos2-pos1));
//	for(int i=0;i<top-1;i++)printf("%d ",tem1[i]);putchar('\n');
//	for(int i=0;i<top-1;i++)printf("%d ",tem2[i]);putchar('\n');
	if(pos1<pos2){
		int orig=tem1[top-2];
		for(int i=top-2;i;i--)tem1[i]=tem1[i-1];
		tem1[0]=orig;
	}
	else if(pos1>pos2){
		int orig=tem1[0];
		for(int i=0;i<top-2;i++)tem1[i]=tem1[i+1];
		tem1[top-2]=orig;
	}
	fin=std::min(fin,1ll*top*check(top-1)+top-abs(pos2-pos1));
//			putchar('*');
	printf("%d %d %d\n",p1,p2,ans+fin);
}