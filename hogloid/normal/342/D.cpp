#define DEB

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
int w,h;
char buf[3][10005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

Int dp[10005][1<<3];
Int solve(){
	CLR(dp);

	dp[0][0]=1;

	REP(i,w) REP(j,1<<3) if(dp[i][j]!=0){
		int fail=0;
		int bits=j;
		Int val=dp[i][j];
		REP(k,3) if(buf[k][i]=='X'){
			if(j>>k&1) fail=1;
			else bits|=(1<<k);
		}
		if(fail) continue;
		
		int ex[3]={bits&1,bits>>1&1,bits>>2&1};

		if(!ex[0] && !ex[1]){
			if(ex[2]) dp[i+1][0]+=val;
			else dp[i+1][1<<2]+=val;
		}
		if(!ex[1] && !ex[2]){
			if(ex[0]) dp[i+1][0]+=val;
			else dp[i+1][1]+=val;
		}
		int flip=(bits^7);
		dp[i+1][flip]+=val;
	}

	Int res=dp[w][0];
	dump(res);
	return res;
}

int main(){
	h=3;
	cin>>w;
	REP(i,h) scanf("%s",buf[i]);
	
	int sx,sy;
	REP(i,h) REP(j,w) if(buf[i][j]=='O'){
		sx=j;sy=i;
	}

	Int res=0;
	dump(sx);dump(sy);
	int flag=0;
	REP(d,4){
		int fail=0;
		REPN(l,3,1){
			int px=sx+dx[d]*l,py=sy+dy[d]*l;
			if(px<0 || py<0 || px>=w || py>=h || buf[py][px]=='X'){
				fail=1;break;
			}
		}
		if(!fail){
			flag|=(1<<d);
		}
	}
	REPN(bit,(1<<4),1){
		if((flag&bit)==bit){
			int cnt=__builtin_popcount(bit);
			buf[sy][sx]='X';
			REP(d,4) if(bit>>d&1){
				REPN(l,3,1){
					int px=sx+dx[d]*l,py=sy+dy[d]*l;
					buf[py][px]='X';
				}
			}
			
			res+=solve()*(cnt&1?1:-1);
			
			REP(d,4) if(bit>>d&1){
				REPN(l,3,1){
					int px=sx+dx[d]*l,py=sy+dy[d]*l;
					buf[py][px]='.';
				}
			}
		}
	}

	cout<<res<<endl;









	return 0;
}