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

int n;
pair<pi,int> edge[200005];
int zip[200005],xn;

int deg[200005];
vector<pi> g[200005];
int res[200005];

pi getedge(int i){
	while(!g[i].empty()){
		pi e=g[i].back();
		if(res[e.sc]!=-1) g[i].pop_back();
		else return e;
	}
	return mp(-1,-1);
}
int main(){
	cin>>n;
	REP(i,n){
		int l,r;scanf("%d%d",&l,&r);
		l*=2;
		r=r*2+1;

		zip[i*2]=l;
		zip[i*2+1]=r;

		edge[i]=mp(mp(l,r),i);
	}
	sort(zip,zip+n*2);
	xn=unique(zip,zip+n*2)-zip;

	int nn=n;
	REP(i,n){
		edge[i].fr.fr=lower_bound(zip,zip+xn,edge[i].fr.fr)-zip;
		edge[i].fr.sc=lower_bound(zip,zip+xn,edge[i].fr.sc)-zip;

		++deg[edge[i].fr.fr];
		++deg[edge[i].fr.sc];
	}

	int last=-1;
	REP(i,xn) if(deg[i]&1){
		if(last==-1) last=i;
		else{
			edge[n]=mp(mp(last,i),n);
			++n;
			last=-1;
		}
	}

	REP(i,n){
		int a=edge[i].fr.fr,b=edge[i].fr.sc,id=edge[i].sc;
		g[a].pb(mp(b,id));
		g[b].pb(mp(a,id));
	}

	REP(i,xn){
		dump(i);
		debug(ALL(g[i]));
	}
	
	memset(res,-1,sizeof(res));
	dump(xn);
	REP(i,xn){
		while(getedge(i).fr!=-1){
			int cur=i;
			dump(i);
			do{
				dump(cur);
				pi e=getedge(cur);
				g[cur].pop_back();
				if(e.fr>cur) res[e.sc]=0;
				else res[e.sc]=1;
				cur=e.fr;
			}while(cur!=i);
		}
	}

	REP(i,nn) printf("%d%c",res[i],i==n-1?'\n':' ');






		

	return 0;
}