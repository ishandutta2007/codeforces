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

using namespace std;


#ifdef DEB
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

int n;
int ar[1000005];
const int mod=1000000007,mod2=mod-1;
int cnt[1100000][21];//cnt[i][j] ...j) change-able
struct Int {
	unsigned x;
	Int(): x(0) { }
	Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
	int get() const { return (int)x; }
	
	Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int &operator=(Int that) { x=that.x; return *this;}
	bool operator==(Int that){ return x==that.x; }
	bool operator>(Int that) { return x>that.x;}
	bool operator<(Int that) { return x<that.x;}


	Int operator+(Int that) const { return Int(*this) += that; }
	Int operator-(Int that) const { return Int(*this) -= that; }
	Int operator*(Int that) const { return Int(*this) *= that; }

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
lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

int main(){
	cin>>n;
	REP(i,n){
		scanf("%d",&ar[i]);

		++cnt[ar[i]][20];
	}
	prl;
	for(int i=(1<<20)-1;i>=0;--i) for(int k=20;k>=0;--k) if(cnt[i][k]){
		for(int j=k-1;j>=0;--j) if(i>>j&1){
			int tmp=(i^(1<<j));
			cnt[tmp][j]+=cnt[i][k];
			if(cnt[tmp][j]>=mod2) cnt[tmp][j]-=mod2;
		}
	}

	prl;
	
	REP(i,(1<<20)) REP(j,20){
		cnt[i][0]+=cnt[i][j+1];
		if(cnt[i][0]>=mod2) cnt[i][0]-=mod2;
	}

	REP(i,10) dump(cnt[i][0]);
	
	Int res=0;
	REP(i,1<<20) if(cnt[i][0]){
		int pcnt=__builtin_popcount(i);

		res+=(mpow(2,cnt[i][0])-1)*mpow(-1,pcnt)%mod;
		dump(i);
		dump(res);
	}


	cout<<res<<endl;



	return 0;
}