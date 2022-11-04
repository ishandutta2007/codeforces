#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod=1e9+7; // (119<<23)+1
template<int M,int R>
struct modnum{
	int v;
	static int minv(int a,int m){return (a%=m)==1?1:m-ll(minv(m,a))*m/a;}
	static constexpr modnum root(){return R;}
	static constexpr int mod(){return M;}
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
	friend modnum mpow(modnum a,ll b){ // change this to pow and you'll never debug your code
		modnum res=1;
		for(;b;b>>=1,a*=a)if(b&1)res*=a;
		return res;
	}
};
using mint=modnum<mod,5>;

const int N=400100;
mint F[N];
mint choose(int n,int k){
	if(k>n||k<0)return 0;
	return F[n]/F[k]/F[n-k];
}

int n,l,r;

void ProGamerMove(){
	cin>>n>>l>>r;
	mint res;
	ll mxd=min(r-n,-(l-1));
	res+=mxd*choose(n,n/2);
	if(n&1)res+=mxd*choose(n,n/2);
	for(ll d=mxd+1,i=0;i<=n;++i,++d){
		// x>=l+d
		ll firstsub=max(1ll,l+d);
		// x<=r-d;
		ll lastadd=min(ll(n),r-d);
//		cerr<<d<<" "<<firstsub<<" "<<lastadd<<endl;
		if(firstsub-1>lastadd)continue;
//		cerr<<n/2-(firstsub-1)<<endl;
		res+=choose(lastadd-firstsub+1,(n+1)/2-(firstsub-1));
		if(n&1)res+=choose(lastadd-firstsub+1,n/2-(firstsub-1));
	}
	cout<<res<<"\n";
}

signed main(){
	F[0]=1;
	for(int i=1;i<N;++i)F[i]=F[i-1]*i;
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}