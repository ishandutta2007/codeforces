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
//const int INF=5e8;

static const int B=600;
pair<pi,int> es[400005];
int n,m,q;

int on[50005];
pair<int,pi> query[250005];

int mark[50005];
int mat[B*2][B*2];
int conv[50005];
int cnt;
int res[50005],rev[B*2];
void build(int l,int r){
	CLR(mark);
	REPN(i,r,l){
		if(query[i].fr<=1) mark[query[i].sc.fr]=1;
		else mark[query[i].sc.fr]=mark[query[i].sc.sc]=1;
	}
	cnt=0;
	memset(conv,-1,sizeof(conv));
	REP(i,n) if(mark[i]==1){
		conv[i]=cnt;
		rev[conv[i]]=i;
		++cnt;
	}
	
	CLR(mat);
	CLR(res);
	REP(i,m){
		int a=conv[es[i].fr.fr],b=conv[es[i].fr.sc],val=es[i].sc;
		if(a>=0 && b>=0) mat[a][b]+=val,mat[b][a]+=val;
		if(a>=0 && on[es[i].fr.sc]) res[a]+=val;
		if(b>=0 && on[es[i].fr.fr]) res[b]+=val;
	}
}

int main(){
	cin>>n>>m>>q;
	int o;scanf("%d",&o);
	REP(i,o){
		int a;scanf("%d",&a);
		--a;
		on[a]=1;
	}
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		es[i]=mp(mp(a,b),1);
	}

	REP(i,q){
		char tmp[10];scanf("%s",tmp);
		int u,v;
		if(tmp[0]=='O'){
			scanf("%d",&u);--u;
			query[i]=mp(0,mp(u,0));
		}else if(tmp[0]=='F'){
			scanf("%d",&u);--u;
			query[i]=mp(1,mp(u,0));
		}else if(tmp[0]=='A'){
			scanf("%d%d",&u,&v);--u;--v;
			query[i]=mp(2,mp(u,v));
		}else if(tmp[0]=='D'){
			scanf("%d%d",&u,&v);--u;--v;
			query[i]=mp(3,mp(u,v));
		}else if(tmp[0]=='C'){
			scanf("%d",&u);--u;
			query[i]=mp(-1,mp(u,0));
		}
	}

	REP(i,q){
		if(i%B==0) build(i,min(i+B,q));
		
		int t=query[i].fr,u=query[i].sc.fr,v=query[i].sc.sc;
		int U=conv[u],V=conv[v];
		if(t==-1){
			printf("%d\n",res[U]);
		}else if(t==0){
			on[u]=1;
			REP(j,cnt) if(mat[j][U]) ++res[j];
		}else if(t==1){
			on[u]=0;
			REP(j,cnt) if(mat[j][U]) --res[j];
		}else if(t==2){
			mat[U][V]=mat[V][U]=1;
			es[m++]=mp(mp(u,v),1);
			if(on[u]) ++res[V];
			if(on[v]) ++res[U];
		}else if(t==3){
			mat[U][V]=mat[V][U]=0;
			es[m++]=mp(mp(u,v),-1);
			if(on[u]) --res[V];
			if(on[v]) --res[U];
		}
	}


	return 0;
}