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
int n,m,k;
int main(){
	cin>>n>>m>>k;
	vector<int> res;
	REP(i,k) res.pb(0);
	res.pb(n-1);
	REP(i,k-1) res.pb(n);
	
	if(k==1){
		if(m+2>n){
			if(n>2) res.pb(n+1);
			else{
				if(n==m) res.pb(n),res.pb(n+1);
				else res.pb(n);
			}
		}
	}else{
		if(n<=m) res.pb(n+1);
	}
	printf("%d\n",(int)res.size());
	REP(i,res.size()) printf("%d\n",res[i]+1);

	return 0;
}