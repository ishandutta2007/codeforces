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
	unsigned mpow(Int_ a,unsigned k){
		Int_ res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	unsigned inverse(Int_ a){
		return mpow(a,mod-2);
	}
	Int_(): x(0) { }
	Int_(long long sig) {
    if(sig<0) x=sig%mod+mod;
    else x=sig%mod;
  }
	unsigned get() const { return (unsigned)x; }
	
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

typedef Int item ;
typedef vector<item> vec;
typedef vector<vector<item> > mat;
mat matpow(const mat& a,const mat& b){
	int n=a.size();
	mat res(n,vec(n));
	REP(i,n) REP(j,n) REP(k,n){
		res[i][j]+=a[i][k]*b[k][j];
	}
	return res;
}
mat mpow(mat a,lint k){
	int n=a.size();
	mat res(n,vec(n));
	REP(i,n) res[i][i]=1;
	while(k){
		if(k&1) res=matpow(res,a);
		a=matpow(a,a);
		k>>=1;
	}
	return res;
}

int w[10];
int main(){
  REP(i,7) cin>>w[i+1];

  vec ever(2);
  ever[1]=1;
  for(int i=1;i<=7;++i){
    int n=(1<<i);
    mat M(n,vec(n));

    REP(j,n) REP(k,n) REP(l,n/2){
      int l2=(l<<1)|1|(1<<i);
      int fail=0;
      REP(i2,i) if(j>>i2&1 && k>>i2&1 && l2>>i2&1 && l2>>(i2+1)&1){
        fail=1;break;
      }
      if(!fail) M[j][k]+=1;
    }

    mat M2=mpow(M,w[i]);

    vec nxt(n);
    REP(i,n) REP(j,n){
      nxt[j]+=ever[i]*M2[i][j];
    }
    ever.clear();
    if(i==7) ever=nxt;
    else{
      ever.resize(2*n);
      REP(j,n) ever[j|n]=nxt[j];
    }
  }

  Int res=ever[(1<<7)-1];
  cout<<res<<endl;
  return 0;
}