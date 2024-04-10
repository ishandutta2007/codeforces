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
	
	if(m==3 && n>=5) puts("-1");
	else if(m==3 && n==4) printf("0 0\n3 0\n0 3\n1 1\n");
	else{
		REP(i,m) printf("%d %d\n",i,i*i+10000000);
		REP(i,n-m) printf("%d %d\n",i,-i*i-10000000);
	}



	return 0;
}