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

const int INF=1e9;
struct seg2{
	vector<pi> val[400005];
	vector<int> uppmost[400005];
	int n;
	void init(int n_,pair<int,pi>* a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			val[i+n-1].pb(a[i].sc);
		}
		for(int i=n-2;i>=0;--i){
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
		}

		REP(i,n*2){
			uppmost[i].pb(-INF);
			int ever=-INF;
			REP(j,val[i].size()){
				chmax(ever,val[i][j].sc);
				uppmost[i].pb(ever);
			}
			dump(val[i].size());dump(uppmost[i].size());
		}
		dump(n);
	}
	bool query(int a,int b,int lb,int ub,int i,int l,int r){
		if(a<=l && r<=b){//[lb...ub]
			int R=lower_bound(ALL(val[i]),mp(lb+1,-INF))-val[i].begin();
			dump(i);dump(l);dump(r);dump(val[i].size());
			dump(R);dump(uppmost[i][R]);
			if(uppmost[i][R]>=ub) return true;
			return false;
		}
		if(b<=l || r<=a) return false;
		int md=(l+r)>>1;
		return (query(a,b,lb,ub,i*2+1,l,md) || query(a,b,lb,ub,i*2+2,md,r));
	}
};
seg2 seg;
int n1,n2;
pair<int,pi> vert[50005],horz[50005];

bool check(int md){
	dump(md);
	REP(i,n2){
		int x=horz[i].sc.fr,y=horz[i].fr,l=horz[i].sc.sc-horz[i].sc.fr;

		int lb=lower_bound(vert,vert+n1,mp(x+md,mp(-INF,-INF)))-vert,
				ub=lower_bound(vert,vert+n1,mp(x+l-md+1,mp(-INF,-INF)))-vert;
		
		if(lb<ub){
			dump(lb);dump(ub);
			if(seg.query(lb,ub,y-md,y+md,0,0,seg.n)){
			dump(i);
			dump(horz[i]);
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin>>n1>>n2;
	REP(i,n1){
		int x,y,l;scanf("%d%d%d",&x,&y,&l);
		vert[i]=mp(x,mp(y,y+l));
	}
	sort(vert,vert+n1);
	seg.init(n1,vert);

	REP(i,n2){
		int x,y,l;scanf("%d%d%d",&x,&y,&l);
		horz[i]=mp(y,mp(x,x+l));
	}
	

	int lb=0,ub=100000005;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(check(md)) lb=md;
		else ub=md;
	}
	cout<<lb<<endl;



	return 0;
}