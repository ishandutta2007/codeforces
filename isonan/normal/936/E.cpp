#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

int n,x[300001],y[300001],q,head[300001],nxt[600001],b[600001],k,last[300001],L[300001],R[300001];
int pre[300001];
int node[300001],mx[300001],size[300001],full,root;
std::map<std::pair<int,int>,int>map;
std::set<std::pair<int,int> >set;
std::vector<int>rt[300001],dis[300001],pos[300001];
struct point{int x,y;}num[300001];
std::vector<int>c[2][300001];
bool vis[300001];
void push(int s,int t){
//	printf("link %d %d\n",s,t);
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void link(int s,int t){
	if(set.count(std::make_pair(s,t)))return;
	set.insert(std::make_pair(s,t));
	push(s,t);
	push(t,s);
}
void dmin(int &x,int y){if(x>y)x=y;}
void update(std::vector<int>&vec,int ind,int x){
	int u=vec.size();
	for(++ind;ind<=u;ind+=ind&-ind)dmin(vec[ind-1],x);
}
int query(std::vector<int>&vec,int ind){
	int tot=0x7f7f7f7f;
	for(++ind;ind;ind-=ind&-ind)dmin(tot,vec[ind-1]);
	return tot;
}
void getroot(int x,int f){
	size[x]=1;
	mx[x]=0;
//	printf("%d\n",b[head[x]]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
//			printf("*%d %d\n",b[i],x);
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=std::max(mx[x],size[b[i]]);
		}
	mx[x]=std::max(mx[x],full-size[x]);
//	printf("%d %d\n",x,mx[x]);
	if(mx[x]<mx[root])root=x;
}
bool in(int y,int ind){return y>=num[ind].y&&y<num[ind].y+R[ind];}
void getdis(int x,int f){
	for(int i=0;i<R[x];i++){
		::rt[x+i].push_back(root);
		if(in(num[x].y+i,f)){
			int u=f+(num[x].y+i-num[f].y);
			dis[x+i].push_back(dis[u].back()+1);
			pos[x+i].push_back(pos[u].back());
		}
		else if(num[x].y+i<num[f].y){
			dis[x+i].push_back(dis[f].back()+1+(num[f].y-num[x].y-i));
			pos[x+i].push_back(pos[f].back());
		}
		else{
			int u=f+R[f]-1;
			dis[x+i].push_back(dis[u].back()+1+(num[x].y+i-num[u].y));
			pos[x+i].push_back(pos[u].back());
		}
	}
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			getdis(b[i],x),size[x]+=size[b[i]];
}
void solve(int rt){
//	printf("solve %d\n",rt);
	vis[rt]=1;
	for(int i=0;i<R[rt];i++){
		::rt[rt+i].push_back(rt);
		dis[rt+i].push_back(0);
		pos[rt+i].push_back(i);
	}
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]])getdis(b[i],rt);
	for(int i=0;i<2;i++){
		c[i][rt].resize(R[rt]);
		for(int j=0;j<c[i][rt].size();j++)
			c[i][rt][j]=0x7f7f7f7f;
	}
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]]){
			mx[root=0]=full=size[b[i]];
			getroot(b[i],rt);
			solve(root);
		}
}
bool cmp(point a,point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&num[i].x,&num[i].y);
	std::sort(num+1,num+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(num[i-1].x==num[i].x&&num[i-1].y==num[i].y-1)node[i]=node[i-1];
		else L[node[i]=i]=num[i].y,++cnt;
		++R[node[i]];
		if(last[num[i].y]&&num[last[num[i].y]].x==num[i].x-1)link(node[i],node[last[num[i].y]]),pre[i]=last[num[i].y];
		last[num[i].y]=i;
		map[std::make_pair(num[i].x,num[i].y)]=i;
	}
	mx[root=0]=full=cnt;
	getroot(1,0);
	solve(root);
	scanf("%d",&q);
//	for(int i=1;i<=n;i++){
//		printf("%d %d %d %d %d\n",i,num[i].x,num[i].y,node[i],R[node[i]]);
//		for(int j=0;j<rt[i].size();j++)
//			printf("%d %d %d\n",rt[i][j],dis[i][j],pos[i][j]);
//	}
	for(int i=1,t,x,y;i<=q;i++){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			int u=map[std::make_pair(x,y)];
			for(int j=0;j<rt[u].size();j++){
				int nowrt=rt[u][j];
//				printf("%d\n",dis[u][j]-pos[u][j]);
				update(c[0][nowrt],pos[u][j],dis[u][j]-pos[u][j]);
				update(c[1][nowrt],R[nowrt]-1-pos[u][j],dis[u][j]+pos[u][j]);
			}
		}
		else{
			int u=map[std::make_pair(x,y)],tot=0x7f7f7f7f;
			for(int j=0;j<rt[u].size();j++){
				int nowrt=rt[u][j];
//				printf("%d\n",query(c[0][nowrt],pos[u][j])+pos[u][j]);
				dmin(tot,query(c[0][nowrt],pos[u][j])+dis[u][j]+pos[u][j]);
				dmin(tot,query(c[1][nowrt],R[nowrt]-1-pos[u][j])+dis[u][j]-pos[u][j]);
			}
			if(tot>n)puts("-1");
			else printf("%d\n",tot);
		}
	}
}