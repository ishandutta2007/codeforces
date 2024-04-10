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
#define sz size()
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
int n,k;
pi p[1005];
int dist[1005][1005];
int zip[1000005];
int es[1000005],nxt[1000005],head[1005];
int deg[1005],mark[1005];
int m;
pi order[1005];
int used[1005];
int dfs(int ind,int k){
	if(k<0) return 0;
	while(ind<n && order[ind].fr!=-1 && mark[order[ind].sc]) ++ind;
	if(ind==n || order[ind].fr==-1){
		return 1;
	}
	int v=order[ind].sc;
	{// NOT USE
		int kk=k;
		for(int i=head[v];i!=-1;i=nxt[i]){
			int to=es[i];
			if(mark[to]==0){
				--kk;
				mark[to]=v+1;
				used[to]=1;
			}
		}
		if(dfs(ind+1,kk)){
			used[v]=0;
			return 1;
		}
		for(int i=head[v];i!=-1;i=nxt[i]){
			int to=es[i];
			if(mark[to]==v+1){
				mark[to]=0;
				used[to]=0;
			}
		}
	}
	if(deg[v]>1){//USE
		mark[v]=v+1;
		if(dfs(ind+1,k-1)){
			used[v]=1;
			return 1;
		}
		mark[v]=0;
	}
	return 0;
}
bool cmp(const pi& a,const pi& b){
	if(a.fr==0 || a.fr==1) return true;
	if(b.fr==0 || b.fr==1) return false;
	if(a.fr==-1) return false;
	if(b.fr==-1) return true;
	return a.fr<b.fr;
}
bool check(){
	memset(used,0,sizeof(used));
	memset(mark,0,sizeof(mark));
	REP(i,n) if(deg[i]>k) mark[i]=-1;

	int k2=k;
	int m2=m/2;
	REP(i,n) if(mark[i]){
		--k2;
		used[i]=1;
		for(int j=head[i];j!=-1;j=nxt[j]) --deg[es[j]],--m2;
	}
	if(m2>k2*k2 || k2<0) return false;
	REP(i,n) if(!mark[i]){
		while(head[i]!=-1 && mark[es[head[i]]]) head[i]=nxt[head[i]];
		for(int j=head[i];j!=-1;j=nxt[j]){
			int nx=nxt[j];
			while(nx!=-1 && mark[es[nx]]) nx=nxt[nx];
			nxt[j]=nx;
		}
	}
	memset(deg,0,sizeof(deg));
	REP(i,n) order[i]=mp(-1,-1);
	REP(i,n) if(!mark[i]){
		for(int j=head[i];j!=-1;j=nxt[j],++deg[i]);
		order[i]=mp(deg[i],i);
	}
	sort(order,order+n,greater<pi>());
	return dfs(0,k2);
}
			

int res[1005];
int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d%d",&p[i].fr,&p[i].sc);
	int cnt=0;
	REP(i,n) REP(j,n) dist[i][j]=SPR(p[i].fr-p[j].fr)+SPR(p[i].sc-p[j].sc),zip[cnt++]=dist[i][j];
	sort(zip,zip+cnt,greater<int>());
	int zn=unique(zip,zip+cnt)-zip;
	zip[zn]=0;
	int lb=-1,ub=zn;
	while(ub-lb>1){
		int md=(ub+lb)>>1,len=zip[md];
		m=0;
		memset(deg,0,sizeof(deg));
		memset(head,-1,sizeof(head));
		REP(i,n) REP(j,i) if(dist[i][j]>=len){
			es[m]=j;nxt[m]=head[i];head[i]=m++;
			es[m]=i;nxt[m]=head[j];head[j]=m++;
			++deg[i];++deg[j];
		}
		if(check()){
			lb=md;
			memcpy(res,used,sizeof(res));
		}else ub=md;
	}
	vi res2;
	REP(i,n) if(res[i]) res2.pb(i);
	REP(i,n) if(!res[i] && res2.size()<k) res2.pb(i);
	REP(i,k) printf("%d%c",res2[i]+1,i==k-1?'\n':' ');	
	return 0;
}