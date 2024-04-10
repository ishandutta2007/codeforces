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
int main(){
	cin>>n>>m;
	lint res=0;
	REP(i,n){
		int t,T,x,cost;
		scanf("%d%d%d%d",&t,&T,&x,&cost);
		int ride=(T-t);
		
		if(ride>0) res+=min(x*(lint)m,((m+ride-1)/ride-1)*(lint)cost)+cost;
		else res+=x*(lint)m+cost;
	}
	cout<<res<<endl;

	return 0;
}