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
int n;
int seq[200005];
int main(){
	scanf("%d",&n);
	int sum=0;
	REP(i,n) scanf("%d",&seq[i]),sum+=seq[i];
	vector<int> res;
	REP(i,n){
		int other=sum-seq[i];
		if(other==seq[i]*(n-1)) res.pb(i);
	}
	printf("%d\n",(int)res.size());
	REP(i,res.size()) printf("%d\n",res[i]+1);

	return 0;
}