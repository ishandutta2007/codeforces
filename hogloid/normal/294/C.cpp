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
int n,m;
int mark[1005];
lint C[1005][1005];
const lint mod=1000000007;
lint pow2[1005];
int main(){
	pow2[0]=1;
	REP(i,1000) pow2[i+1]=2*pow2[i]%mod;
	REP(i,1005){
		C[i][0]=1;
		REP(j,i) C[i][j+1]=(C[i-1][j+1]+C[i-1][j])%mod;
	}

	scanf("%d%d",&n,&m);
	REP(i,m){
		int p;scanf("%d",&p);--p;
		mark[p]=1;
	}
	lint res=1;
	int ever=0;
	REP(i,n) if(!mark[i]){
		int j=i;
		while(j<n && !mark[j]) ++j;
		ever+=j-i;
		res=(res*C[ever][j-i])%mod;
		if(i>0 && j<n) res=res*pow2[j-i-1]%mod;
		i=j-1;
	}
	cout<<res<<endl;
	return 0;
}