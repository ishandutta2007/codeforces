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
const lint INF2=2000000005;
typedef pair<int,int> pi;

int a,b,k;
static const int N=10000000+5;
int minp[N];

int up;
vector<int> prm;
lint dfs(int d,int sign,lint sum){
	if(sum>up) return 0;
	if(d==prm.size()){
		return up/sum*sign;
	}
	return dfs(d+1,sign,sum)+dfs(d+1,-sign,sum*prm[d]); 
}
bool isprime(int n){
	for(int i=2;i*i<=n;++i) if(n%i==0) return false;
	return true;
}

int solve(int up,int k){
	if(!isprime(k)) return 0;
	up/=k;
	if(up<N){
		int res=0;
		REP(i,up+1) if(minp[i]>=k) ++res;
		return res;
	}
	::up=up;
	prm.clear();
	REP(i,k) if(minp[i]==i) prm.pb(i);
	return dfs(0,1,1)+1;
}

int main(){
	REP(i,N) minp[i]=i;
	minp[0]=minp[1]=INF2;
	for(int i=2;i*i<N;++i) if(minp[i]==i){
		for(int j=i*i;j<N;j+=i) if(minp[j]==j) minp[j]=i;
	}


	cin>>a>>b>>k;

	printf("%d\n",solve(b,k)-solve(a-1,k));

	return 0;
}