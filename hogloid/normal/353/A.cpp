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

int n;

int main(){
	cin>>n;
	int sum=0,dif=0,sumA=0,sumB=0;
	REP(i,n){
		int a,b;cin>>a>>b;
		sum+=a+b;
		if((a%2)!=(b%2)) dif=1;
		sumA+=a;
		sumB+=b;
	}
	int res=0;
	if(sum%2) res=-1;
	else if(sumA%2==0 && sumB%2==0) res=0;
	else if(dif==0) res=-1;
	else res=1;

	printf("%d\n",res);
	return 0;
}