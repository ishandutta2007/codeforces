
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

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



//const int INF=5e8;
	
int n;
char buf[305][305];
int main(){
	cin>>n;
	REP(i,n) scanf("%s",buf[i]);

	set<char> diag,other;
	REP(i,n) diag.insert(buf[i][i]),diag.insert(buf[i][n-1-i]);
	REP(i,n) REP(j,n){
		if(i!=j && i!=n-1-j) other.insert(buf[i][j]);
	}
	if(diag.size()==1 && other.size()==1 && *diag.begin()!=*other.begin()){
		puts("YES");
	}
	else puts("NO");

	return 0;
}