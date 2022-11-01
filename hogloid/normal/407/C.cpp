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
const int mod=1000000007;


struct Int {
	unsigned x;
	int mpow(Int a,int k){
		Int res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	int inverse(Int a){
		return mpow(a,mod-2);
	}
	Int(): x(0) { }
	Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
	int get() const { return (int)x; }
	
	Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int &operator=(Int that) { x=that.x; return *this;}
	Int &operator/=(Int that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	bool operator==(Int that){ return x==that.x; }
	bool operator!=(Int that){ return x!=that.x; }


	Int operator+(Int that) const { return Int(*this) += that; }
	Int operator-(Int that) const { return Int(*this) -= that; }
	Int operator*(Int that) const { return Int(*this) *= that; }
	Int operator/(Int that) const { return Int(*this) /= that; }

};



namespace std{
	ostream &operator <<(ostream& out,const Int& a){
		out<<a.get();
		return out;
	}
	istream &operator >>(istream& in,Int& a){
		in>>a.x;
		return in;
	}
};

int n,m;
int ar[100005];

Int sum[105][100005];

Int C[110005][105];
int main(){

	REP(i,110005){
		C[i][0]=1;
		REP(j,min(i,101)) C[i][j+1]=C[i-1][j]+C[i-1][j+1];
	}

	cin>>n>>m;
	REP(i,n) scanf("%d",&ar[i]);
	REP(hoge,m){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);--l;
		
		int up=100-k;
		dump(up);
		sum[up][l]+=1;
		REP(i,k+1){
			if(i) sum[i+up][r]-=C[r-l+i][i]-C[r-l+i-1][i-1];
			else sum[i+up][r]-=C[r-l+i][i];
		}
	}
	REP(i,101) REP(j,n){
		sum[i+1][j]+=sum[i][j];
		sum[i][j+1]+=sum[i][j];
	}
	dump(sum[99][0]);
	debug(sum[100],sum[100]+5);

	REP(i,n){
		Int res=sum[100][i];
		res+=ar[i];
		printf("%d%c",res.get(),i==n-1?'\n':' ');
	}
	return 0;
}