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
int n,w,b;
const lint mod=1000000009;
int C[4005][4005];
int main(){
	REP(i,4003){
		C[i][0]=1;
		REP(j,i) C[i][j+1]=(C[i-1][j+1]+C[i-1][j])%mod;
	}

	cin>>n>>w>>b;
	lint res=0;

	REPN(l,n-1,1) REPN(r,n,l+1){
		int len=r-l,wlen=n-len;
		if(b-len<0 || w-wlen<0) continue;
		res+=C[b-1][b-len]*(lint)C[w-1][w-wlen]%mod;
		res%=mod;
	}

	REP(i,w) res=res*(i+1)%mod;
	REP(i,b) res=res*(i+1)%mod;

	cout<<res<<endl;

	return 0;
}