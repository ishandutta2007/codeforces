#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int mat[105][105];
int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&mat[i][j]);
	int res=0;
	REP(i,n) REP(j,n) if(i==j || j==n-1-i || i==n/2 || j==n/2){
		res+=mat[i][j];
	}
	printf("%d\n",res);

	return 0;
}