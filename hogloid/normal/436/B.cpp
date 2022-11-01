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

int n,m,k;
char buf[2005][2005];

int res[2005];
int main(){
	cin>>n>>m>>k;
	REP(i,n) scanf("%s",buf[i]);

	REP(i,m){
		int cnt=0;
		for(int j=1;i-j>=0 && j<n;++j) if(buf[j][i-j]=='R') ++cnt;
		for(int j=1;i+j<m && j<n;++j)  if(buf[j][i+j]=='L') ++cnt;
		for(int j=2;j<n;j+=2) if(buf[j][i]=='U') ++cnt;

		res[i]=cnt;
	}
	REP(i,m) printf("%d%c",res[i],i==m-1?'\n':' ');

	return 0;
}