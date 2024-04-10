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
char buf[105][105];
void print(vector<pi>& a){
	REP(i,a.size()) printf("%d %d\n",a[i].fr+1,a[i].sc+1);
}
int main(){
	cin>>n;
	REP(i,n) scanf("%s",buf[i]);
	
	vector<pi> res;
	REP(i,n){
		REP(j,n) if(buf[i][j]=='.') {
			res.pb(mp(i,j));
			break;
		}
	}
	if(res.size()==n){
		print(res);
		return 0;
	}
	res.clear();
	REP(i,n){
		REP(j,n) if(buf[j][i]=='.'){
			res.pb(mp(j,i));
			break;
		}
	}
	if(res.size()==n) print(res);
	else puts("-1");


	return 0;
}