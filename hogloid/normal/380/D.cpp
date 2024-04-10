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
	Int &operator- () { x=mod-x; if(x==mod) x=0; return *this;}
	bool operator==(Int that){ return x==that.x; }
	bool operator!=(Int that){ return x!=that.x; }


	Int operator+(Int that) const { return Int(*this) += that; }
	Int operator-(Int that) const { return Int(*this) -= that; }
	Int operator*(Int that) const { return Int(*this) *= that; }
	Int operator/(Int that) const { return Int(*this) /= that; }

};

Int mpow(Int a,int k){
	Int res=1;
	while(k){
		if(k&1) res=res*a;
		a=a*a;
		k>>=1;
	}
	return res;
}

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
int n;
vector<pi> decc;

Int inv[100005];
Int C(int a,int b){
	if(b<0 || b>a) return 0;
	Int res=1;
	REP(i,b){
		res*=a-i;
		res*=inv[i+1];
	}
	return res;
}

Int solve(int l,int r){//[l...r]
	Int res=1;
	for(int i=1;i<decc.size();++i){
		int pos=decc[i].sc,place=decc[i].fr-decc[i-1].fr-1;
		if(l<=pos && pos<=r) return 0;
		
		if(r<pos){
			res*=C(place,pos-r-1);
			l-=place-(pos-r-1);
			r=pos;
		}else{
			res*=C(place,l-pos-1);
			r+=place-(l-pos-1);
			l=pos;
		}
	}
	if(l<-1 || r>n) return 0;
	dump(res);
	return res;
}


int main(){
	for(int i=1;i<=100004;++i) inv[i]=Int(1)/i;

	cin>>n;
	REP(i,n){
		int a;scanf("%d",&a);
		if(a>0) decc.pb(mp(a-1,i));
	}
	decc.pb(mp(n,-1));
	decc.pb(mp(n+1,n));
	sort(ALL(decc));
	
	Int res=0;
	if(decc[0].fr>0){
		res+=solve(decc[0].sc-decc[0].fr,decc[0].sc)*mpow(2,decc[0].fr-1);
		res+=solve(decc[0].sc,decc[0].sc+decc[0].fr)*mpow(2,decc[0].fr-1);
	}else{
		res+=solve(decc[0].sc,decc[0].sc);
	}
	cout<<res<<endl;
	
	return 0;
}