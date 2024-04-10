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
static const int MAX_SIZE=4015;
vector<int> g[MAX_SIZE];
int vis[MAX_SIZE],match[MAX_SIZE];
int dfs(int v){
	vis[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i],w=match[to];
		if(w==-1 || (vis[w]==0 && dfs(w))){
			match[v]=to;
			match[to]=v;
			return 1;
		}
	}
	return 0;
}
int bipartite_matching(int n){
	memset(match,-1,sizeof(match));
	int res=0;
	REP(i,n) if(match[i]==-1){
		memset(vis,0,sizeof(vis));
		if(dfs(i)){
			++res;
		}
	}
	return res;
}

int n,m;
int rowok[1005],colok[1005];

pi es[12]={mp(1,6),mp(1,4),mp(1,8),mp(2,3),mp(2,7),mp(2,5),mp(3,8),mp(3,6),mp(4,5),mp(4,7),
			mp(5,8),mp(6,7)};

int main(){
	REP(i,12){
		--es[i].fr;
		--es[i].sc;
	}

	cin>>n>>m;
	REP(i,n) rowok[i]=colok[i]=1;

	REP(i,m){
		int x,y;scanf("%d%d",&x,&y);--x;--y;
		rowok[x]=0;
		colok[y]=0;
	}
	rowok[0]=colok[0]=rowok[n-1]=colok[n-1]=0;

	
	int res=0;
	REPN(i,n/2,1){
		int mxi=0;
		REP(bit,1<<8){
			if(!rowok[i] && (bit&1 || bit>>5&1)) continue;
			if(!rowok[n-1-i] && (bit>>1&1 || bit>>4&1)) continue;
			if(!colok[i] && (bit>>2&1 || bit>>7&1)) continue;
			if(!colok[n-1-i] && (bit>>3&1 || bit>>6&1)) continue;

			int fail=0;
			REP(j,12){
				if(bit>>es[j].fr&1 && bit>>es[j].sc&1) fail=1;
			}
			if(!fail){
				chmax(mxi,__builtin_popcount(bit));
			}
		}
		res+=mxi;
	}

	if(n&1){
		if(rowok[n/2] || colok[n/2]) ++res;
	}
	cout<<res<<endl;

	return 0;
}