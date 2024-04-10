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


int n,m;
int ar[105];
int eve[25];

bool done[1<<20];
int dp[1<<20];
int rec(int bit,int idx){
	if(idx==m) return 0;
	if(done[bit]) return dp[bit];

	int& res=dp[bit];
	if(!(eve[idx]&1)){
		res=-INF;
		if(eve[idx]&2){
			REP(i,n) if(!(bit>>i&1)) chmax(res,rec(bit^(1<<i),idx+1)+ar[i]);
		}else{
			REP(i,n) if(!(bit>>i&1)) chmax(res,rec(bit^(1<<i),idx+1));
		}
	}else{
		res=INF;
		if(eve[idx]&2){
			REP(i,n) if(!(bit>>i&1)) chmin(res,rec(bit^(1<<i),idx+1)-ar[i]);
		}else{
			REP(i,n) if(!(bit>>i&1)) chmin(res,rec(bit^(1<<i),idx+1));
		}
	}
	done[bit]=1;
	dump(bit);dump(res);
	return res;
}

		
int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	cin>>m;
	REP(i,m){
		char tmp[5];
		int t;scanf("%s%d",tmp,&t);


		if(tmp[0]=='p') eve[i]|=2;
		if(t==2) eve[i]|=1;
	}
	sort(ar,ar+n,greater<int>());
	n=m;

	int res=rec(0,0);

	cout<<res<<endl;



	return 0;
}