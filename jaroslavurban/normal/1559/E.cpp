#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod=998244353; // (119<<23)+1
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

vector<int>muarr(int n){
	vector<int>comp(n);
	vector<int>mu(n);
	for(int i=2;i<n;++i)
		if(!comp[i]){
			++mu[i];
			for(int j=2*i;j<n;j+=i){
				comp[j]=true;
				++mu[j];
			}
			for(ll j=i*ll(i);j<n;j+=i*i)mu[j]=1e9;
		}
	for(int i=0;i<n;++i)
		if(mu[i]>=1e9)mu[i]=0;
		else mu[i]=1-2*(mu[i]&1);
	return mu;
}

int n,m;
vector<pair<int,int>>ranges;

mint f(int d){
	vector<mint>cnt(m/d+1),pref(m/d+2,1);cnt[0]=1;pref[0]=0;
	for(auto[l,r]:ranges){l=(l+d-1)/d,r=(r+d-1)/d;
		vector<mint>ncnt(m/d+1);
		for(int i=0;i<=m/d;++i)ncnt[i]=pref[max(0,i-l+1)]-pref[max(0,i-r+1)];
		swap(cnt,ncnt);
		partial_sum(cnt.begin(),cnt.end(),pref.begin()+1);
	}
	return accumulate(cnt.begin(),cnt.end(),mint(0));
}

void ProGamerMove(){
	cin>>n>>m;
	ranges.resize(n);
	for(auto&[l,r]:ranges)cin>>l>>r,++r;
	auto mu=muarr(m+1);
	mint res;
	for(int d=1;d<=m;++d)res+=mu[d]*f(d);
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}