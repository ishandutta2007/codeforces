#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
template<int M>
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
using mint = modnum<mod>;

const int N=100100;
mint F[N];
int n,k;

mint choose(ll n,ll k){
	if(k>n||k<0)return 0;
	return F[n]*F[n-k].inv()*F[k].inv();
}

void ProGamerMove(){
	cin>>n>>k;
	mint res=1,dv=n;
	for(int p=1;p<=n;++p){
		res+=choose(n-(p-1)*ll(k-1),p)*F[p]*dv.inv();
		dv*=max(n-p,1);
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	F[0]=1;
	for(int i=1;i<N;++i)F[i]=F[i-1]*mint(i);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}