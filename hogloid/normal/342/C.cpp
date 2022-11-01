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
#include<cmath>
int main(){
	int r,h;
	cin>>r>>h;
	
	int h2=h/r;
	int res;
	if((h%r)*2>=r) res=h2*2+2;

	double h3=h/(double)r+1-sqrt(3.0)/2;
	res=max(res,1+2*(int)h3);

	printf("%d\n",res);
	return 0;
}