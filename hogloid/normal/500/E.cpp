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
pi ar[200005];

int nxt[20][200005];
int cost[20][200005];
int main(){
	cin>>n;
	REP(i,n) scanf("%d%d",&ar[i].fr,&ar[i].sc);
	
	vector<int> stk;
	REP(i,n){
		while(!stk.empty()){
			int v=stk.back();
			if(ar[v].fr+ar[v].sc<=ar[i].fr+ar[i].sc){
				nxt[0][v]=i;
				cost[0][v]=max(0,ar[i].fr-ar[v].fr-ar[v].sc);
				stk.pop_back();
			}else break;
		}
		stk.pb(i);
	}
	while(!stk.empty()) nxt[0][stk.back()]=-1,stk.pop_back();
	REP(i,19) REP(j,n){
		if(nxt[i][j]==-1) nxt[i+1][j]=-1,cost[i+1][j]=cost[i][j];
		else nxt[i+1][j]=nxt[i][nxt[i][j]],cost[i+1][j]=cost[i][j]+cost[i][nxt[i][j]];
	}
	int q;cin>>q;
	REP(hoge,q){
		int x,y;scanf("%d%d",&x,&y);--x;--y;
		if(ar[x].fr+ar[x].sc>=ar[y].fr){
			puts("0");
			continue;
		}

		int res=0;
		for(int i=19;i>=0;--i){
			int v=nxt[i][x];
			if(v!=-1 && ar[v].fr+ar[v].sc<ar[y].fr){
				res+=cost[i][x];
				x=v;
			}
		}
		res+=cost[0][x];
		printf("%d\n",res);
	}

	return 0;
}