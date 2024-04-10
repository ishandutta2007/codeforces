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
int perm[100005];
string f[100005],s[100005];

char tmp[55],tmp2[55];

bool dp[100005][2];
int main(){
	cin>>n;


	REP(i,n){
		scanf("%s%s",tmp,tmp2);
		f[i]=tmp;
		s[i]=tmp2;
	}
	REP(i,n){
		scanf("%d",&perm[i]);--perm[i];
	}
	prl;

	dp[0][0]=dp[0][1]=true;

	for(int i=1;i<n;++i){
		int cur=perm[i],last=perm[i-1];
		if(f[last]<f[cur]) dp[i][0]|=dp[i-1][0];
		if(f[last]<s[cur]) dp[i][1]|=dp[i-1][0];

		if(s[last]<f[cur]) dp[i][0]|=dp[i-1][1];
		if(s[last]<s[cur]) dp[i][1]|=dp[i-1][1];
	}
	if(dp[n-1][0] || dp[n-1][1]) puts("YES");
	else puts("NO");





	return 0;
}