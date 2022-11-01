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

int n,m;
double k;
map<string,int> skill;
int main(){
	cin>>n>>m>>k;
	REP(i,n){
		string s;int a;cin>>s>>a;
		if(a*k>=100-1e-9) skill[s]=a*k+1e-9;
	}
	REP(i,m){
		string s;cin>>s;
		if(skill.count(s)==0) skill[s]=0;
	}
	printf("%d\n",(int)skill.size());
	for(auto it:skill){
		printf("%s %d\n",it.fr.c_str(),it.sc);
	}


	return 0;
}