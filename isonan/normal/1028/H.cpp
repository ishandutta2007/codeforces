#include <cstdio>
#include <vector>
#include <cstring>

const int M=5032107;
int prime[M+1],top,f[M+1],down[M+1],n,q,a[200001],mx[M+1];
int c[200001],ans[2000001];
void update(int ind,int num){
	for(;ind;ind-=ind&-ind)c[ind]=std::min(c[ind],num);
}
int query(int ind){
	int tot=0x7f7f7f7f;
	for(;ind<=n;ind+=ind&-ind)tot=std::min(tot,c[ind]);
	return tot;
}
std::vector<std::pair<int,int> >que[200001];
int head[M+1],nxt[25600001],b[25600001],k,last[200001],now;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int stk[21];
bool pri[M+1];
void add(int d,int i){
	while(head[d]){
		int v=b[head[d]];
		if(last[v]<now)update(v,f[a[v]]+f[a[i]]-(f[d]<<1)),last[v]=now;
		if(f[a[v]]>f[a[i]])head[d]=nxt[head[d]];
		else break;
	}
	push(d,i);
}
void dfs(int x,int i,int prod){
	if(x>top){
		add(prod,i);
		return;
	}
	dfs(x+1,i,prod*stk[x]);
	dfs(x+1,i,prod);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	down[1]=1;
	mx[1]=0;
	for(int i=2;i<=M;i++){
		if(!pri[i])prime[++top]=i,f[i]=1,down[i]=i,mx[i]=i;
		for(int j=1;j<=top&&i*prime[j]<=M;j++){
			pri[i*prime[j]]=1;
			mx[i*prime[j]]=std::max(mx[i],prime[j]);
			if(i%prime[j]==0){
				down[i*prime[j]]=down[i/prime[j]];
				break;
			}
			down[i*prime[j]]=down[i]*prime[j];
			f[i*prime[j]]=f[i]+1;
		}
	}
	memset(c,0x7f7f7f7f,sizeof c);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)a[i]=down[read()];
	for(int i=1,l,r;i<=q;i++)l=read(),r=read(),que[r].push_back(std::make_pair(l,i));
	for(int i=1;i<=n;i++){
		++now;
		top=0;
		for(int tem=a[i];tem>1;tem/=mx[tem]){
			stk[++top]=mx[tem];
		}
		dfs(1,i,1);
		for(int j=0;j<que[i].size();j++)
			ans[que[i][j].second]=query(que[i][j].first);
	}
	for(int i=1;i<=q;i++)write(ans[i]),putchar('\n');
}