#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define DB long double
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const DB eps=1e-6;
const int N=4e5+10;
const int M=230;

int n,Q,dfn;
vector<int> ve[N];
int tp[N],fa[N],siz[N],son[N],DFN[N],dep[N];

void dfs1(int x){
	siz[x]=1;son[x]=0;
	for(int i=0;i<ve[x].size();++i){
		if(ve[x][i]==fa[x]) continue;
		fa[ve[x][i]]=x;
		dep[ve[x][i]]=dep[x]+1;
		dfs1(ve[x][i]);
		siz[x]+=siz[ve[x][i]];
		if(siz[son[x]]<siz[ve[x][i]]) son[x]=ve[x][i];
	}
}

void dfs2(int x,int TP){
	tp[x]=TP;
	DFN[x]=++dfn;
	if(son[x]) dfs2(son[x],TP);
	for(int i=0;i<ve[x].size();++i){
		if(ve[x][i]==son[x]||ve[x][i]==fa[x])  continue;
		dfs2(ve[x][i],ve[x][i]);
	}
}

int tc;
int ccc[N],sta[N];

struct node{
	int l,r,c;
}d[N<<1];

void pushdown(int t){
	if(d[t].l==d[t].r) return;
	if(d[t].c)d[t<<1].c=d[t<<1|1].c=d[t].c;
	d[t].c=0;
}

void build(int l,int r,int t){
	d[t].l=l;d[t].r=r;
	if(l==r){
		d[t].c=ccc[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,t<<1);
	build(mid+1,r,t<<1|1);
}

void update(int l,int r,int t,int c){
	if(d[t].l==l&&d[t].r==r){
		d[t].c=c;
		return;
	}
	pushdown(t);
	if(r<=d[t<<1].r) update(l,r,t<<1,c);
	else if(l>d[t<<1].r) update(l,r,t<<1|1,c);
	else{
		update(l,d[t<<1].r,t<<1,c);
		update(d[t<<1|1].l,r,t<<1|1,c);
	}
}

int get(int l,int t){
	if(d[t].l==d[t].r) return d[t].c;
	pushdown(t);
	if(l<=d[t<<1].r) return get(l,t<<1);
	else return get(l,t<<1|1);
}

struct date{
	int l,r;
};

bool operator < (date A,date B){
	return A.l<B.l||(A.l==B.l&&A.r<B.r);
}

set<date> S;
set<date>::iterator it;

int t[N];
void add(int x,int w){
	while(x<N){
		t[x]+=w;
		x+=x&-x;
	}
}
int cal(int x){
	int re=0;
	while(x){
		re+=t[x];
		x-=x&-x;
	}
	return re;
}

char op[20];

int rk(int x){
	int C=get(DFN[x],1);
	//cout<<"rk "<<x<<" "<<C<<endl;
	int re=cal(C-1);
	int y=sta[C-1];
	if(C<=n) return re+1;
	//cout<<x<<" "<<C<<" "<<re<<endl;
	while(tp[x]!=tp[y]){
		//cout<<x<<" "<<y<<endl;
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		//cout<<DFN[x]<<" "<<DFN[tp[x]]<<" "<<tp[x]<<endl;
		re+=(DFN[x]-DFN[tp[x]]+1);
		x=fa[tp[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	re+=(DFN[x]-DFN[y]+1);
	return re;
}

int du[N],cc[N];
priority_queue<int,vector<int>,greater< int > > q;

int main(){
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){
		S.insert(date{i,i});
		add(i,1);
	}
	S.insert(date{-1,-1});
	int u,v;
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ve[u].push_back(v);
		ve[v].push_back(u);
		++du[u];++du[v];
	}
	for(int i=1;i<=n;++i) if(du[i]==1) q.push(i);
	for(int i=1;i<=n;++i){
		u=q.top();q.pop();
		cc[u]=i;
		for(int j=0;j<ve[u].size();++j){
			--du[ve[u][j]];
			if(du[ve[u][j]]==1)
				q.push(ve[u][j]);
		}
		sta[n]=u;
		//cout<<u<<endl;
	}
	dfs1(1);dfs2(1,1);
	//for(int i=1;i<=n;++i) cout<<cc[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i) ccc[DFN[i]]=cc[i];
	build(1,n,1);
	tc=n;
	date y,re;
	int C;
	while(Q--){
		scanf("%s",op+1);
		if(op[1]=='w'){
			scanf("%d",&u);
			printf("%d\n",rk(u));
		}
		else if(op[1]=='c'){
			scanf("%d%d",&u,&v);
			if(rk(u)<rk(v)) printf("%d\n",u);
			else printf("%d\n",v);
		}
		else{
			scanf("%d",&u);++tc;sta[tc]=u;
			v=sta[tc-1];
			while(tp[u]!=tp[v]){
				
				//cout<<u<<" "<<v<<endl;
				
				if(dep[tp[u]]<dep[tp[v]]) swap(u,v);
				it=S.lower_bound(date{DFN[u],n+10});--it;
				y=(*it);S.erase(it);
				if(y.r>DFN[u]) S.insert(date{DFN[u]+1,y.r});
				y.r=DFN[u];S.insert(y);
				it=S.lower_bound(date{DFN[u],n+10});--it;
				re=date{DFN[u],DFN[u]};
				//cout<<u<<endl;
				while(1){
					y=(*it);--it;
					if(y.l<DFN[tp[u]]) break;
					S.erase(y);
					C=get(y.l,1);
					add(C,-(y.r-y.l+1));
					update(y.l,y.r,1,tc);
					add(tc,(y.r-y.l+1));
					re.l=y.l;
				}
				S.insert(re);
				u=fa[tp[u]];
			}
			if(dep[u]<dep[v]) swap(u,v);
			
			it=S.lower_bound(date{DFN[v],n+10});--it;
			y=(*it);S.erase(it);
			if(y.l<DFN[v]) S.insert(date{y.l,DFN[v]-1});
			y.l=DFN[v];S.insert(y);
			
			it=S.lower_bound(date{DFN[u],n+10});--it;
			y=(*it);S.erase(it);
			if(y.r>DFN[u]) S.insert(date{DFN[u]+1,y.r});
			y.r=DFN[u];S.insert(y);
			
			it=S.lower_bound(date{DFN[u],n+10});--it;
			re=date{DFN[u],DFN[u]};
			while(1){
				y=(*it);--it;
				if(y.l<DFN[v]) break;
				S.erase(y);
				C=get(y.l,1);
				add(C,-(y.r-y.l+1));
				update(y.l,y.r,1,tc);
				add(tc,(y.r-y.l+1));
				re.l=y.l;
			}
			S.insert(re);
		}
	}
	return 0;
}
/*
4 2
1 2
2 3
1 4
up 2
when 2

compare 3 3

*/