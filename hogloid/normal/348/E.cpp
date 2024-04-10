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

//const int INF=5e8;

vector<pi> g[100005];
pi chi_far[100005];
pair<int,pi> par_far[100005];
int mark[100005];
int n,m;

void rec(int v,int p,int dep){
	chi_far[v]=mp(-1,-1);
	if(mark[v]) chi_far[v]=mp(0,v);
	for(auto e:g[v]){
		if(e.fr==p) continue;
		rec(e.fr,v,dep+e.sc);
		if(chi_far[e.fr].fr==-1) continue;

		if(chi_far[v].fr==chi_far[e.fr].fr+e.sc){
			chi_far[v].sc=v;
		}else if(chi_far[v].fr<chi_far[e.fr].fr+e.sc){
			chi_far[v]=chi_far[e.fr];
			chi_far[v].fr+=e.sc;
		}
	}
}

int sum[100005],decr[100005];
void rec2(int v,int p){
	vector<pi> way;
	for(auto e:g[v]){
		if(e.fr==p) continue;
		if(chi_far[e.fr].fr!=-1){
			way.pb(mp(chi_far[e.fr].fr+e.sc,e.fr));
		}
	}
	if(p!=-1 && par_far[v].fr!=-1) way.pb(mp(par_far[v].fr,-1));

	if(mark[v]) way.pb(mp(0,v));
	sort(ALL(way),greater<pi>());

	way.pb(mp(-1,-1));
	way.pb(mp(-1,-1));

	if(mark[v]){
		dump(v);
		if(way[0].fr==way[1].fr){
			;
		}else{
			if(way[0].sc==-1){
				dump(v);dump(par_far[v].sc.fr);dump(par_far[v].sc.sc);
				++sum[v];
				++sum[par_far[v].sc.fr];
				sum[par_far[v].sc.sc]--;
				--decr[par_far[v].sc.sc];
			}else{
				dump(chi_far[way[0].sc].sc);
				dump(v);
				++sum[chi_far[way[0].sc].sc];
				--sum[v];
			}
		}
	}


	for(auto e:g[v]){
		if(e.fr==p) continue;
		
		pi a,b;

		if(way[0].sc==e.fr){
			a=way[1],b=way[2];
		}else{
			a=way[0];
			if(way[1].sc==e.fr) b=way[2];
			else b=way[1];
		}

		if(a.fr==-1){
			par_far[e.fr]=mp(-1,mp(-1,-1));
		}else if(a.fr==b.fr){
			par_far[e.fr]=mp(a.fr+e.sc,mp(v,v));
		}else{
			if(a.sc==-1) par_far[e.fr]=mp(a.fr+e.sc,par_far[v].sc);
			else if(a.sc==v) par_far[e.fr]=mp(a.fr+e.sc,mp(v,v));
			else par_far[e.fr]=mp(a.fr+e.sc,mp(chi_far[a.sc].sc,v));
		}
		rec2(e.fr,v);
	}
}

pi ans=mp(-1,-1);
int rec3(int v,int p){
	int chil=sum[v];
	for(auto e:g[v]){
		if(e.fr==p) continue;
		chil+=rec3(e.fr,v);
	}
	if(!mark[v]){
		if(ans.fr<chil) ans=mp(chil,1);
		else if(ans.fr==chil) ++ans.sc;
	}

	return chil+decr[v];
}



int main(){
	cin>>n>>m;
	REP(i,m){
		int a;scanf("%d",&a);--a;
		mark[a]=1;
	}

	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}

	rec(0,-1,0);
	prl;
	rec2(0,-1);
	prl;
	debug(sum,sum+n);
	rec3(0,-1);
	prl;

	cout<<ans.fr<<' '<<ans.sc<<endl;

	return 0;
}