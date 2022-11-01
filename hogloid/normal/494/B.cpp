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


bool mark[100005];

int table[100005];
void KMP(char* s,char* key){
	int len=strlen(s),klen=strlen(key);
	table[0]=0;
	REPN(i,klen+1,1){
		int j=table[i-1];
		while(j>0 && key[j]!=key[i]) j=table[j-1];
		if(key[j]==key[i]) ++j;
		table[i]=j;
	}

	int j=0,res=0;
	REP(i,len){
		while(j>0 && key[j]!=s[i]) j=table[j-1];
		if(key[j]==s[i]) ++j;
		if(j==klen){
      mark[i-klen+1]=1;
		}
	}
}

typedef Int_<1000000007> Int;

char s[100005],t[100005];
int n,m;

Int dp[100005][3];
int main(){
  scanf("%s%s",s,t);
  n=strlen(s);m=strlen(t);
  KMP(s,t);

  dp[0][0]=1;
  REP(i,n+1){
    if(dp[i][2]!=0){
      dp[i][0]+=dp[i][2];
      dp[i+1][2]+=dp[i][2];
    }

    if(dp[i][0]!=0){
      dp[i][1]+=dp[i][0];
      dp[i+1][0]+=dp[i][0];
    }
    if(dp[i][1]!=0){
      if(mark[i]) dp[i+m][2]+=dp[i][1];
      else dp[i+1][1]+=dp[i][1];
    }
  }

  Int res=dp[n][0];
  res-=1;
  cout<<res<<endl;

  return 0;
}