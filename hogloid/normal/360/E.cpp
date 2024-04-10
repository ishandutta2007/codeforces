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

const lint INF=1e18;

int n,m,k;
int s1,s2,goal;

vector<pair<pi,pi> > g[10005];
lint cost1[10005],cost2[10005];
void ijk(int s,lint* cost){
	REP(i,n) cost[i]=INF;

	cost[s]=0;
	typedef pair<lint,int> stat;
	priority_queue<stat,vector<stat>,greater<stat> >pq;
	pq.push(mp(0,s));
	while(!pq.empty()){
		stat cur=pq.top();pq.pop();
		for(auto e:g[cur.sc]){
			if(cost[e.fr.fr]>cur.fr+e.sc.fr){
				cost[e.fr.fr]=cur.fr+e.sc.fr;
				pq.push(mp(cost[e.fr.fr],e.fr.fr));
			}
		}
	}
}


int res[105];
int main(){
	cin>>n>>m>>k;
	cin>>s1>>s2>>goal;
	--s1;--s2;--goal;

	REP(i,m){
		int a,b,c;cin>>a>>b>>c;
		--a;--b;

		g[a].pb(mp(mp(b,-1),mp(c,c)));
	}
	REP(i,k){
		int a,b,l,r;cin>>a>>b>>l>>r;
		--a;--b;

		g[a].pb(mp(mp(b,i),mp(r,l)));
	}


	bool changed=true;
	while(changed){
		changed=false;
		prl;

		ijk(s1,cost1);
		ijk(s2,cost2);
		REP(i,n) if(cost1[i]<cost2[i]){
			for(auto& e:g[i]) if(e.sc.fr>e.sc.sc){
				swap(e.sc.fr,e.sc.sc);
				changed=true;
			}
		}
	}
	REP(i,n) for(auto e:g[i]) if(e.fr.sc>=0){
		res[e.fr.sc]=e.sc.fr;
	}

	if(cost1[goal]<cost2[goal]){
		puts("WIN");
		REP(i,k) printf("%d%c",res[i],i==k-1?'\n':' ');
	}else if(cost1[goal]==cost2[goal]){
		puts("DRAW");
		REP(i,k) printf("%d%c",res[i],i==k-1?'\n':' ');
	}else puts("LOSE");





	return 0;
}