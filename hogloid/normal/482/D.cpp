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


template<lint mod>
struct Int_{
	unsigned x;
	int mpow(Int_ a,int k){
		Int_ res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	int inverse(Int_ a){
		return mpow(a,mod-2);
	}
	Int_(): x(0) { }
	Int_(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
	int get() const { return (int)x; }
	
	Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int_ &operator=(Int_ that) { x=that.x; return *this;}
	Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	bool operator==(Int_ that) const { return x==that.x; }
	bool operator!=(Int_ that) const { return x!=that.x; }

	Int_ operator-() const { return Int_(0)-Int_(*this);}
	Int_ operator+(Int_ that) const { return Int_(*this) += that; }
	Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
	Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
	Int_ operator/(Int_ that) const { return Int_(*this) /= that; }

};

namespace std{
	template<lint mod>
	ostream &operator <<(ostream& out,const Int_<mod>& a){
		out<<a.get();
		return out;
	}
	template<lint mod>
	istream &operator >>(istream& in,Int_<mod>& a){
		in>>a.x;
		return in;
	}
};

typedef Int_<1000000007> Int;

int n;
Int dp[100005][2];

vector<int> g[100005];


void solve(int v,Int dp2[2][3][2]){
  REP(i,2) REP(j,3) REP(k,2) dp2[i][j][k]=0;
  
  for(auto to:g[v]){

    Int tmp[2][3][2]={0};
    REP(i,2) REP(j,3) REP(k,2) REP(i2,2) tmp[i^i2][j==i2?j:2][k^1]+=
      dp[to][i2]*dp2[i][j][k];

    REP(i,2) REP(j,3) REP(k,2) dp2[i][j][k]+=tmp[i][j][k];
    dp2[0][1][1]+=dp[to][1];
    dp2[1][0][1]+=dp[to][0];
  }
}

void rec(int v){

  for(auto to:g[v]) rec(to);

  Int dp2[2][3][2];//[even or odd][all subtree&1 (2: unequal)][taken child&1]

  solve(v,dp2);

  dp[v][0]+=dp2[0][2][0]+dp2[0][2][1]+dp2[0][1][0];
  dp[v][1]+=dp2[1][2][0]+dp2[1][2][1]+dp2[1][1][0];
  
  reverse(ALL(g[v]));
  solve(v,dp2);

  REP(i,2) REP(j,3) REP(k,2) dp[v][i]+=dp2[i][j][k];

  dp[v][1]+=1;
}
int main(){
  cin>>n;
  REP(i,n-1){
    int p;scanf("%d",&p);--p;
    g[p].pb(i+1);
  }

  rec(0);

  cout<<dp[0][0]+dp[0][1]<<endl;

  return 0;
}