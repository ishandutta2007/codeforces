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
const int M=26;

int n,Q;
char s[N];
int tot;
int root;
struct node{
	int l,fa;
	int ch[M];
}sa[N];
int ver[N];

void buildsa(){
	int x;
	root=++tot;
	int las=root;
	int p,np,q,nq;
	for(int i=n;i>=1;--i){
		p=las;
		x=s[i]-'a';
		np=las=++tot;
		sa[np].l=sa[p].l+1;
		ver[i]=np;
		for(;p&&!sa[p].ch[x];p=sa[p].fa) sa[p].ch[x]=np;
		if(!p) sa[np].fa=root;
	    else{
	        q=sa[p].ch[x];
	        if (sa[p].l+1==sa[q].l) sa[np].fa=q;
	        else {
	        	nq=++tot;sa[nq].l=sa[p].l+1;
	            memcpy(sa[nq].ch,sa[q].ch,sizeof(sa[nq].ch));
	            sa[nq].fa=sa[q].fa;
	            sa[q].fa=sa[np].fa=nq;
	            for (;sa[p].ch[x]==q;p=sa[p].fa) sa[p].ch[x]=nq;
	        }
	    }
	}
}

int fa[N],dis[N],siz[N],son[N],tp[N];
vector<int> v[N];

void dfs1(int x){
	siz[x]=1;
	for(int i=0;i<v[x].size();++i){
		dfs1(v[x][i]);
		siz[x]+=siz[v[x][i]];
		if(siz[v[x][i]]>siz[son[x]]) son[x]=v[x][i];
	}
}

void dfs2(int x,int TP){
	tp[x]=TP;
	if(son[x]) dfs2(son[x],TP);
	for(int i=0;i<v[x].size();++i)
		if(v[x][i]!=son[x]) dfs2(v[x][i],v[x][i]);
}

void buildtree(){
	for(int i=1;i<=tot;++i){
		fa[i]=sa[i].fa;
		dis[i]=sa[i].l;
		if(fa[i]) v[fa[i]].push_back(i);
	}
	dfs1(1);dfs2(1,1);
}

struct P{
	int num,len,pos;
};

vector<P> p[N];

void buildver(int z){
	int x=ver[z];
	while(x>1){
		int y=tp[x];
		p[y].push_back(P{z,dis[x]-dis[fa[y]],z+dis[fa[y]]+1});
		x=fa[y];
	}
}

struct query{
	int id,len,r;
};
bool operator < (query A,query B){return A.r<B.r;}
vector<query> q1[N],q2[N];

void buildq(int l,int len,int id){
	int x=ver[l];
	while(x>1){
		int y=tp[x];
		if(dis[fa[y]]<len){
			q1[y].push_back(query{id,min(dis[x],len)-dis[fa[y]],l-1});
			q2[y].push_back(query{id,min(dis[x],len)-dis[fa[y]],l+len});
		}
		x=fa[y];
	}
}

int nu[N+50];
LL su[N+50];

void update(int p){
	//cout<<"u "<<p<<endl;
	for(int x=p;x<N;x+=x&-x){++nu[x];su[x]+=p;}
}

void cl(int p){
	//cout<<"cl "<<p<<endl;
	for(;p<N;p+=p&-p) su[p]=nu[p]=0;
}

int getnu(int p){
	int re=0;
	for(;p;p-=p&-p)re+=nu[p];
	return re;
}

LL getsu(int p){
	LL re=0;
	for(;p;p-=p&-p)re+=su[p];
	return re;
}

LL ans[N];

bool cmpn(P A,P B){return A.num<B.num;}
bool cmpp(P A,P B){return A.len+A.pos<B.len+B.pos;}

void sol(vector<P> &pp,vector<query> &Q1,vector<query> &Q2){
	if(pp.empty()) return;
	if(!Q1.empty()){
		sort(pp.begin(),pp.end(),cmpn);
		sort(Q1.begin(),Q1.end());
		int j=0,re=0;
		for(int i=0;i<Q1.size();++i){
			for(;j<pp.size()&&pp[j].num<=Q1[i].r;++j){
				++re;update(pp[j].len);
			}
			int s=getnu(Q1[i].len);
			LL t=getsu(Q1[i].len);
			ans[Q1[i].id]-=(LL)Q1[i].len*(re-s)+t;
		}
		for(j=0;j<pp.size();++j) cl(pp[j].len);
	}
	if(!Q2.empty()){
		sort(pp.begin(),pp.end(),cmpp);
		sort(Q2.begin(),Q2.end());
		int j=0,re=0;
		for(int i=0;i<Q2.size();++i){
			for(;j<pp.size()&&pp[j].pos+pp[j].len<=Q2[i].r+1;++j){
				++re;update(pp[j].len);
			}
			int s=getnu(Q2[i].len);
			LL t=getsu(Q2[i].len);
			ans[Q2[i].id]+=(LL)Q2[i].len*(re-s)+t;
		}
		for(j=0;j<pp.size();++j) cl(pp[j].len);
		
		reverse(pp.begin(),pp.end());
		reverse(Q2.begin(),Q2.end());
		j=0;
		for(int i=0;i<Q2.size();++i){
			for(;j<pp.size()&&pp[j].pos+pp[j].len>Q2[i].r+1;++j) update(pp[j].pos);
			int s=getnu(Q2[i].r);
			LL t=getsu(Q2[i].r);
			if(Q2[i].r-Q2[i].len+1<=0) ans[Q2[i].id]+=(LL)(Q2[i].r+1)*s-t;
			else{
				int s1=getnu(Q2[i].r-Q2[i].len+1);
				LL t1=getsu(Q2[i].r-Q2[i].len+1);
				ans[Q2[i].id]+=(LL)Q2[i].len*s1+(LL)(Q2[i].r+1)*(s-s1)-(t-t1);
			}
		}
		for(j=0;j<pp.size();++j) cl(pp[j].pos);
	}
}

void solve(){
	for(int i=1;i<=tot;++i) sol(p[i],q1[i],q2[i]);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	buildsa();
	//cout<<tot<<endl;
	buildtree();
	//for(int i=1;i<=n;++i) cout<<ver[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i) buildver(i);
	scanf("%d",&Q);
	int u,v,w;
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&u,&v);w=v-u+1;
		buildq(u,w,i);
	}
	solve();
	for(int i=1;i<=Q;++i) printf("%I64d\n",ans[i]);
	return 0;
}
/*

*/