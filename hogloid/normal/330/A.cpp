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

int h,w;
char s[15][15];

int isevilR[15],isevilC[15];
int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",s[i]);
	REP(i,h) REP(j,w) if(s[i][j]=='S'){
		isevilR[i]=isevilC[j]=1;
	}
	int res=0;
	REP(i,h) REP(j,w) if(!isevilR[i] || !isevilC[j]) ++res;
	cout<<res<<endl;


	return 0;
}