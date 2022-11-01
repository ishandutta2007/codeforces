#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<functional>
#include<list>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cstdlib>
#include<cmath>
#include<climits>
#define REP(num,num2) for(int num=0;num<(int)(num2);++num)
#define REPN(num,num2,init) for(int num=init;num<(int)(num2);++num)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define ITR(tp) __typeof((tp).begin())
#define SZ(t) ((int)t.size())
#define ALL(typ) (typ).begin(),(typ).end()
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define RANGE(t,n) (t).begin(),(t).begin()+n
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
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
typedef vector<string> vs;
const double PI  = acos(-1.0);
int n,k;
int nxt[100005],head[50001];
pi es[100005];
int ecnt;
int cut[50001];
int size[50001];
int balance,bestroot;
int len[50001],cnt;
int lim;
int getsize(int v,int p){
	int& res=size[v];
	res=1;
	for(int i=head[v];i!=-1;i=nxt[i]){
		pi& e=es[i];
		if(e.fr==p || cut[e.fr]) continue;
		res+=getsize(e.fr,v);
	}
	return res;
}
void getroot(int v,int root,int p){
	int maxi=size[root]-size[v];
	for(int i=head[v];i!=-1;i=nxt[i]){
		pi& e=es[i];
		if(e.fr==p || cut[e.fr]) continue;
		maxi=max(maxi,size[e.fr]);
		getroot(e.fr,root,v);
	}
	if(maxi<balance){
		balance=maxi;
		bestroot=v;
	}
}
void getdist(int v,int p,int dep){
	len[cnt++]=dep;
	for(int i=head[v];i!=-1;i=nxt[i]){
		pi& e=es[i];
		if(cut[e.fr] || e.fr==p || dep+e.sc>lim) continue;
		getdist(e.fr,v,dep+e.sc);
	}
}
lint getconnect(int v){
	cnt=0;
	getdist(v,-1,0);
	sort(len,len+cnt);
	lint res=0;
	REP(i,cnt){
		res+=(upper_bound(len,len+cnt,lim-len[i])-lower_bound(len,len+cnt,lim-len[i]));
	}
	return res;
}

lint dfs(int v){
	getsize(v,-1);
	bestroot=-1;balance=INF;
	getroot(v,v,-1);
	if(size[v]==1) return 0;
	v=bestroot;
	cut[v]=1;
	lint con=0;
	for(int i=head[v];i!=-1;i=nxt[i]){
		pi& e=es[i];
		if(cut[e.fr]) continue;
		con+=dfs(e.fr);
	}
	lim=k;
	con+=getconnect(v);
	for(int i=head[v];i!=-1;i=nxt[i]){
		pi& e=es[i];
		if(cut[e.fr]) continue;
		lim=k-e.sc*2;
		con-=getconnect(e.fr);
	}
	cut[v]=0;
	return con;
}
int main(){
	scanf("%d%d",&n,&k);
	memset(cut,0,sizeof(cut));memset(size,-1,sizeof(size));
	ecnt=0;
	memset(nxt,0,sizeof(nxt));memset(head,-1,sizeof(head));
	REP(i,n-1){
		int a,b,c;scanf("%d%d",&a,&b);--a;--b;c=1;
		es[ecnt]=mp(b,c);nxt[ecnt]=head[a];head[a]=ecnt;++ecnt;
		es[ecnt]=mp(a,c);nxt[ecnt]=head[b];head[b]=ecnt;++ecnt;
	}
	cout<<dfs(0)/2<<endl;
	return 0;
}