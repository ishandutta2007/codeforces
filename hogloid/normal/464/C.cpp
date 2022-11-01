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
const int mod=1000000007;
typedef Int_<1000000007> Int;
char s[100005];
int n,m;


char tmp[100105];

int d[100005];
string t[100005];

pi event[200005];


int main(){
	scanf("%s",s);
	m=strlen(s);

	cin>>n;
	REP(i,n){
		scanf("%s",tmp);
		d[i]=tmp[0]-'0';
		t[i]=&tmp[3];
	}

	Int trans[10];
	int len[10];
	REP(i,10){
		trans[i]=i;
		len[i]=1;
	}

	for(int i=n-1;i>=0;--i){
		Int conv=0;
		int len2=0;
		REP(j,t[i].size()){
			len2+=len[t[i][j]-'0'];
			len2%=(mod-1);
			conv=conv*conv.mpow(10,len[t[i][j]-'0'])+trans[t[i][j]-'0'];
		}
		len[d[i]]=len2;
		trans[d[i]]=conv;
	}
	
	Int res=0;
	REP(i,m){
		res=res*res.mpow(10,len[s[i]-'0'])+trans[s[i]-'0'];
	}
	cout<<res<<endl;





	return 0;
}