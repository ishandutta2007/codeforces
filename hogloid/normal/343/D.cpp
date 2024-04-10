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

//const int INF=5e8;

struct segtree{
	int maxi[2000000],lazy[2000000];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		memset(maxi,-1,sizeof(maxi));
		memset(lazy,-1,sizeof(lazy));
	}
	void push(int i){
		if(lazy[i]!=-1){
			chmax(lazy[i*2+1],lazy[i]);
			chmax(lazy[i*2+2],lazy[i]);
			chmax(maxi[i*2+1],lazy[i]);
			chmax(maxi[i*2+2],lazy[i]);

			lazy[i]=-1;
		}
	}

	void renew(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			chmax(maxi[i],v);
			chmax(lazy[i],v);
			return;
		}
		if(b<=l || r<=a) return ;
		int md=(l+r)>>1;

		push(i);

		renew(a,b,i*2+1,l,md,v);
		renew(a,b,i*2+2,md,r,v);
		maxi[i]=max(maxi[i*2+1],maxi[i*2+2]);
	}

	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return maxi[i];
		if(b<=l || r<=a) return -1;
		push(i);
		int md=(l+r)>>1;
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree fil,emp;

int n;
int st[500005],fin[500005],cnt;
vector<int> g[500005];
void dfs(int v,int p){
	st[v]=cnt;
	++cnt;
	for(auto to:g[v]){
		if(to==p) continue;
		dfs(to,v);
	}
	fin[v]=cnt;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0,-1);
	fil.init(n);
	emp.init(n);

	int q;cin>>q;
	REP(i,q){
		int c,v;
		scanf("%d%d",&c,&v);--v;
		if(c==1){
			fil.renew(st[v],fin[v],0,0,fil.n,i);
		}else if(c==2){
			emp.renew(st[v],st[v]+1,0,0,emp.n,i);
		}else{
			int lastF=fil.query(st[v],st[v]+1,0,0,fil.n),
					lastE=emp.query(st[v],fin[v],0,0,emp.n);
			int res;
			if(lastF>lastE) res=1;
			else res=0;
			printf("%d\n",res);
		}
	}
	return 0;
}