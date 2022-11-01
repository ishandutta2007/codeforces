#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cstdlib>
#include<cmath>
#define REP(num,num2) for(int num=0;num<(int)(num2);++num)
#define REPN(num,num2,init) for(int num=init;num<(int)(num2);++num)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define ITR(tp) __typeof((tp).begin())
#define SZ(t) ((int)t.size())
#define ALL(typ) (typ).begin(),(typ).end()
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
typedef vector<string> vs;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template<class T> inline void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> inline void chmax(T& a,const T& b) { if(a<b) a=b; }
int main(){
	int a1,a2,a3,a4;
	scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
	if(abs(a3-a4)>1){
		puts("-1");
		return 0;
	}
	if(a3-a4==1){//begin 4	and end 7
		if(a1-a4<=0 || a2-a4<=0){
			puts("-1");
			return 0;
		}
		REP(i,a1-a4) putchar('4');
		REP(i,a4) printf("74");
		REP(i,a2-a4) putchar('7');
	}else if(a4-a3==1){//begin 7 and end 4
		if(a1-a3<=0 || a2-a3<=0){
			puts("-1");
			return 0;
		}
		putchar('7');
		REP(i,a1-a3) putchar('4');
		REP(i,a4-2) printf("74");
		REP(i,a2-a3) putchar('7');
		putchar('4');
	}else{//	begin 4 and end 4
		if(a1-a3<=0 || a2-a3+1<=0){
			swap(a1,a2);
			if(a1-a3<=0 || a2-a3+1<=0){
				puts("-1");
				return 0;
			}
			REP(i,a3) printf("74");
			REP(i,a1-a3) putchar('7');
		}else{
			REP(i,a1-a3) putchar('4');
			REP(i,a3-1) printf("74");
			REP(i,a2-a3+1) putchar('7');
			putchar('4');
		}
	}
	putchar('\n');
	return 0;
}