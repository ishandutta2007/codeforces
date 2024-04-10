#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
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
vector<int> g[100005];
int name[100005];
map<string,int> id;
vector<pair<pi,int> >each[200005];
int cnt;
int begin[100005],end[100005],dep[100005];
void dfs(int v,int d=0){
	begin[v]=cnt++;
	dep[v]=d;
	REP(i,g[v].size()){
		int to=g[v][i];
		dfs(to,d+1);
	}
	end[v]=cnt++;
	each[d].pb(mp(mp(begin[v],end[v]),name[v]));
}

map<pi,int> answer;
int ar[100005];
int main(){
	cin>>n;
	vector<int> roots;
	REP(i,n){
		string tmp;
		int a;cin>>tmp>>a;
		--a;
		if(a!=-1) g[a].pb(i);
		else roots.pb(i);
		if(id.count(tmp)) name[i]=id[tmp];
		else name[i]=id[tmp]=id.size();
	}
	REP(i,roots.size()) dfs(roots[i]);
	REP(i,100005) sort(ALL(each[i]));
	cin>>m;
	REP(hoge,m){
		int v,k;cin>>v>>k;
		--v;
		if(answer.count(mp(v,k))){
			printf("%d\n",answer[mp(v,k)]);
			continue;
		}
		int want=dep[v]+k;
		if(each[want].size()==0){
			answer[mp(v,k)]=0;
			printf("%d\n",0);
			continue;
		}
		int lb=-1,ub=each[want].size();
		while(ub-lb>1){
			int md=(lb+ub)>>1;
			if(each[want][md].fr.sc<begin[v]) lb=md;
			else ub=md;
		}

		int left=ub,right;
		lb=-1;ub=each[want].size();
		while(ub-lb>1){
			int md=(lb+ub)>>1;
			if(end[v]<each[want][md].fr.fr) ub=md;
			else lb=md;
		}
		right=ub;
		if(left>=right){
			answer[mp(v,k)]=0;
			printf("%d\n",0);
			continue;
		}
		int cnt=0;
		REPN(i,right,left) ar[cnt++]=each[want][i].sc;
		sort(ar,ar+cnt);
		cnt=unique(ar,ar+cnt)-ar;
		answer[mp(v,k)]=cnt;
		printf("%d\n",cnt);
	}

	return 0;
}