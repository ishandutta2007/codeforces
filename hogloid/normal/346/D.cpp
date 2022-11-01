#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


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
vector<int> g[1000005],rg[1000005];

int out[1000005],in[1000005];
int out_done[1000005];

int cost[1000005];
int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		rg[b].pb(a);
		++out[a];
		++in[b];
	}

	int s,t;cin>>s>>t;
	--s;--t;

	REP(i,n) cost[i]=INF;
	cost[t]=0;

	deque<pi> dq;dq.pb(mp(0,t));
	while(!dq.empty()){
		pi cur=dq.front();dq.pop_front();
		int v=cur.sc,c=cur.fr;

		if(cost[v]<c) continue;

		for(auto to:rg[v]){
			++out_done[to];
			if(out_done[to]==out[to]){
				if(cost[to]>c){
					cost[to]=c;
					dq.push_front(mp(c,to));
				}
			}
			if(cost[to]>c+1){
				cost[to]=c+1;
				dq.push_back(mp(c+1,to));
			}
		}
	}

	int res=cost[s];
	if(res==INF) res=-1;
	cout<<res<<endl;
	return 0;
}