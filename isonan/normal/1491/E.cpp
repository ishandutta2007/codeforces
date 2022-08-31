#include <cstdio>
#include <vector>

int n;
int head[200001],nxt[400001],b[400001],k,col[200001],now,fa[200001],size[200001];
bool vis[200001];
int f[31];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::vector<int>vec;
void dfs(int x,int f,int n,int &p0,int &p1,int &fap){
	size[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&col[x]==col[b[i]]){
			dfs(b[i],x,n,p0,p1,fap);
			size[x]+=size[b[i]];
		}
	if(size[x]==::f[n]||size[x]==::f[n+1]){
		if(p0)fap=fa[x];
		(p0?p1:p0)=x;
	}
}
void recol(int x,int f,int c){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&col[x]==col[b[i]]){
			recol(b[i],x,c);
		}
	col[x]=c;
}
bool check(int x,int n){
	if(n<=3)return 1;
	int p0=0,p1=0,fap=0;
	bool t1=0,t2=0;
	dfs(x,0,n-2,p0,p1,fap);
	if(!p0)return 0;
	t1=(size[p0]==f[n-2]);
	t2=(size[p1]==f[n-2]);
	if(t1){
		recol(p0,fa[p0],++now);
		bool ans=check(x,n-1)&&check(p0,n-2);
		recol(p0,0,col[x]);
		return ans;
	}
	else if(t2){
		recol(p1,fa[p1],++now);
		bool ans=check(x,n-1)&&check(p1,n-2);
		recol(p1,0,col[x]);
		return ans;
	}
	else if(p0){
		recol(p0,fa[p0],++now);
		bool ans=check(x,n-2)&&check(p0,n-1);
		recol(p0,0,col[x]);
		return ans;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		push(u,v),push(v,u);
	}
	f[0]=f[1]=1;
	for(int i=2;i<=30;i++)f[i]=f[i-1]+f[i-2];
	int k=1;
	while(f[k]<n)++k;
	if(f[k]>n){
		puts("NO");
		return 0;
	}
	if(check(1,k))puts("YES");
	else puts("NO");
}