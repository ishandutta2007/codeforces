#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
//#define double long double

int n,m;
int head[100001],nxt[200001],b[200001],k;
int size[100001],son[100001],dep[100001],top[100001],fa[100001],Top;
struct point{
	int l,r,t,ord;
	double app;
}num[200010];
std::vector<point>vec[100001];
double ans=1e18;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	size[x]=1;
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[b[i]]>size[son[x]])son[x]=b[i];
		}
}
void dfs2(int x,int t){
	top[x]=t;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]&&b[i]!=son[x])dfs2(b[i],b[i]);
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])std::swap(x,y);
		y=fa[top[y]];
	}
	return dep[x]>dep[y]?y:x;
}
bool cmp(point a,point b){return a.app<b.app||(a.app==b.app&&a.r>b.r);}
int root,ch[100001][2],pri[100001],t_size[100001];
void pushup(int x){
	t_size[x]=t_size[ch[x][0]]+t_size[ch[x][1]]+1;
}
bool comp(int X,int o1,int o2,double t){
	if(o1==o2)return 0;
	else{
		double n1=(double)dep[vec[X][o1].l]+(double)vec[X][o1].t*(t-vec[X][o1].app);
		double n2=(double)dep[vec[X][o2].l]+(double)vec[X][o2].t*(t-vec[X][o2].app);
//		printf("%lf %lf %lf %lf %lf %d %d\n",(double)vec[X][o1].t,(double)vec[X][o2].t,n1,n2,t,o1,o2);
		return n1<=n2;
	}
}
void split(int now,int &x,int &y,int X,int Ord,double time){
	if(!now)x=y=0;
	else{
		if(comp(X,Ord,now,time))x=now,split(ch[now][1],ch[now][1],y,X,Ord,time);
		else y=now,split(ch[now][0],x,ch[now][0],X,Ord,time);
		pushup(now);
	}
}
void splits(int now,int &x,int &y,int s){
	if(!now)x=y=0;
	else{
		if(t_size[ch[now][0]]+1<=s)x=now,splits(ch[now][1],ch[now][1],y,s-t_size[ch[now][0]]-1);
		else y=now,splits(ch[now][0],x,ch[now][0],s);
		pushup(now);
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(pri[x]<pri[y]){
		ch[x][1]=merge(ch[x][1],y);
		pushup(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]);
		pushup(y);
		return y;
	}
}
int left(int x){while(ch[x][0])x=ch[x][0];return x;}
int rght(int x){while(ch[x][1])x=ch[x][1];return x;}
bool in(double a,double b,double c){return (a<=c&&c<=b)||(b<=c&&c<=a);}
void chk(point a,point b){
	double b1=(double)dep[a.l]-(double)(1ll*a.t*a.app);
	double b2=(double)dep[b.l]-(double)(1ll*b.t*b.app);
	if(a.t==b.t){
		if(b1==b2){
			long long x1=dep[a.l],y1=dep[a.r],x2=dep[b.l],y2=dep[b.r];
			if(x1>y1)std::swap(x1,y1);
			if(x2>y2)std::swap(x2,y2);
			if(std::max(x1,x2)<=std::min(y1,y2))ans=std::min(ans,std::max(a.app,b.app));
		}
	}
	else{
		double X=(b2-b1)/(double)(a.t-b.t);
		double pos=a.t*X+b1;
//		printf("%lf %lf %lf %lf %d %d %d %d\n",a.app,b.app,X,pos,dep[a.l],dep[a.r],dep[b.l],dep[b.r]);
		if(in((double)dep[a.l],(double)dep[a.r],pos)&&in((double)dep[b.l],(double)dep[b.r],pos))
			ans=std::min(ans,X);
	}
}
void debug(int x){
	if(!x)return;
	debug(ch[x][0]);
	printf("%d\n",x);
	debug(ch[x][1]);
}
void solve(int x){
//	printf("solve %d\n",x);
	Top=0;
	for(int i=1;i<vec[x].size();i++){
		num[++Top]=(point){vec[x][i].app,1,vec[x][i].t,i,vec[x][i].app};
		double r=(double)abs(dep[vec[x][i].l]-dep[vec[x][i].r])/(double)vec[x][i].t;
		if(dep[vec[x][i].l]>dep[vec[x][i].r])vec[x][i].t=-vec[x][i].t;
//		printf("%d %d %d %lf %lf\n",vec[x][i].l,vec[x][i].r,vec[x][i].t,vec[x][i].app,vec[x][i].app+r);
		num[++Top]=(point){vec[x][i].app,-1,vec[x][i].t,i,vec[x][i].app+r};
	}
	std::sort(num+1,num+Top+1,cmp);
	root=0;
	for(int i=1;i<=Top;i++){
		if(num[i].app>=ans-1e-7)break;
		if(num[i].r==1){
			int t1,t2;
//			printf("add %d\n",num[i].ord);
			split(root,t1,t2,x,num[i].ord,num[i].app);
			if(t1)chk(vec[x][rght(t1)],vec[x][num[i].ord]);
			if(t2)chk(vec[x][left(t2)],vec[x][num[i].ord]);
			ch[num[i].ord][0]=ch[num[i].ord][1]=0;
			t_size[num[i].ord]=1;
			root=merge(t1,merge(num[i].ord,t2));
		}
		else{
			int t1,t2,t3;
//			printf("del %d\n",num[i].ord);
			split(root,t1,t2,x,num[i].ord,num[i].app);
//			printf("%d %d\n",t1,t2);
			splits(t2,t2,t3,1);
			if(t1&&t3)chk(vec[x][rght(t1)],vec[x][left(t3)]);
			root=merge(t1,t3);
		}
//		debug(root);putchar('\n');
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	for(int i=1;i<=100000;i++)pri[i]=(1ll*rand()*rand())%1000000;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,val;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)vec[i].push_back((point){0,0,0,0,0});
	for(int i=1,u,v,t,c;i<=m;i++){
		scanf("%d%d%d%d",&t,&c,&u,&v);
		double start=(double)t,end=(double)t+(double)(dep[u]+dep[v]-(dep[LCA(u,v)]<<1ll))/(double)c;
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]]){
				vec[top[u]].push_back((point){u,fa[top[u]],c,i,start});
//				printf("%d %d %d\n",u,fa[top[u]],dep[u]-dep[fa[top[u]]]);
				start+=(double)(dep[u]-dep[fa[top[u]]])/(double)c;
				u=fa[top[u]];
			}
			else{
				end-=(double)(dep[v]-dep[fa[top[v]]])/(double)c;
				vec[top[v]].push_back((point){fa[top[v]],v,c,i,end});
				v=fa[top[v]];
			}
//			printf("%d %d %lf %lf\n",u,v,start,end);
		}
		vec[top[u]].push_back((point){u,v,c,i,start});
	}
	for(int i=1;i<=n;i++)if(top[i]==i)solve(i);
	if(ans>1e12)puts("-1");
	else std::cout<<std::fixed<<std::setprecision(6)<<ans;
}