#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

const int INF=5e8;

int n;
vector<pi> g[100005];


int mark[100005];
int size[100005],par[100005];
int prep(int v,int p){
	size[v]=1;
	par[v]=p;
	int mxsize=-1;
	for(auto e:g[v]){
		if(e.fr==p) continue;
		size[v]+=prep(e.fr,v);
		chmax(mxsize,size[e.fr]);
	}
	chmax(mxsize,n-size[v]);
	
	if(mxsize*2<n) mark[v]=2;
	else if(mxsize*2<=n) mark[v]=1;
	return size[v];
}

vector<int> group[100005];
int belong[100005];
lint dfs(int v,int p,lint d,int p2){
	if(p2!=-1){
		belong[v]=p2;
		group[p2].pb(v);
	}else{
		belong[v]=v;
		group[v].pb(v);
	}

	lint res=d;
	for(auto e:g[v]){
		if(e.fr==p) continue;
		res+=dfs(e.fr,v,d+e.sc,(p2==-1?e.fr:p2));
	}
	return res;
}

vector<int> ans;

struct segtree{
	static const int MAX_N=400005;
	pi val[MAX_N];
	int n;
	int all;
	void init(int n_){
		n=1;
		all=0;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i].fr=INF;
		REP(i,n_) val[i+n-1]=mp(INF,i);
		for(int i=n-2;i>=0;--i) val[i]=min(val[i*2+1],val[i*2+2]);
	}
	void fix(int k){
		while(k>0){
			k=(k-1)/2;
			val[k]=min(val[k*2+1],val[k*2+2]);
		}
	}
	void set(int k,int a){
		k+=n-1;
		val[k].fr=a;
		fix(k);
	}
	void add(int k){
		k+=n-1;
		++val[k].fr;
		fix(k);
	}
	void decr(){
		++all;
	}
	pi query(){
		return mp(val[0].fr-all,val[0].sc);
	}
};
bool used[100005];
segtree seg;

void fix(int& a,int &b){
	while(used[a]) ++a;

	chmax(b,a+1);
	while(b<n && (belong[a]==belong[b] || used[b])) ++b;
}

lint solve(int r,bool flag){//flag=0: r->!r flag=1: r->r
	seg.init(n);
	REP(i,n) group[i].clear();

	CLR(used);
	
	ans.resize(n);


	if(flag){
		used[r]=1;
		ans[r]=r;
	}


	lint res=dfs(r,-1,0,-1)*2;
	int whole=n;
	if(flag) whole=n-1;

	REP(i,n) if(group[i].size()>0){
		if(flag && i==r) continue;
		seg.set(i,whole-group[i].size()*2);
	}

	REP(i,n) sort(ALL(group[i]),greater<int>());

	
	int p1=0,p2=0;
	fix(p1,p2);
	debug(belong,belong+n);
	dump(p1);dump(p2);
	REP(i,n){
		if(flag && i==r) continue;

		int g=belong[i];

		pi mini=seg.query();
		dump(mini);
		if(mini.fr==0 && mini.sc!=g){
			int g2=mini.sc,val=group[g2].back();
			ans[i]=val;
			group[g2].pop_back();
			
			used[val]=1;
			seg.add(g);seg.add(g2);
			seg.decr();
		}else{
			int val;
			if(belong[p1]==g) val=p2;
			else val=p1;

			dump(val);

			ans[i]=val;
			group[belong[val]].pop_back();

			used[val]=1;
			seg.add(g);seg.add(belong[val]);
			seg.decr();
		}
		fix(p1,p2);
	}
	debug(ALL(ans));
	return res;
}




int main(){
	cin>>n;
	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	

	prep(0,-1);
	
	vector<int> ans2;
	lint res=0;

	prl;
	REP(i,n) if(mark[i]){
		chmax(res,solve(i,0));
		if(ans2.empty() || ans2>ans) ans2=ans;
		if(mark[i]==2) chmax(res,solve(i,1));
		if(ans2.empty() || ans2>ans) ans2=ans;
	}
	cout<<res<<endl;
	REP(i,n) printf("%d%c",ans2[i]+1,i==n-1?'\n':' ');
	return 0;
}