#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int M=998244353;
struct modnum{
	int v;
	static int minv(int a,int m){return (a%=m)==1?1:m-ll(minv(m,a))*m/a;}
	modnum():v(0){}
	modnum(ll v_):v(int(v_%M)){if(v<0)v+=M;}
	explicit operator int()const{return v;}
	explicit operator bool()const{return v;}
	friend ostream&operator<<(ostream&out,const modnum&a){return out<<int(a);}
	friend istream&operator>>(istream&in,modnum&a){ll v;in>>v;a=modnum(v);return in;}
	friend bool operator==(const modnum&a,const modnum&b){return a.v==b.v;}
	friend bool operator!=(const modnum&a,const modnum&b){return a.v!=b.v;}
	modnum inv()const{return modnum(minv(v,M));}
	friend modnum inv(const modnum&a){return a.inv();}
	modnum neg()const{return modnum(v?M-v:0);}
	friend modnum neg(const modnum&a){return a.neg();}
	modnum operator-()const{return neg();}
	modnum operator+()const{return *this;}
	modnum&operator++(){if(++v==M)v=0;return*this;}
	modnum&operator--(){if(!v--)v=M-1;return*this;}
	modnum&operator+=(const modnum&a){if((v+=a.v)>=M)v-=M;return*this;}
	modnum&operator-=(const modnum&a){if((v-=a.v)<0)v+=M;return*this;}
	modnum&operator*=(const modnum&a){v=ll(v)*a.v%M;return*this;}
	modnum&operator/=(const modnum&a){return*this*=a.inv();}
	friend modnum operator++(modnum&a,int){modnum r=a;++a;return r;}
	friend modnum operator--(modnum&a,int){modnum r=a;--a;return r;}
	friend modnum operator+(const modnum&a,const modnum&b){return modnum(a)+=b;}
	friend modnum operator-(const modnum&a,const modnum&b){return modnum(a)-=b;}
	friend modnum operator*(const modnum&a,const modnum&b){return modnum(a)*=b;}
	friend modnum operator/(const modnum&a,const modnum&b){return modnum(a)/=b;}
};

typedef modnum mint;

void ProGamerMove(){
	int n;cin>>n>>M;
	const int N=505;
	bool choosedone[N][N]={};
	mint choosedp[N][N];
	function<mint(int,int)>choose=[&](int n,int k){
		if(n<k||k<0)return mint(0);
		if(n==k)return mint(1);
		if(choosedone[n][k])return choosedp[n][k];
		choosedone[n][k]=true;
		return choosedp[n][k]=choose(n-1,k)+choose(n-1,k-1);
	};
	mint F[N];F[0]=1;
	for(int i=1;i<N;++i)F[i]=i*F[i-1];
	int off=n*(n-1)/2;
	vector<mint>dp(2*off+1),tmp(dp),pref(dp);
	#define qp(idx) (idx>=0?pref[idx]:0)
	dp[off]=1;
	mint res=0;
	for(int cn=2;cn<=n;++cn){
//		for(int i=0;i<dp.size();++i)cerr<<setw(3)<<i-off<<" ";cerr<<endl;
//		for(int i=0;i<dp.size();++i)cerr<<setw(3)<<dp[i]<<" ";cerr<<endl;
//		cerr<<endl;
		partial_sum(dp.rbegin(),dp.rend(),pref.rbegin());
		mint prefixes=choose(n,cn)*F[n-cn];
		mint cur;
		for(int i=1;i<=cn;++i)
			for(int j=i+1;j<=cn;++j)
				cur+=pref[j-i+1+off];
		res+=cur*prefixes;
		partial_sum(dp.begin(),dp.end(),tmp.begin());
		partial_sum(tmp.begin(),tmp.end(),pref.begin());
		for(int i=0;i<dp.size()-n+1;++i)dp[i]=qp(i+cn-1)-2*qp(i-1)+qp(i-cn-1);
	}
	cout<<res<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}