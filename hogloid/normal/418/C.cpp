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
//const int mod=5e8;


inline int spr(int a) { return a*a; }
vector<int> solve(int n){
	vector<int> res;
	if(n==1) res.pb(1);
	else if(n==2) res.pb(3),res.pb(4);
	else if(n&1){
		REP(i,n-2) res.pb(1);
		res.pb(2);
		res.pb((n+3)/2-1);
	}else{
		REP(i,n-1) res.pb(1);
		res.pb((n/2)-1);
	}
	return res;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> row=solve(n),col=solve(m);

	REP(i,n) REP(j,m) printf("%d%c",row[i]*col[j],j==m-1?'\n':' ');


	return 0;
}