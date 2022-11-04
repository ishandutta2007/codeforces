#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// NOT TESTED
template<int M>
struct modnum{
	int v;
	static int minv(int a,int m){return (a%=m)==1?1:m-ll(minv(m,a))*m/a;}
	modnum():v(0){}
	modnum(ll v_):v(int(v_%M)){if(v<0)v+=M;}
	explicit operator int()const{return v;}
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
using mint = modnum<int(1e9+7)>;

const int N=100100,mod=1e9+7;
int mu[N],maxp[N],muls[N];
int n;

ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b&1)return a*powmod(a*a%mod,b/2)%mod;
	return powmod(a*a%mod,b/2);
}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	for(int i=2;i<N;++i){
		if(!maxp[i]){
			for(int j=i;j<N;j+=i){
				maxp[j]=i;
				++mu[j];
			}
			for(ll j=i*ll(i);j<N;j+=i*ll(i))mu[j]=1e9;
		}
	}
	for(int i=1;i<N;++i)if(mu[i]>=1e9)mu[i]=0;
	else mu[i]=1-2*(mu[i]&1);
	cin>>n;
	for(int i=0;i<n;++i){
		int a;cin>>a;
		vector<int>primes;
		while(a!=1){
			if(primes.empty()||primes.back()!=maxp[a])primes.push_back(maxp[a]);
			a/=maxp[a];
		}
		for(int j=0;j<1<<primes.size();++j){
			int num=1;
			for(int k=0;k<primes.size();++k)if(j&1<<k)num*=primes[k];
			++muls[num];
		}
	}
	mint res=0;
	for(int i=1;i<N;++i)res+=mu[i]*(powmod(2,muls[i])-1);
	cout<<int(res)<<endl;
}