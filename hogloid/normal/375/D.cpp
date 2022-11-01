#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;
typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> set_t;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

const int INF=5e8;
int n,m;
vector<int> g[100005];
int col[100005];

vector<pi> query[100005];//(k,id)

int res[100005];
map<int,int> subcnt[100005];//(color,size)
set_t sizes[100005];//(size,color);

void merge(map<int,int>& a,map<int,int>& b,set_t& A,set_t& B){
	if(a.size()<b.size()){
		a.swap(b);
		A.swap(B);
	}
	for(auto elem:b){
		if(a.count(elem.fr)>0) A.erase(mp(a[elem.fr],elem.fr));
		a[elem.fr]+=elem.sc;
		A.insert(mp(a[elem.fr],elem.fr));
	}
}

void dfs(int v,int p){
	subcnt[v][col[v]]++;
	sizes[v].insert(mp(1,col[v]));
	for(auto to:g[v]){
		if(to==p) continue;
		dfs(to,v);
		merge(subcnt[v],subcnt[to],sizes[v],sizes[to]);
	}
	for(auto q:query[v]){
		int tmp=sizes[v].order_of_key(mp(q.fr,-1));
		tmp=sizes[v].size()-tmp;
		res[q.sc]=tmp;
	}
	
}


int main(){
	cin>>n>>m;
	REP(i,n) scanf("%d",&col[i]);

	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,m){
		int v,k;scanf("%d%d",&v,&k);
		--v;
		query[v].pb(mp(k,i));
	}
	
	dfs(0,-1);

	REP(i,m) printf("%d\n",res[i]);


	return 0;
}