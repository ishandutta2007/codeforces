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
int ar[1005];
vector<pi> res;

void solve(int& a,int& b,int& c){
	if(ar[a]>ar[b]) swap(a,b);
	if(ar[b]>ar[c]) swap(b,c);
	if(ar[a]>ar[b]) swap(a,b);

	if(ar[a]==0) return;

	int div=ar[b]/ar[a];
	while(div>0){
		if(div&1){
			res.pb(mp(a,b));
			ar[b]-=ar[a];
			ar[a]*=2;
		}else{
			res.pb(mp(a,c));
			ar[c]-=ar[a];
			ar[a]*=2;
		}

		div>>=1;
	}
	swap(a,b);

	solve(a,b,c);
}

int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	
	int a=0,b=1,c=2;
	for(int i=3;i<=n;++i){
		solve(a,b,c);
		a=i;
	}
	if(ar[b]>0 && ar[c]>0){
		cout<<res.size()<<endl;
		REP(i,res.size()) printf("%d %d\n",res[i].fr+1,res[i].sc+1);
	}
	else puts("-1");
	return 0;
}