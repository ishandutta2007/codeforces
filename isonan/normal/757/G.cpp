#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define int long long

int n,x,head[300001],nxt[600001],b[600001],v[600001],k;
int root,full,size[300001],mx[300001],top,key[20000001];
long long cnt[10000001],sum[10000001];
std::vector<int>rt[300001],dis[300001],point[300001];
std::vector<int>vec[300001];
bool vis[300001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=std::max(mx[x],size[b[i]]);
		}
	mx[x]=std::max(mx[x],full-size[x]);
	if(mx[x]<mx[root])root=x;
}
void getdis(int x,int f,int orig,long long dis){
	rt[x].push_back(orig);
	::dis[x].push_back(dis);
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			getdis(b[i],x,orig,dis+v[i]);
			size[x]+=size[b[i]];
		}
}
void solve(int rt){
	vis[rt]=1;
	getdis(rt,0,rt,0);
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]]){
			mx[root=0]=full=size[b[i]];
			getroot(b[i],0);
			solve(root);
		}
}
int find(int x,int p){
	int l=0,r=vec[x].size()-1,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(key[vec[x][mid]]<=p)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
long long que(int x,int L,int R){
	long long ans=0;
	for(int i=0;i<rt[x].size();i++){
		int nowrt=rt[x][i];
//		for(int j=0;j<vec[nowrt].size();j++)printf("%d ",key[vec[nowrt][j]]);putchar('\n');
		int r=find(nowrt,R),l=find(nowrt,L-1);
//		printf("%d %d %d\n",l,r,((~r)?sum[vec[nowrt][r]]:0)-((~l)?sum[vec[nowrt][l]]:0));
//		printf("%d %d\n",dis[x][i],(i?dis[x][i-1]:0));
		ans+=((~r)?sum[vec[nowrt][r]]:0)-((~l)?sum[vec[nowrt][l]]:0)+1ll*(r-l)*(dis[x][i]-(i?dis[x][i-1]:0));
//		printf("%lld\n",ans);
	}
	return ans; 
}
int q,a[200001];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v,val;i<n;i++){
		u=read(),v=read(),val=read();
		push(u,v,val),push(v,u,val);
	}
	mx[root=0]=full=n;
	getroot(1,0);
	solve(root);
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<rt[a[i]].size();j++){
			point[a[i]].push_back(++top);
			key[top]=i;
			cnt[top]=dis[a[i]][j]-(j?dis[a[i]][j-1]:0);
			if(!vec[rt[a[i]][j]].empty())sum[top]=cnt[top]+sum[vec[rt[a[i]][j]].back()];
			else sum[top]=cnt[top];
			vec[rt[a[i]][j]].push_back(top);
		}
//	fprintf(stderr,"%d\n",top);
	for(int i=1;i<=q;i++){
//		if(i%1000==0)fprintf(stderr,"%d\n",i);
		int t,l,r,v;
		t=read();
		if(t==1){
			l=read(),r=read(),v=read();
			l^=ans,r^=ans,v^=ans;
			write(ans=que(v,l,r));
			putchar('\n');
			ans%=(1<<30);
		}
		else{
			v=read();
			v^=ans;
			int i=0;
			while(i<rt[a[v]].size()&&i<rt[a[v+1]].size()&&rt[a[v]][i]==rt[a[v+1]][i])++i;
			for(int j=0;j<i;j++){
//				printf("%d %d %d %d\n",cnt[point[a[v]][j]],cnt[point[a[v+1]][j]],sum[point[a[v]][j]],sum[point[a[v+1]][j]]);
				std::swap(point[a[v]][j],point[a[v+1]][j]);
				key[point[a[v]][j]]=v+1;
				key[point[a[v+1]][j]]=v;
				sum[point[a[v+1]][j]]+=cnt[point[a[v]][j]]-cnt[point[a[v+1]][j]];
				std::swap(cnt[point[a[v]][j]],cnt[point[a[v+1]][j]]);
//				std::swap(sum[point[a[v]][j]],sum[point[a[v+1]][j]]);
//				printf("%d %d %d %d\n",cnt[point[a[v+1]][j]],cnt[point[a[v]][j]],sum[point[a[v+1]][j]],sum[point[a[v]][j]]);
			}
			for(int j=i;j<rt[a[v]].size();j++)++key[point[a[v]][j]];
			for(int j=i;j<rt[a[v+1]].size();j++)--key[point[a[v+1]][j]];
			std::swap(a[v],a[v+1]);
		}
	}
}