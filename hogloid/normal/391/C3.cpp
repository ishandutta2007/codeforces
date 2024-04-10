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

static const int MAXN=200005;
struct BIT{
	lint val[MAXN*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,lint a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	lint query(int k){	//[0,k)
		lint res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};


int n,k;
pi opp[200005];
vector<pi> cost[200005];
vector<lint> sum[200005];

int cnt_p[200005];
int pos[200005];
const lint INF=1e18;
BIT cnt,eff;
int main(){
	cin>>n>>k;
	REP(i,n){
		int a,b;scanf("%d%d",&a,&b);
		cost[a].pb(mp(b,i));
		if(a>0) cost[a-1].pb(mp(b,i));
		opp[i]=mp(b,i);
		++cnt_p[a];
	}
	sort(opp,opp+n);
	REP(i,n) pos[opp[i].sc]=i;

	REP(i,200005){
		sort(ALL(cost[i]));
		lint ever=0;
		sum[i].pb(0);
		REP(j,cost[i].size()) {
			ever+=cost[i][j].fr;
			sum[i].pb(ever);
		}
	}

	cnt.init(n);
	eff.init(n);

	REP(i,n) cnt.add(i,1);
	REP(i,n) eff.add(i,opp[i].fr);
	
	int got=0;
	lint res=INF;
	if(k==n+1){
		puts("0");
		return 0;
	}
	for(int T=1;T<=n;++T){

		REP(i,cost[T-1].size()){
			int p=pos[cost[T-1][i].sc];
			cnt.add(p,-1);
			eff.add(p,-cost[T-1][i].fr);
		}

		int j=T;
		while(j<n && cnt.query(j)<T) ++j;
		while(j>=0 && cnt.query(j)+cost[T-1].size()>=T){
			int rest=T-cnt.query(j);
			lint cost2=eff.query(j)+sum[T-1][rest];
			
			if(rest+got>=(n+1-k)) chmin(res,cost2);
			--j;
		}
		REP(i,cost[T-1].size()){
			int p=pos[cost[T-1][i].sc];
			cnt.add(p,1);
			eff.add(p,opp[p].fr);
		}
		got+=cnt_p[T-1];
	}
	dump(res);
	if(res==INF) res=-1;

	cout<<res<<endl;


	return 0;
}