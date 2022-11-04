#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod=998244353;
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
using mint = modnum<mod>;

const int N=200100;
int suf[N],pos[N];
mint F[N];
int n,k;


mint choose(int n,int k){
	if(k>n||k<0)return 0;
	return F[n]*F[k].inv()*F[n-k].inv();
}

void TenIQBenchmark(){
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>suf[i],pos[suf[i]]=i;
	int lt=0;
	for(int i=0;i<n-1;++i)if(!(suf[i]==n-1||(suf[i+1]!=n-1&&pos[suf[i]+1]<pos[suf[i+1]+1])))++lt;
	mint res=0;
	for(int add=0;add+lt<n;++add)res+=choose(k,add+lt+1)*choose(n-1-lt,add);
	cout<<res<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	F[0]=1;
	for(int i=1;i<N;++i)F[i]=i*F[i-1];
	int tc=1;
	//cin>>tc;
	while(tc--)TenIQBenchmark();
}