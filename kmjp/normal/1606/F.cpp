#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> vnum,vdel;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;

int N;

int Q,V[202020],K[202020],ret[202020];

const int ME=300001;
vector<int> E[ME];
int L[ME],R[ME],D[ME],P[ME],rev[ME],eid;
int vis[202020];
int top[202020];
set<int> del[202020];
vector<int> query[202020];


void EulerTour(int cur,int pre=0,int d=0) {
	if(pre==-1) ZERO(L),ZERO(R),eid=0;
	rev[eid]=cur;
	P[cur]=pre;
	L[cur]=eid++;
	D[cur]=d;
	FORR(e,E[cur]) if(e!=pre) EulerTour(e,cur,d+1);
	R[cur]=eid;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	E[0].push_back(1);
	E[1].push_back(0);
	N++;
	
	EulerTour(0);
	FOR(i,N) {
		top[i]=L[i];
		vnum.add(L[i],E[i].size()-1);
		if(i) vnum.add(L[P[i]],-((int)E[i].size()-1));
		if(i>1&&E[i].size()>=2) del[E[i].size()-2].insert(-L[i]);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>V[i]>>K[i];
		query[K[i]].push_back(i);
	}
	
	for(k=200000;k>=0;k--) {
		while(del[k].size()) {
			int v=rev[-*del[k].begin()];
			del[k].erase(del[k].begin());
			if(vis[v]) continue;
			vis[v]=1;
			top[uf[v]]=top[uf[P[v]]]=min(top[uf[v]],top[uf[P[v]]]);
			uf(v,P[v]);
			x=vnum(R[v]-1)-vnum(L[v]-1);
			i=vdel(R[v]-1)-vdel(L[v]-1);
			y=rev[top[uf[v]]];
			vnum.add(L[P[v]],x-1);
			vnum.add(L[P[y]],-x+1);
			vdel.add(L[P[v]],i+1);
			vdel.add(L[P[y]],-(i+1));
			if(y>1&&vis[y]==0) {
				x=vnum(R[y]-1)-vnum(L[y]-1);
				i=vdel(R[y]-1)-vdel(L[y]-1);
				x=max(0,min(k,(x+i)/(i+1)-1));
				del[x].insert(-L[y]);
			}
		}
		FORR(q,query[k]) {
			int v=V[q];
			ret[q]=(vnum(R[v]-1)-vnum(L[v]-1))-1LL*k*(vdel(R[v]-1)-vdel(L[v]-1));
			if(N==200000&&q==9&&ret[q]==1) {
				cout<<vnum(R[v]-1)<<" "<<vnum(L[v]-1)<<" "<<k<<" "<<vdel(R[v]-1)<<" "<<vdel(L[v]-1)<<endl;
				return;
			}
		}
	}
	
	
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}