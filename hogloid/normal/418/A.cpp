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

int n,k;
pi es[1000*1000];
int main(){
	cin>>n>>k;

	if(n<2*k+1) puts("-1");
	else{
		int cnt=0,m=2*k+1;
		REP(i,m){
			REP(j,k) es[cnt++]=mp(i,(i+j+1)%m);
		}

		REPN(i,n,m){
			REP(j,k) es[cnt++]=mp(i,j);
		}

		printf("%d\n",cnt);
		REP(i,cnt) printf("%d %d\n",es[i].fr+1,es[i].sc+1);

	}


	return 0;
}