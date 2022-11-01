#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
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
int a[1000005];
pi rank[1000005];
lint ans[1000010];
set<int> done;
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) rank[i]=mp(a[i],i);
	sort(rank,rank+n);
	done.insert(-1);done.insert(n);
	REP(i,n){
		int x=rank[i].sc;
		done.insert(x);
		set<int>::iterator it=done.find(x);
		--it;
		int y=x-(*it);
		++it;++it;
		int z=(*it)-x;
		ans[1]+=rank[i].fr;ans[1+y]-=rank[i].fr;ans[1+z]-=rank[i].fr;ans[1+y+z]+=rank[i].fr;
	}
	REP(i,n+5) ans[i+1]+=ans[i];
	REP(i,n+5) ans[i+1]+=ans[i];
	int m;scanf("%d",&m);
	REP(i,m){
		int len;scanf("%d",&len);
		printf("%.11f\n",ans[len]/(double)(n+1-len));
	}
	return 0;
}