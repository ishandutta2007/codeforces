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
//const int INF=5e8;

int n,k;
char s[2005];

Int dp[2005][2005];


Int sum[2005];
int main(){
	cin>>n>>k;
	cin>>s;

	dp[n][0]=1;
	for(int i=n-1;i>=0;--i){
		dp[i][0]+=1;
		REP(j,k+1){
dump(i);dump(j);
			dp[i][j]+=dp[i+1][j]*(s[i]-'a');
			int j2;
			for(j2=i;j2<n && (j2-i+1)*(n-j2)<=j;++j2){
				dp[i][j]+=dp[j2+1][j-(j2-i+1)*(n-j2)]*('z'-s[j2]);
			}
			int j3;
			for(j3=n-1;j3>=j2 && (j3-i+1)*(n-j3)<=j;--j3){
				dp[i][j]+=dp[j3+1][j-(j3-i+1)*(n-j3)]*('z'-s[j3]);
			}

			dp[i][j]+=sum[j];

			sum[j]+=dp[i+1][j]*(s[i]-'a');
		}
	}

	cout<<dp[0][k]<<endl;

	return 0;
}