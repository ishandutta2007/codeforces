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
	bool operator>(Int that) { return x>that.x;}
	bool operator<(Int that) { return x<that.x;}


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

static const int MX=1000002,MX2=MX+5;
Int sum1[MX2],sumL[MX2],sumLL[MX2];

int phi[MX2];
Int gcdsum[MX2];
int main(){
	REP(i,MX) phi[i]=i;
	
	for(int i=2;i<=MX;++i) if(phi[i]==i){
		for(int j=i;j<=MX;j+=i) phi[j]-=phi[j]/i;
	}
	
	debug(phi,phi+5);
	for(int i=1;i<=MX;++i){
		for(int j=i;j<=MX;j+=i) gcdsum[j]+=Int(phi[j/i])*i;
	}



	sum1[0]=sumL[0]=sumLL[0]=0;
	
	debug(gcdsum,gcdsum+5);
	for(int i=1;i<=MX;++i){
		Int cur=Int(i)*(i+1)*(2*i+1)/3-Int(i)*i*3+gcdsum[i]*2;
		sum1[i]=sum1[i-1]+cur;
		sumL[i]=sumL[i-1]+cur*i;
		sumLL[i]=sumLL[i-1]+cur*i*i;
	}
	int t;
	scanf("%d",&t);
	dump(sum1[1]);
	REP(hoge,t){
		int n,m;scanf("%d%d",&n,&m);

		if(n>m) swap(n,m);
		
		dump(sum1[n]);dump(sumL[n]);dump(sumLL[n]);
		Int res=sum1[n]*Int(n+1)*Int(m+1)-sumL[n]*(n+1+m+1)+sumLL[n];

		cout<<res<<endl;
	}
	return 0;
}