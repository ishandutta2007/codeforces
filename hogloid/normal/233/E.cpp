#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
lint fib[1005];
int t,n;
lint memo[2][2][100];
lint dfs2(lint,int,int);
lint dfs1(lint a,int type,int n){
	if(n<=0) return 0;
	lint& res=memo[0][type][n];
	if(res!=-1) return res;
	if(n==1) return res=(a==0?0:1);
	if(a>=fib[n-1]) return res=dfs1(a-fib[n-1],type,n-2)+1;
	return res=min(dfs1(a,type,n-1),dfs2(a,type,n-1)+2);
}//connect to 0

lint dfs2(lint a,int type,int n){
	if(n<=0) return 0;
	lint& res=memo[1][type][n];
	if(res!=-1) return res;
	if(n==1) return res=(a==1?0:1);
	if(a>=fib[n-1]) return res=dfs2(a-fib[n-1],type,n-2);
	return res=min(dfs2(a,type,n-1),dfs1(a,type,n-1))+1+(n-2+1)/2;
}//connect to fib[n-1]
lint solve(lint a,lint b,lint n){
	if(a>b) swap(a,b);
	if(a==b) return 0;
	if(a<fib[n-1] && b<fib[n-1]){
		lint tmp=solve(a,b,n-1);
		tmp=min(dfs1(a,0,n-1)+dfs2(b,1,n-1)+2,tmp);
		tmp=min(dfs2(a,0,n-1)+dfs1(b,1,n-1)+2,tmp);
		return tmp;
	}
	if(a>=fib[n-1] && b>=fib[n-1]) return solve(a-fib[n-1],b-fib[n-1],n-2);
	return min(dfs1(a,0,n-1),dfs2(a,0,n-1))+1+dfs1(b-fib[n-1],1,n-2);
}
	

int main(){
	fib[0]=1;
	fib[1]=2;fib[2]=3;
	REPN(i,155,3) {
		fib[i]=fib[i-2]+fib[i-1];
	}

	cin>>t>>n;
	n=min(n,90);

	REP(hoge,t){
		lint a,b;cin>>a>>b;--a;--b;
		memset(memo,-1,sizeof(memo));
		cout<<solve(a,b,n)<<endl;
	}
	
	return 0;
}