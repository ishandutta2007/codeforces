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

int h,w;
int buf[1005][1005];
bool ok[1005][1005];
int nxt[1005][1005];

bool exi[1005];
bool check(int k){
	CLR(ok);
	REP(i,h) REP(j,w) if(buf[i][j]>=k) ok[i][j]=1;
	REP(i,h){
		int pos=-1;
		for(int j=w-1;j>=0;--j){
			nxt[i][j]=pos;
			if(ok[i][j]) pos=j;
		}
	}
	
	REP(i,w){
		CLR(exi);
		REP(j,h) if(ok[j][i]){
			int cur=nxt[j][i];
			while(cur!=-1){
				if(!exi[cur]) exi[cur]=1;
				else return true;
				cur=nxt[j][cur];
			}
		}
	}
	return false;
}

int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w) scanf("%d",&buf[i][j]);

	int lb=0,ub=1000000005;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(check(md)) lb=md;
		else ub=md;
	}
	cout<<lb<<endl;

	return 0;
}