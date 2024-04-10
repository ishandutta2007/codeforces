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

void ProGamerMove(){
	int n;cin>>n;
	vector<int>adds(n,-1);
	for(int i=0;i<n;++i){
		char c;cin>>c;
		if(c=='+')cin>>adds[i];
	}
	mint res=0;
	for(int i=0;i<n;++i){
		if(adds[i]==-1)continue;
		vector<mint>dp(n);dp[0]=1;
		for(int j=0;j<n;++j){
			if(i==j)continue;
			vector<mint>ndp(n);
			for(int k=0;k<n;++k)
				if(dp[k]){
					if(~adds[j]){
						if((j<i&&adds[j]<=adds[i])||(j>i&&adds[j]<adds[i]))ndp[k+1]+=dp[k];
						else ndp[k]+=dp[k];
					}else{
						if(j<i||k)ndp[max(0,k-1)]+=dp[k];
					}
					ndp[k]+=dp[k];
				}
			swap(dp,ndp);
		}
		for(auto v:dp)res+=v*adds[i];
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