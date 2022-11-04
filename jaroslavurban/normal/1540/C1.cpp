#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

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

const int N=101;
int c[N],b[N],need[N];

void ProGamerMove(){
	int n,q,x;cin>>n;
	for(int i=0;i<n;++i)cin>>c[i];
	for(int i=0;i<n-1;++i)cin>>b[i];
	cin>>q>>x;
	if(x>=N*N){cout<<"0\n";return;}
	need[0]=x;
	for(int i=1;i<n;++i)need[i]=need[i-1]+b[i-1];
	ll smn=0;
	for(int i=0;i<n;++i){
		need[i]-=smn;
		smn=max(0,-need[i]);
		if(i+1!=n)need[i]=max(0,need[i]);
	}
	vector<mint>dp(N*N);
	dp[0]=1;
	for(int i=n-1;i>=0;--i){
		vector<mint>ndp(N*N);
		for(int j=0;j<N*N;++j)if(dp[j])
			for(int k=0;k<=c[i];++k)if(max(0,j+need[i]-k)<N*N)
				ndp[max(0,j+need[i]-k)]+=dp[j];
		swap(dp,ndp);
	}
	cout<<dp[0]<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}