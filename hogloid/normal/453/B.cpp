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
bool isprime(int a){
	if(a==1) return false;
	for(int i=2;i*i<=a;++i) if(a%i==0) return false;
	return true;
}

const int INF=5e8;
int MX=58;
int n;
int ar[105];
int dp[105][1<<17];
int id[60];
int bit[60];

int back[105][1<<17];
int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];

	int cnt=0;
	memset(id,-1,sizeof(id));
	for(int i=2;i<=MX;++i) if(isprime(i)){
		id[i]=cnt++;
	}

	for(int i=1;i<=MX;++i) {
		if(id[i]>=0) bit[i]=(1<<id[i]);
		else{
			for(int j=1;j<i;++j) if(id[j]>=0 && i%j==0) bit[i]|=(1<<id[j]);
		}
	}
	
	REP(i,105) REP(j,1<<17) dp[i][j]=INF;
	dp[0][0]=1;
	
	REP(i,n) REP(j,1<<cnt) if(dp[i][j]<INF){

		for(int k=1;k<=MX;++k) if(!(j&bit[k])){
			if(dp[i+1][j|bit[k]]>dp[i][j]+abs(k-ar[i])){
				dp[i+1][j|bit[k]]=dp[i][j]+abs(k-ar[i]);
				back[i+1][j|bit[k]]=k;
			}
		}
	}

	int res=INF;
	vector<int> path;
	REP(i,1<<17) if(res>dp[n][i]){
		res=dp[n][i];
		
		int cur=i;
		path.clear();

		for(int j=n;j>0;--j) {
			path.pb(back[j][cur]);
			cur^=(bit[back[j][cur]]);
		}
	}

	reverse(ALL(path));
	REP(i,path.size()) printf("%d%c",path[i],i==path.size()-1?'\n':' ');

	return 0;
}