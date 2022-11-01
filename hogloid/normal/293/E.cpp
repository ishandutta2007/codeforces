#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,l,w;

lint ans;

static const int MAX_N=100005;
vector<pair<int,int> > g[MAX_N];
int cut[MAX_N],size[MAX_N],whole;
int root,rcost;
int getsize(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(to!=p && cut[to]==0) size[v]+=getsize(to,v);
	}
	return size[v];
}
void getbestroot(int v,int p){
	int maxi=0;
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(to!=p && cut[to]==0){
			getbestroot(to,v);
			maxi=max(maxi,size[to]);
		}
	}
	int rest=whole-size[v];
	maxi=max(maxi,rest);
	if(maxi<rcost){
		rcost=maxi;
		root=v;
	}
}

pi prop[100005];
int cnt;
void find(int v,int p,int len,int wei){
	prop[cnt++]=mp(len,wei);
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(e.fr==p || cut[e.fr]) continue;
		find(e.fr,v,len+1,wei+e.sc);
	}
}

struct BIT{
	int val[200005];
	int n;
	void init(int n_){
		n=n_;
		REP(i,n+1) val[i]=0;
	}
	int query(int k){
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
};
BIT bit;
int zip[100005],zn;
void part(int v,int p,int add,int l,int w){
	cnt=0;
	find(v,p,0,0);
	
	sort(prop,prop+cnt);

	REP(i,cnt){
	}
	REP(i,cnt) zip[i]=prop[i].sc;
	sort(zip,zip+cnt);
	zn=unique(zip,zip+cnt)-zip;
	bit.init(zn);

	REP(i,cnt) prop[i].sc=lower_bound(zip,zip+zn,prop[i].sc)-zip;

	REP(i,cnt) bit.add(prop[i].sc,1);
	lint tmp=0;
	int j=cnt;//...j)
	REP(i,cnt){
		while(j>0 && prop[j-1].fr+prop[i].fr>l){
			--j;
			bit.add(prop[j].sc,-1);
		}
		int p=upper_bound(zip,zip+zn,w-zip[prop[i].sc])-zip;
		tmp+=bit.query(p);
	}
	REP(i,cnt) if(prop[i].fr*2<=l && zip[prop[i].sc]*2<=w) --tmp;
	tmp/=2;


	tmp*=add;

	ans+=tmp;
}



void dfs(int v){
	getsize(v,-1);
	if(size[v]==1) return;
	whole=size[v];
	rcost=INF;
	getbestroot(v,-1);
	v=root;
	cut[v]=1;
	
	part(v,-1,1,l,w);
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr]) continue;
		part(e.fr,-1,-1,l-2,w-e.sc*2);
	}

	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr]) continue;
		dfs(e.fr);
	}
}



int main(){
	cin>>n>>l>>w;
	REP(i,n-1){
		int p,len;scanf("%d%d",&p,&len);
		--p;
		g[p].pb(mp(i+1,len));
		g[i+1].pb(mp(p,len));
	}

	dfs(0);

	cout<<ans<<endl;

	return 0;
}