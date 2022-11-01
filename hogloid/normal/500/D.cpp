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

int n;
vector<pi> g[100005];//(dst,id)

int wei[100005];
double prob[100005];

double C3(double a){
	return a*(a-1)*(a-2);
}

double calc(double n,double r){
	double res=(1-(C3(r)+C3(n-r))/C3(n))*2;
	return res;
}

int dfs(int v,int p){
	int size=1;
	for(auto e:g[v]){
		if(e.fr==p) continue;
		int sub=dfs(e.fr,v);

		prob[e.sc]=calc(n,sub);
		size+=sub;
	}
	return size;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		wei[i]=c;

		g[a].pb(mp(b,i));
		g[b].pb(mp(a,i));
	}

	dfs(0,-1);

	double res=0;
	REP(i,n-1) res+=prob[i]*wei[i];

	int q;cin>>q;
	REP(hoge,q){
		int r,w;scanf("%d%d",&r,&w);--r;

		res-=prob[r]*wei[r];
		res+=prob[r]*w;

		wei[r]=w;
		printf("%.10f\n",res);

	}

	return 0;
}