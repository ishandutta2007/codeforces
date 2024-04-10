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
char buf[5005][5005];

int conc1[5005][5005];

int cnt[5005];
int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);

	REP(i,h) for(int j=w-1;j>=0;--j){
		conc1[i][j]=(buf[i][j]=='0'?0:1+conc1[i][j+1]);
	}
	
	int res=0;
	for(int i=w-1;i>=0;--i){
		CLR(cnt);
		REP(j,h) cnt[conc1[j][i]]++;
		int sum=0;
		for(int j=w;j>=0;--j){
			sum+=cnt[j];
			chmax(res,j*sum);
		}
	}
	cout<<res<<endl;



	return 0;
}