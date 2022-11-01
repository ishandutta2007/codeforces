#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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
int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		mark[a]=mark[b]=1;
	}
	int root;
	REP(i,n) if(!mark[i]) root=i;

	printf("%d\n",n-1);
	REP(i,n) if(i!=root){
		printf("%d %d\n",i+1,root+1);
	}

	return 0;
}