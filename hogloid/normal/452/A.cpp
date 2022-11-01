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
string names[]={"vaporeon", "jolteon", "flareon", "espeon",
	"umbreon", "leafeon", "glaceon", "sylveon"};
bool eq(string a,string b){
	if(a.size()!=b.size()) return false;
	REP(i,a.size()) if(!(b[i]==a[i] || a[i]=='.')) return false;
	return true;
}

int main(){
	int len;cin>>len;
	string tmp;cin>>tmp;

	REP(i,8) if(eq(tmp,names[i])){
		cout<<names[i]<<endl;
	}




	return 0;
}