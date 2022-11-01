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

typedef Int_<1000000021> Int_h;

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
struct Hash{

	static const int MAX_N=300005;
	static Hash pows[MAX_N];
	static lint M1;
	static lint mul1[MAX_N];
	lint a;
	static void init(){
		M1=100000037;

		mul1[0]=1;
		REP(i,MAX_N-1){
			mul1[i+1]=mul1[i]*M1;
		}
		REP(i,MAX_N) pows[i].a=mul1[i];
	}
	Hash(lint val=0){
		a=val;
	}
	Hash &operator+=(const Hash& b) { 
		a+=b.a;

		return *this;
	}
	Hash &operator-=(const Hash& b) {
		a-=b.a;

		return *this;
	}
	Hash &operator <<=(int k){
		a*=mul1[k];
		return *this;
	}
	Hash &operator =(Hash b){
		a=b.a;
		return *this;
	}
	Hash operator -()const{
		return Hash(0)-=Hash(*this);
	}

	Hash operator +(const Hash& b) const{
		return Hash(*this)+=b;
	}
	Hash operator -(const Hash& b) const{
		return Hash(*this)-=b;
	}

	Hash operator <<(int k) const{
		return Hash(*this)<<=k;
	}

	bool operator==(const Hash& b) const { return (a==b.a); }
	bool operator!=(const Hash& b) const { return (a!=b.a); }
};

const int Hash::MAX_N;
lint Hash::M1;
lint Hash::mul1[MAX_N];

Hash Hash::pows[MAX_N];

struct BIT{
	static const int MAX_N=300000;
	Hash val[MAX_N*2+2];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=Hash(0);
	}
	void add(int k,const Hash& a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	Hash query(int k){	//[0,k)
		Hash res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};


BIT bit,rev;
int n;
int ar[300005];
int main(){

	Hash::init();
	
	cin>>n;
	dump(n);

	bit.init(n);
	rev.init(n);
	prl;
	REP(i,n) scanf("%d",&ar[i]),--ar[i];

	REP(i,n){
		dump(i);
		int len=min(ar[i],n-1-ar[i]);
		Hash big=bit.query(ar[i]+len+1)-bit.query(ar[i]),
			 	small=rev.query(n-1-ar[i]+len+1)-rev.query(n-1-ar[i]);

		int dif=ar[i]-(n-1-ar[i]);
		dump(dif);
		if(dif>0) small<<=dif;
		else big<<=-dif;
		if(big!=small){
			puts("YES");
			return 0;
		}

		dump(Hash::pows[ar[i]].a);

		bit.add(ar[i],Hash::pows[ar[i]]);
		rev.add(n-1-ar[i],Hash::pows[n-1-ar[i]]);
	}
	puts("NO");

	return 0;
}