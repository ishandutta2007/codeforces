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
int n,m;
pi es[1000005];
pi fix(int a,int b){
	if(a>b) return mp(b,a);
	return mp(a,b);
}
int mark[1000005],deg[1000005],zero[10000];
vector<int> res[10000];
void dfs(int v,int col){
	mark[v]=col;
	REP(i,n) if(i!=v && !binary_search(es,es+m,fix(v,i))){
		if(mark[i]==0) zero[col]=1;
		else if(mark[i]==-1) dfs(i,col);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		if(a>b) swap(a,b);
		++deg[a];++deg[b];
		es[i]=mp(a,b);
	}
	sort(es,es+m);
	int p=min_element(deg,deg+n)-deg;
	memset(mark,-1,sizeof(mark));
	REP(i,n) if(!binary_search(es,es+m,fix(p,i))) mark[i]=0;
	int cnt=1;
	REP(i,n) if(mark[i]==-1){
		dfs(i,cnt);
		++cnt;
	}
	int group=cnt;
	REP(i,cnt) if(zero[i]) --group;
	printf("%d\n",group);
	int actual=0;
	REP(i,group){
		int counter=0;
		while(zero[actual]) ++actual;
		REP(j,n) if((zero[mark[j]]==0 && mark[j]==actual) || (i==0 && zero[mark[j]])) ++counter;
		printf("%d",counter);
		REP(j,n) if((zero[mark[j]]==0 && mark[j]==actual)|| (i==0 && zero[mark[j]])) printf(" %d",j+1);
		putchar('\n');
		++actual;
	}
	
	return 0;
}