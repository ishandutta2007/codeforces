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
typedef long long lint;
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
	Int_ &operator- () { x=mod-x; if(x==mod) x=0; return *this;}
	bool operator==(Int_ that) const { return x==that.x; }
	bool operator!=(Int_ that) const { return x!=that.x; }


	Int_ operator+(Int_ that) const { return Int_(*this) += that; }
	Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
	Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
	Int_ operator/(Int_ that) const { return Int_(*this) /= that; }

};

typedef Int_<1000000009> Int;
typedef pair<Int ,Int > pi;

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



Int fib1[600005];
pi fib2[600005];
pi fibsum[600005];
struct segtree{
	Int val[1200005];

	Int a1[1200005],a2[1200005];
	int n;
	void init(int n_,int* ar){
		n=1;
		while(n<n_) n<<=1;
		
		REP(i,n_) val[i+n-1]=ar[i];
		for(int i=n-2;i>=0;--i){
			val[i]=val[i*2+1]+val[i*2+2];
		}
	}
	void add2(Int &val,int len,Int a,Int b){
		val=(val+fibsum[len].fr*a+fibsum[len].sc*b);
	}
	void push(int i,int len){

		if(a1[i]==0 || a2[i]==0) return;
		int len2=len/2;
		a1[i*2+1]=(a1[i*2+1]+a1[i]);
		a2[i*2+1]=(a2[i*2+1]+a2[i]);
		add2(val[i*2+1],len2,a1[i],a2[i]);
		

		Int a=a1[i]*fib2[len2].fr+a2[i]*fib2[len2].sc,
			b=a1[i]*fib2[len2+1].fr+a2[i]*fib2[len2+1].sc;

		a1[i*2+2]=(a1[i*2+2]+a);
		a2[i*2+2]=(a2[i*2+2]+b);
		add2(val[i*2+2],len2,a,b);


		a1[i]=a2[i]=0;
	}


	void add(int a,int i,int l,int r,int k,int sign){
		if(a<=l){
			int pos=k+l-a;
			Int v=(fib1[pos]*sign);
			a1[i]=(a1[i]+v);

			pos=k+l-a+1;
			Int v2=(fib1[pos]*sign);
			a2[i]=(a2[i]+v2);
			
			add2(val[i],r-l,v,v2);
			
			dump(l);dump(r);
			dump(fibsum[r-l].fr);dump(fibsum[r-l].sc);
			dump(val[i]);
			return;
		}
		if(r<=a) return;

		int md=(l+r)>>1;
		push(i,r-l);
		add(a,i*2+1,l,md,k,sign);
		add(a,i*2+2,md,r,k,sign);
		val[i]=(val[i*2+1]+val[i*2+2]);
	}
	Int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return Int(0);

		int md=(l+r)>>1;
		push(i,r-l);
		return (query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r));
	}
};


segtree  seg;



int n,m;

int ar[300005];

int main(){
	cin>>n>>m;
	
	fib1[0]=fib1[1]=1;
	fib2[0]=mp(1,0);fib2[1]=mp(0,1);
	REPN(i,n*2+1,2){
		fib1[i]=(fib1[i-1]+fib1[i-2]);
		fib2[i]=mp((fib2[i-1].fr+fib2[i-2].fr),(fib2[i-1].sc+fib2[i-2].sc));
	}
	REP(i,n*2+1){
		fibsum[i+1]=fibsum[i];
		fibsum[i+1].fr=(fibsum[i+1].fr+fib2[i].fr);
		fibsum[i+1].sc=(fibsum[i+1].sc+fib2[i].sc);
	}


	REP(i,n){
		int a;scanf("%d",&a);
		ar[i]=a;
	}
	
	seg.init(n,ar);
	REP(i,m){
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		--l;
		if(t==1){
			seg.add(l,0,0,seg.n,0,1);
			seg.add(r,0,0,seg.n,r-l,-1);
		}else{
			Int ans=seg.query(l,r,0,0,seg.n);
			printf("%d\n",ans.get());
		}
	}



	return 0;
}