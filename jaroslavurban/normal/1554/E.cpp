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

void ProGamerMove(){
	int n;cin>>n;
	vector<vector<int>>g(n);
	for(int u,v,i=1;i<n;++i){
		cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>children(n),lc(n),done(n),can(n);
	vector<mint>div(n),res(n);
	auto add=[&](int d){
		if(1<d&&d<n){
			for(int i=2;i*i<=d;++i)can[i]=can[d/i]=1;
			can[d]=true;
		}
	};
	function<void(int,int)>dfs=[&](int u,int p){
		for(int i=0;i<g[u].size();++i)if(int&v=g[u][i];v!=p){
			dfs(v,u);
			++children[u];
			if(!children[v]){
				swap(v,g[u].back());
				g[u].pop_back();
				--i;
				++lc[u];
			}
		}
		if(!u||(children[u]>1&&children[u]==lc[u])){
			add(children[u]);
			add(children[u]+1);
		}
	};
	dfs(0,0);
	function<int(int,int,int,int&)>tr=[&](int u,int p,int d,int&pos){
		if(!pos)return 0;
		int cnt=lc[u];
		for(int v:g[u])if(v!=p){
			cnt+=tr(v,u,d,pos);
			if(!pos)return 0;
		}
		if(!u){
			if(cnt%d)pos=0;
			return 0;
		}
		if(cnt%d==0)return 1;
		if(cnt%d==d-1)return 0;
		pos=0;
		return 0;
	};
	div[1]=mpow(mint(2),n-1);
	for(int pos,d=2;d<n;++d)if(!done[d]){
		pos=can[d];
		tr(0,0,d,pos);
		done[d]=true;
		div[d]=pos;
		if(!pos){
			for(int j=1;d*j<n;++j)done[d*j]=1;
		}
	}
	auto mu=muarr(n);
	for(int i=1;i<n;++i)
		for(int j=1;i*j<n;++j)
			res[i]+=mu[j]*div[i*j];
	for(int i=1;i<n;++i)cout<<res[i]<<" ";
	cout<<"0\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}