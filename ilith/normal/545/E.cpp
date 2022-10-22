#include<bits/stdc++.h>
#define int long long
const int N=300010;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T& A,Ts&... As){write(A),putchar(' '),write(As...);}
struct node{
	int id,dis;
	bool operator<(node k)const{
		return dis>k.dis;
	}
};
int u,v,w;
struct edge{
	int to,val,id;
};
int res;
edge ans[N];
vector<edge>a[N];
int dis[N],vis[N];
int n,m,s;
priority_queue<node>q;
void dij(int n,int m,int s,vector<edge>a[],int* dis){
	for(int i=1;i<=n;i++)dis[i]=999999999999999ll,vis[i]=0;
	dis[s]=0;
	q.push(node{s,0});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<a[x].size();i++){
			int to=a[x][i].to;
			int val=a[x][i].val;
			if(dis[to]>dis[x]+val){
				dis[to]=dis[x]+val;
				q.push(node{to,dis[to]});
			}
		}
	}
}
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		read(u,v,w);
		a[u].push_back(edge{v,w,i});
		a[v].push_back(edge{u,w,i});
	}
	read(s);
	dij(n,m,s,a,dis);
	for(int i=1;i<=n;i++){
		ans[i].val=99999999999999999ll;
		for(int j=0;j<a[i].size();j++){
			int to=a[i][j].to;
			if(dis[to]+a[i][j].val==dis[i]&&a[i][j].val<ans[i].val)ans[i]=a[i][j];
		}
		if(ans[i].val<9999999999999999ll)res+=ans[i].val;
	}
	write(res),putchar('\n');
	for(int i=1;i<=n;i++){
		if(ans[i].id)write(ans[i].id),putchar(' ');
	}
	return 0;
}