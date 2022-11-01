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

const int INF=5e8;


int n,m;

pair<pi,pi> query[5005];

int add[5005];

int ar[5005];
int main(){
	cin>>n>>m;
	REP(i,n) ar[i]=INF;

	REP(i,m){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		if(a==1){
			--b;
			REPN(j,c,b) add[j]+=d;
		}else{
			--b;
			REPN(j,c,b) chmin(ar[j],d-add[j]);
		}
		query[i]=mp(mp(a,b),mp(c,d));
	}
	CLR(add);
	int fail=0;
	REP(i,m){
		int a=query[i].fr.fr,b=query[i].fr.sc,c=query[i].sc.fr,d=query[i].sc.sc;
		
		if(a==1){
			REPN(j,c,b) add[j]+=d;
		}else{
			int maxi=-INF;
			REPN(j,c,b) chmax(maxi,ar[j]+add[j]);
			if(maxi!=d){
				fail=1;
			}
		}
	}
	if(!fail){
		puts("YES");
		REP(i,n) printf("%d%c",ar[i],i==n-1?'\n':' ');
	}else puts("NO");






	return 0;
}