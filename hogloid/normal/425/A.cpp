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

int ar[205];
int n,k;

const int INF=5e8;
int tmp[205],cnt;
int tmp2[205],cnt2;
int main(){
	cin>>n>>k;
	REP(i,n) cin>>ar[i];
	
	int ans=-INF;
	debug(ar,ar+n);
	REP(i,n) REPN(j,n+1,i+1){//[i..j)
		int len=j-i;
		
		cnt=cnt2=0;
		REP(i2,len) tmp[cnt++]=ar[i+i2];

		REP(i2,i) tmp2[cnt2++]=ar[i2];
		REPN(i2,n,j) tmp2[cnt2++]=ar[i2];

		sort(tmp2,tmp2+cnt2,greater<int>());

		REP(i2,min(k,cnt2)) tmp[cnt++]=tmp2[i2];

		sort(tmp,tmp+cnt,greater<int>());

		int sum=0;
		REP(i2,len) sum+=tmp[i2];
		debug(tmp,tmp+len);
		dump(sum);dump(i);dump(j);
		chmax(ans,sum);
	}
	
	cout<<ans<<endl;

	return 0;
}