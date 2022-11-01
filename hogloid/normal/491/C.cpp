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
static const int MAX_V=155;		

struct edge{
	int to,cap,cost,rev;
	edge(int st,int sc,int sco,int sr){
		to=st;cap=sc;cost=sco;rev=sr;
	}
};
vector<edge> g[MAX_V];
int pot[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
	g[from].pb(edge(to,cap,cost,g[to].size()));
	g[to].pb(edge(from,0,-cost,g[from].size()-1));
}

int min_cost_flow(int s,int t,int f,int V){
	int res=0;
	fill(pot,pot+V,0);
	while(f>0){
		priority_queue<pi,vector<pi>,greater<pi> >pq;pq.push(mp(0,s));
		fill(dist,dist+V,INF);
		dist[s]=0;
		while(!pq.empty()){
			pi cur=pq.top();pq.pop();
			if(dist[cur.sc]<cur.fr) continue;
			REP(i,g[cur.sc].size()){
				edge& e=g[cur.sc][i];
				if(e.cap>0 && dist[e.to]>cur.fr+e.cost+pot[cur.sc]-pot[e.to]){
					dist[e.to]=cur.fr+e.cost+pot[cur.sc]-pot[e.to];
					prevv[e.to]=cur.sc;
					preve[e.to]=i;
					pq.push(mp(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF){
			return -1;
		}
		for(int v=0;v<V;++v) pot[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,g[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*pot[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge& e=g[prevv[v]][preve[v]];
			e.cap-=d;
			g[v][e.rev].cap+=d;
		}
	}
	return res;
}


int n,k;
char s[2000005],s2[2000005];
int conv[300];
const int M=2000005;
int cnt[55][55];

char rev[55];
int main(){
	cin>>n>>k;
	scanf("%s%s",s,s2);

	int S=k*2,T=S+1;
	REP(i,26){
		conv['a'+i]=i;
		rev[i]='a'+i;
	}
	REP(i,26){
		conv['A'+i]=26+i;
		rev[26+i]='A'+i;
	}

	REP(i,n){
		cnt[conv[s[i]]][conv[s2[i]]]++;
	}

	REP(i,k) add_edge(S,i,1,0);
	REP(i,k) add_edge(i+k,T,1,0);

	REP(i,k) REP(j,k) add_edge(i,j+k,1,M-cnt[i][j]);

	int cost=min_cost_flow(S,T,k,T+1);
	
	string res(k,'a');
	REP(i,k){
		for(auto e:g[i]){
			if(e.to>=k && e.to<2*k && e.cap==0){
				res[i]=rev[e.to-k];
			}
		}
	}


	cost-=M*k;
	cost*=-1;

	cout<<cost<<endl;
	cout<<res<<endl;

	return 0;
}