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
typedef pair<lint,lint> pi;

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

static const int MAXN=300005;
struct BIT{
	int val[MAXN*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){	//[0,k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};

BIT bit;
int n,m;
const lint INF=1e18;
int cnt;
pi house[100005];
pi pts[100005];
int main(){
	int tmp__,tmp___;
	cin>>tmp__>>tmp___;

	cin>>n;
	REP(i,n){
		int x,y;scanf("%d%d",&x,&y);

		int X=x+y,Y=-x+y;
		house[i]=mp(X,Y);
	}
	cin>>m;
	REP(i,m){
		int x,y;scanf("%d%d",&x,&y);

		int X=x+y,Y=-x+y;
		pts[i]=mp(X,Y);
	}

	lint lb=-1,ub=1e10+1;

	int who=-1;
	while(ub-lb>1){
		lint md=(lb+ub)>>1;
		
		lint L=-INF,R=INF,top=INF,bot=-INF;

		REP(i,n){
			lint X=house[i].fr,Y=house[i].sc;

			chmax(L,X-md);
			chmin(R,X+md);
			chmax(bot,Y-md);
			chmin(top,Y+md);
		}
		int suc=0;
		REP(i,m){
			int X=pts[i].fr,Y=pts[i].sc;
			if(L<=X && X<=R && bot<=Y && Y<=top){
				suc=1;
				who=i;
				break;
			}
		}
		if(suc) ub=md;
		else lb=md;
	}

	lint ans=ub;

	cout<<ans<<endl<<who+1<<endl;

	return 0;
}