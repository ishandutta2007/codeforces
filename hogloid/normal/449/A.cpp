#define DEB

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
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

lint n,m,k;
int main(){
	cin>>n>>m>>k;
	
	lint res=-1;
	for(int i=0;i<=min(100000ll,n-1) && i<=k;++i){
		if(m>=(k-i+1)) chmax(res,(n/(i+1))*(m/(k-i+1)));
	}

	for(lint i=1;i<=min(n,100000ll);++i){
		lint split=n/i-1;
		if(k-split+1<=m) chmax(res,i*(m/max(1ll,k-split+1)));
	}

	cout<<res<<endl;



	return 0;
}