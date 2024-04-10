#include<iostream>
#include<cmath>
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
int R,r;
const double PI=acos(-1.0);
int main(){
	cin>>n>>R>>r;
	
	if(R<r){
		puts("NO");
		return 0;
	}else if(R-r<r){
		puts(n==1?"YES":"NO");
		return 0;
	}

	
	double h=sqrt((double)(R-r)*(R-r)-r*r);

	double theta=atan2(h,r);
	double theta2=(PI-2*theta);
	if(theta2*n>2*PI+1e-8) puts("NO");
	else puts("YES");
	

	return 0;
}