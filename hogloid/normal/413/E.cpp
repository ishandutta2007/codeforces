#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;
char buf[3][2000005];
int n,m;
struct segtree{
	int n;
	int val[800005][2][2];
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) REP(j,2) REP(k,2) val[i][j][k]=INF;
		REP(i,n_) {
			REP(j,2) REP(k,2) if(buf[j][i]=='.' && buf[k][i]=='.'){
				val[i+n-1][j][k]=abs(j-k);
			}
		}
		for(int i=n-2;i>=0;--i){
			REP(j,2) REP(k,2) REP(l,2) chmin(val[i][j][l],
					val[i*2+1][j][k]+val[i*2+2][k][l]+1);
		}
	}
	int res[2][2],tmp[2][2];
	int a,b,L,R;
	void query(int i,int l,int r){
		if(a<=l && r<=b) {
			memcpy(tmp,res,sizeof(res));
			REP(i,2) REP(j,2) res[i][j]=INF;
			
			REP(j,2) REP(k,2) REP(l,2) chmin(res[j][l],tmp[j][k]+1+val[i][k][l]);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		query(i*2+1,l,md);
		query(i*2+2,md,r);
	}

	int query(int a1,int b1,int L1,int R1){
		a=a1;b=b1;L=L1;R=R1;
		res[0][0]=res[1][1]=0;
		res[0][1]=res[1][0]=INF;
		query(0,0,n);
		return res[L1][R1];
	}
};
segtree seg;

int main(){
	cin>>n>>m;
	REP(i,2) scanf("%s",buf[i]);
	seg.init(n);
	REP(hoge,m){
		int a,b;cin>>a>>b;--a;--b;
		if(a%n>b%n) swap(a,b);
		int res=seg.query(a%n,b%n+1,a/n,b/n);
		if(res==INF) res=-1;
		else --res;
		printf("%d\n",res);
	}


	return 0;
}