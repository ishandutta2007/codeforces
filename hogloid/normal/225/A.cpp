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
pi dice[105];
int main(){
	int x;
	cin>>n>>x;
	REP(i,n) cin>>dice[i].fr>>dice[i].sc;

	int fail=0;
	REP(i,n-1){
		int bottom=7-x;
		if(!(dice[i+1].fr!=bottom && 7-dice[i+1].fr!=bottom && 
			dice[i+1].sc!=bottom && 7-dice[i+1].sc!=bottom)){
			fail=1;break;
		}
	}
	if(fail) puts("NO");
	else puts("YES");
	return 0;
}