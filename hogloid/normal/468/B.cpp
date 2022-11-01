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

int n,a,b;
pi ar[100005];

vector<pi> g[100005];
int col[100005];

void dfs(int v,int p=-1){
	if(col[v]==-1){
		for(auto e:g[v]){
			if(col[e.fr]==-1 && p!=e.fr){
				col[e.fr]=col[v]=e.sc;
				break;
			}
		}
		for(auto e:g[v]) if(p!=e.fr){
			dfs(e.fr,v);
		}
	}else{
		for(auto e:g[v]) if(p!=e.fr && col[e.fr]==-1){
			dfs(e.fr,v);
		}
	}
}

bool solve(){
	sort(ar,ar+n);

	REP(i,n) g[i].clear();

	REP(i,n){
		int t1=a-ar[i].fr;
		{
			int p1=lower_bound(ar,ar+n,mp(t1,-1))-ar;
			if(p1<n && ar[p1].fr==t1 && ar[i].fr!=ar[p1].fr){
				g[ar[i].sc].pb(mp(ar[p1].sc,0));
			}
		}
		t1=b-ar[i].fr;
		{
			int p1=lower_bound(ar,ar+n,mp(t1,-1))-ar;
			if(p1<n && ar[p1].fr==t1 && ar[i].fr!=ar[p1].fr){
				g[ar[i].sc].pb(mp(ar[p1].sc,1));
			}
		}
	}
	REP(i,n) if(g[i].size()==1 && col[i]==-1){
		dfs(i);
	}

	REP(i,n) if(col[i]==-1) return false;
	return true;
}



int main(){
	cin>>n>>a>>b;
	REP(i,n){
		cin>>ar[i].fr;
		ar[i].sc=i;
	}
	sort(ar,ar+n);
	if(a==b){
		int fail=0;
		REP(i,n){
			int p=lower_bound(ar,ar+n,mp(a-ar[i].fr,-1))-ar;
			if(p<n && ar[p].fr==a-ar[i].fr) ;
			else fail=1;
		}
		if(!fail){
			puts("YES");
			REP(i,n) printf("%d%c",0,i==n-1?'\n':' ');
		}else puts("NO");
		return 0;
	}


	int p[2]={-1,-1};
	REP(i,n){
		if(ar[i].fr*2==a) p[0]=ar[i].sc;
		if(ar[i].fr*2==b) p[1]=ar[i].sc;
	}

	REP(bit,4){
		memset(col,-1,sizeof(col));
		REP(i,2) if(bit>>i&1 && p[i]!=-1){
			col[p[i]]=i;
		}
		if(solve()){
			puts("YES");
			REP(i,n) printf("%d%c",col[i],i==n-1?'\n':' ');
			return 0;
		}
	}
	puts("NO");




	return 0;
}