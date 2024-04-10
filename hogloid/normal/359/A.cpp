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

int h,w;
int buf[100][100];
int main(){
	cin>>h>>w;
	int res=4;
	REP(i,h) REP(j,w){

		cin>>buf[i][j];
		if(buf[i][j] && (i==0 || j==0 || i==h-1 || j==w-1)) res=2;
	}
	printf("%d\n",res);




	return 0;
}