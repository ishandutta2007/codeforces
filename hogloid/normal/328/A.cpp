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

int ar[5];
int main(){
	REP(i,4) cin>>ar[i];
	int d=ar[1]-ar[0];
	if(ar[3]-ar[2]==d && ar[2]-ar[1]==d){
		printf("%d\n",ar[3]+d);
		return 0;
	}
	if(ar[0]*ar[2]==ar[1]*ar[1] && ar[1]*ar[3]==ar[2]*ar[2]){
		int res=ar[3]*ar[3]/ar[2];
		if(ar[3]*ar[3]%ar[2]) puts("42");
		else printf("%d\n",res);
	}else puts("42");

	return 0;
}