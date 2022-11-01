
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

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



//const int INF=5e8;
	

char s[1000005];
int dp[2][4][4];
int n;

const int mod=1000000007;
int conv[300];
int main(){
	scanf("%s",s);
	n=strlen(s);
	if(n==1){
		int res;
		if(s[0]=='*' || s[0]=='0') res=1;
		else if(s[0]=='?') res=2;
		else res=0;
		printf("%d\n",res);
		return 0;
	}
	
	conv['0']=0;conv['1']=1;conv['2']=2;
	conv['*']=3;conv['?']=4;
	int cur=0,nxt=1;
	REP(i,4) REP(j,4){
		if((conv[s[0]]==4 || conv[s[0]]==i) &&
			(conv[s[1]]==4 || conv[s[1]]==j)){

			if(i<3 && i!=(j==3?1:0)) continue;
			dp[cur][i][j]++;
		}
	}

	for(int i=2;i<n;++i){
		REP(j,4) REP(k,4) if(dp[cur][j][k]>0){
			REP(l,4) if(conv[s[i]]==4 || conv[s[i]]==l){
				if(k<3 && k!=(j==3)+(l==3)) continue;
				dp[nxt][k][l]+=dp[cur][j][k];
				if(dp[nxt][k][l]>=mod) dp[nxt][k][l]-=mod;
			}
		}
		swap(cur,nxt);
		CLR(dp[nxt]);
	}
	
	int res=0;
	REP(i,4) REP(j,4) if(dp[cur][i][j]>0){
		if(j<3 && j!=(i==3)) continue;
		res+=dp[cur][i][j];
		if(res>=mod) res-=mod;
	}
	cout<<res<<endl;


	return 0;
}