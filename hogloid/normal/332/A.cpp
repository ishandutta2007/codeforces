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
char seq[2005];
int main(){
	scanf("%d%s",&n,seq);
	int m=strlen(seq);
	int res=0;
	for(int i=n;i<m;i+=n){
		if(seq[i-3]==seq[i-2] && seq[i-2]==seq[i-1]) ++res;
	}
	printf("%d\n",res);

	return 0;
}