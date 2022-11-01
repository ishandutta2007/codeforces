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

int g[405][405];
int n,m;
int main(){
	cin>>n>>m;
	char s1[30],s2[30];
	scanf("%s",s1);
	scanf("%s",s2);

	REP(i,n) REP(j,m){
		int id=i*m+j;
		if(s1[i]=='>' && j+1<m){
			int id2=id+1;
			g[id][id2]=1;
		}
		if(s1[i]=='<' && j>0){
			int id2=id-1;
			g[id][id2]=1;
		}
		if(s2[j]=='v' && i+1<n){
			int id2=id+m;
			g[id][id2]=1;
		}
		if(s2[j]=='^' && i>0){
			int id2=id-m;
			g[id][id2]=1;
		}
	}
	int V=n*m;
	REP(i,V) g[i][i]=1;
	REP(i,V) REP(j,V) REP(k,V) g[j][k]|=(g[j][i]&&g[i][k]);
	
	int fail=0;
	REP(i,V) REP(j,V) if(!g[i][j]){
		fail=1;
	}
	puts(fail?"NO":"YES");

	return 0;
}