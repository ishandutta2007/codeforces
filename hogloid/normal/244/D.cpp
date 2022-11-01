#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
pi es[200005];
vector<int> g[100005];
int n,m,h,t;

int both[405],A[405],B[405];

int main(){
	cin>>n>>m>>h>>t;
	REP(i,m){
		int a,b;cin>>a>>b;
		--a;--b;
		es[i]=mp(a,b);
		es[i+m]=mp(b,a);
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,n) sort(ALL(g[i]));

	int suc=0;

	int head,tail;
	vector<int> H,T;
	REP(i,m*2){
		int a=es[i].fr,b=es[i].sc;
		// a:=head 	b:=tail
		
		int lima=min(((int)g[a].size()),205),limb=min(((int)g[b].size()),205);
		int s1=0,s2=0,s3=0;

		int j=0,k=0;
		while(j<lima || k<limb){
			if(j<lima && (k==limb || g[a][j]<g[b][k])){
				if(g[a][j]!=b) A[s1++]=g[a][j];
				++j;
			}else if(k<limb && (j==lima || g[a][j]>g[b][k])){
				if(g[b][k]!=a) B[s2++]=g[b][k];
				++k;
			}else{
				both[s3++]=g[a][j];
				++j;
				++k;
			}
		}
		int lackA=max(0,h-s1),lackB=max(0,t-s2);
		if(lackA+lackB>s3) continue;
		suc=1;
		
		REP(j,min(h,s1)) H.pb(A[j]);
		REP(j,min(t,s2)) T.pb(B[j]);

		REP(j,lackA) H.pb(both[j]);
		REP(j,lackB) T.pb(both[j+lackA]);

		head=a;
		tail=b;
		break;
	}
	if(suc){
		puts("YES");
		printf("%d %d\n",head+1,tail+1);
		REP(i,h) printf("%d%c",H[i]+1,i==h-1?'\n':' ');
		REP(i,t) printf("%d%c",T[i]+1,i==t-1?'\n':' ');
	}else puts("NO");

	return 0;
}