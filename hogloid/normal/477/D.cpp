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

const int INF=5e8;
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

Int pat[5005][5005];
int minope[5005][5005];

char x[5005];
int n;

int firstdif[5005][5005];
int main(){
	scanf("%s",x);
	n=strlen(x);

	for(int i=n-1;i>=0;--i) for(int j=n-1;j>=0;--j){
		if(x[i]!=x[j]) firstdif[i][j]=0;
		else{
			if(i+1<n && j+1<n) firstdif[i][j]=min(INF,firstdif[i+1][j+1]+1);
			else firstdif[i][j]=INF;
		}
	}

	
	REP(i,n+1) REP(j,n+1) minope[i][j]=INF;

	
	pat[0][1]=1;
	minope[0][1]=1;

	REP(i,n) REPN(j,n+1,i+1) if(minope[i][j]<INF){

		if(x[i]=='0') continue;
		if(j==n) continue;
		
		chmin(minope[i][j+1],minope[i][j]);
		pat[i][j+1]+=pat[i][j];


		int len=j-i;

		bool flag=false;
		if(firstdif[i][j]<len){
			char c1=x[i+firstdif[i][j]],c2=x[j+firstdif[i][j]];
			if(c1<c2) {
				flag=true;
			}
		}else flag=true;
		if(flag){
			if(j+len<=n){
				chmin(minope[j][j+len],minope[i][j]+1);
				pat[j][j+len]+=pat[i][j];
			}
		}else {
			if(j+len+1<=n){
				chmin(minope[j][j+len+1],minope[i][j]+1);
				pat[j][j+len+1]+=pat[i][j];
			}
		}
	}

	Int pat_num=0;
	REP(i,n) if(x[i]!='0'){
		pat_num+=pat[i][n];
	}

	cout<<pat_num<<endl;
	
	bool done=false;
	Int res;
	lint size=1e18;

	for(int i=n-1;i>=0;--i) if(x[i]!='0' && minope[i][n]<INF){
		Int tmp=0;
		lint tmp2=0;
		REPN(j,n,i){
			tmp=tmp*2+(x[j]-'0');
			tmp2=tmp2*2+(x[j]-'0');
		}
		tmp+=minope[i][n];
		tmp2+=minope[i][n];
		
		if(n-i>=30){
			if(done) break;
			res=tmp;
			break;
		}else{
			if(size>tmp2){
				size=tmp2;
				res=tmp;
				done=true;
			}
		}
	}
	cout<<res<<endl;

	return 0;
}