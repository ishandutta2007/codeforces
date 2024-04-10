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

int exist[185];
int main(){
	for(int i=1;i<=365;++i){
		if(180*i%(i+2)==0) exist[180*i/(i+2)]=1;
	}
	int t;scanf("%d",&t);
	while(t--){
		int a;scanf("%d",&a);
		printf("%s\n",exist[a]?"YES":"NO");
	}

	return 0;
}