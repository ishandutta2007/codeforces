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
int n;
int one,two;
lint base[1000005];
const lint mod=1000000007;
int main(){
	int n;
	scanf("%d",&n);
	int one=0,two=0;
	REP(i,n) {
		int t;scanf("%d",&t);
		if(t==1) ++one;
		else ++two;
	}

	base[0]=base[1]=1;
	for(int i=2;i<=one;++i){
		base[i]=base[i-1]+base[i-2]*(i-1);
		base[i]%=mod;
	}
	
	lint res=base[one];
	REP(i,two){
		res*=one+1+i;
		res%=mod;
	}
	cout<<res<<endl;

	return 0;
}