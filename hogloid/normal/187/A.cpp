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
int perm[200005],repl[200005];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&perm[i]),--perm[i];
	REP(i,n){
		int tmp;
		scanf("%d",&tmp);
		--tmp;
		repl[tmp]=i;
	}
	REP(i,n) perm[i]=repl[perm[i]];
	
	int last=-1,len;
	REP(i,n){
		if(last<perm[i]){
			last=perm[i];
			len=i+1;
		}else break;
	}
	printf("%d\n",n-len);
	return 0;
}