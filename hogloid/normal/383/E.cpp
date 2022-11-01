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

int cnt[1<<24];
int main(){
	cin>>n;
	char tmp[10];
	REP(hoge,n){
		scanf("%s",tmp);
		int mask=0;
		REP(i,3) mask|=(1<<(tmp[i]-'a'));

		int cur=mask;
		while(cur){
			int bits=__builtin_popcount(cur);
			cnt[cur]+=(bits&1?1:-1);
			cur=(cur-1)&mask;
		}
	}

	REP(i,24) REP(s,1<<24) if(s>>i&1) cnt[s]+=cnt[s^(1<<i)];

	int res=0;

	REP(i,1<<24) res^=(cnt[i]*cnt[i]);

	printf("%d\n",res);


	return 0;
}