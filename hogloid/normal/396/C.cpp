#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).beginn(),(t).fin()
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
//const int INF=5e8;
const int mod=1000000007;


struct Int {
	unsigned x;
	int mpow(Int a,int k){
		Int res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	int inverse(Int a){
		return mpow(a,mod-2);
	}
	Int(): x(0) { }
	Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
	int get() const { return (int)x; }
	
	Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int &operator=(Int that) { x=that.x; return *this;}
	Int &operator/=(Int that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	Int &operator- () { x=mod-x; if(x==mod) x=0; return *this;}
	bool operator==(Int that){ return x==that.x; }
	bool operator!=(Int that){ return x!=that.x; }


	Int operator+(Int that) const { return Int(*this) += that; }
	Int operator-(Int that) const { return Int(*this) -= that; }
	Int operator*(Int that) const { return Int(*this) *= that; }
	Int operator/(Int that) const { return Int(*this) /= that; }
};



namespace std{
	ostream &operator <<(ostream& out,const Int& a){
		out<<a.get();
		return out;
	}
	istream &operator >>(istream& in,Int& a){
		in>>a.x;
		return in;
	}
};
static const int MAXN=300005;
struct BIT{
	Int val[MAXN*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,Int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	Int query(int k){	//[0,k)
		Int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};


int n;
vector<int> g[300005];

int beginn[300005],fin[300005];
int cnt;
int dep[300005];
void dfs(int v,int d=0){
	dump(v);
	beginn[v]=cnt;
	++cnt;
	dep[v]=d;
	for(auto to:g[v]){
		dfs(to,d+1);
	}
	fin[v]=cnt;
}

BIT cons,coef;
int main(){
	cin>>n;
	REP(i,n-1){
		int p;scanf("%d",&p);--p;
		g[p].pb(i+1);
	}
	cons.init(n);
	coef.init(n);

	dfs(0);

	int q;cin>>q;

	REP(hoge,q){
		int t,v;scanf("%d%d",&t,&v);--v;
		if(t==1){
			int x,k;scanf("%d%d",&x,&k);

			Int add=x+dep[v]*(lint)k;
			
			cons.add(beginn[v],add);
			cons.add(fin[v],-add);
			coef.add(beginn[v],k);
			coef.add(fin[v],-k);
		}else{
			Int res=cons.query(beginn[v]+1)-coef.query(beginn[v]+1)*dep[v];

			printf("%d\n",res.get());
		}
	}



	return 0;
}