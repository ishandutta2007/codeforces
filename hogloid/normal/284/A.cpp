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

int main(){
	int p;scanf("%d",&p);
	int res=0;
	for(int i=1;i<p;++i){
		int mul=1;
		int fail=0;
		for(int j=1;j<p;++j){
			mul*=i;
			mul%=p;
			if((j==p-1 && (mul-1)%p) ||
				j<p-1 && (mul-1)%p==0) fail=1;
		}
		if(!fail) ++res;
	}
	cout<<res<<endl;
	return 0;
}