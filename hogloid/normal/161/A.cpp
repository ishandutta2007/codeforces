#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define REP(num,num2) for(int num=0;num<(int)num2;++num)
#define REPN(num,num2,init) for(int num=init;num<(int)num2;++num)
#define ITR(x) __typeof((x).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define ALL(typ) (typ).begin(),(typ).end()
#define SPR(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz .size()
#define INF ((int)1e9)
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
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
int n,m,x,y;
pi sold[100005];
pi vest[100005];
pi res[100005];
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	REP(i,n) scanf("%d",&sold[i].fr),sold[i].sc=i;
	REP(i,m) scanf("%d",&vest[i].fr),vest[i].sc=i;
	sort(sold,sold+n);
	sort(vest,vest+m);
	int j=0;
	int cnt=0;
	REP(i,n){
		while(j<m && sold[i].fr-x>vest[j].fr) ++j;
		if(j<m && vest[j].fr<=sold[i].fr+y){
			res[cnt++]=mp(vest[j].sc,sold[i].sc);
			++j;
		}
	}
	printf("%d\n",cnt);
	REP(i,cnt) printf("%d %d\n",res[i].sc+1,res[i].fr+1);
	return 0;
}