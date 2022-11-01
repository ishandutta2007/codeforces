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

int n;
int ar[10005];
int piv[35];

void swp(vector<pi>& ans,int x,int y){
	ans.pb(mp(x,y));
	ans.pb(mp(y,x));
	ans.pb(mp(x,y));

	swap(ar[x],ar[y]);
}
int who[35];
int aff[35][10005];

pair<vector<pi>,vector<int> > solve(){
	vector<pi> ans;
	int rank=0;
	vector<int> unit;
	for(int i=0;i<30;++i){
		int idx=-1;
		REPN(j,n,rank) if(ar[j]>>i&1){
			idx=j;
			break;
		}
		if(idx==-1) continue;
		if(idx!=rank) swp(ans,rank,idx);
		piv[rank]=i;

		REP(j,n) if(j!=rank && ar[j]>>i&1){
			ans.pb(mp(j,rank));
			ar[j]^=ar[rank];
		}
		++rank;
	}
	REP(i,rank) unit.pb(ar[i]);
	return mp(ans,unit);
}

int mark[35];


int init1[10005],init2[10005];
int main(){
	cin>>n;
	REP(i,n){
		cin>>ar[i];
		init1[i]=ar[i];
	}

	pair<vector<pi>,vector<int> > res_=solve();
	vector<pi> res=res_.fr;

	REP(i,n){
		cin>>ar[i];
		init2[i]=ar[i];
	}

	pair<vector<pi>,vector<int> > res2_=solve();
	vector<pi> res2=res2_.fr;

	vector<int> A=res_.sc,B=res2_.sc;
	if(A.size()<B.size()){
		puts("-1");
		return 0;
	}
	debug(ALL(A));debug(ALL(B));
	REP(i,A.size()){
		int low=__builtin_ffs(A[i])-1;
		REP(j,B.size()) if(B[j]>>low&1 && i!=j){
			res.pb(mp(j,i));
			A[j]^=A[i];
		}
		if(i>=B.size() || !(B[i]>>low&1)) {
			A[i]=0;
			res.pb(mp(i,i));
		}
	}
	debug(ALL(A));
	res.insert(res.end(),res2.rbegin(),res2.rend());

	REP(i,res.size()){
		int a=res[i].fr,b=res[i].sc;
		init1[a]^=init1[b];
	}
	debug(init1,init1+n);
	debug(init2,init2+n);
	int fail=0;
	REP(i,n) if(init2[i]!=init1[i]) fail=1;
	if(fail) puts("-1");
	else{
		cout<<res.size()<<endl;
		REP(i,res.size()) printf("%d %d\n",res[i].fr+1,res[i].sc+1);
	}

	return 0;
}