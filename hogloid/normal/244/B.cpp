#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
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
int dp[20][15][15];
set<int> all;
int X,Y;
int n;
void dfs(int num){
	lint a=num*10ll+X;
	if(a<=n){
		all.insert(a);
		dfs(a);
	}
	a=num*10ll+Y;
	if((num>0 || Y>0) && a<=n){
		all.insert(a);
		dfs(a);
	}
}
int main(){
	cin>>n;
	for(X=0;X<10;++X) for(Y=0;Y<X;++Y) dfs(0);
	cout<<all.size()<<endl;

	return 0;
}