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
		assert(b>=0);
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

void ProGamerMove(){
	int n,N=100100;cin>>n;
	vector<int>freq(N);
	for(int a,f,i=0;i<n;++i)cin>>a>>f,freq[a]=f;
	ll m=accumulate(freq.begin(),freq.end(),0ll);
	if(m<2){cout<<"0\n";return;}
	vector<mint>asum(N),sqsum(N);
	vector<ll>cnt(N);
	for(int i=0;i<N;++i)if(freq[i]){
		for(int j=1;j*j<=i;++j)if(i%j==0){
			asum[j]+=freq[i]*mint(i);
			sqsum[j]+=freq[i]*mint(i)*mint(i);
			cnt[j]+=freq[i];
			if(j*j<i){
				asum[i/j]+=freq[i]*mint(i);
				sqsum[i/j]+=freq[i]*mint(i)*mint(i);
				cnt[i/j]+=freq[i];
			}
		}
	}
	auto mu=muarr(N);
	mint sum=0,it=1/mint(2);
	for(int i=1;i<N;++i)if(cnt[i]>1){
		mint two=cnt[i]*mpow(mint(2),cnt[i]-2)*(asum[i]*asum[i]-sqsum[i])*it;
		mint one=(cnt[i]-1)*mpow(mint(2),cnt[i]-2)*sqsum[i];
		sum+=(two+one)*mu[i];
	}
	cout<<sum<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}