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

// prime[i] = highest prime factor of i
vector<int>prime;
vector<int>erat(int n){ // exclusive
	prime.resize(n);
	vector<int>res;
	for(int i=2;i<n;++i)if(!prime[i]){
		res.push_back(i);
		for(int j=i;j<n;j+=i)prime[j]=i;
	}
	return res;
}
unordered_map<int,int>factorize(int x){
	unordered_map<int,int>res;
	while(x!=1){
		++res[prime[x]];
		x/=prime[x];
	}
	return res;
}

void ProGamerMove() {
	int n; cin >> n;
	vector<vector<pair<int, pair<int, int>>>> g(n);
	for (int a, b, x, y, i = 0; i < n - 1; ++i) {
		cin >> a >> b >> x >> y;
		--a, --b;
		g[a].push_back({b, {y, x}});
		g[b].push_back({a, {x, y}});
	}
	mint mul = 1;
	map<int, int> lcm, m, m2;
	vector<int> vis(n, 0);
	function<void(int)> go1 = [&](int u) {
		vis[u] = true;
		for (auto [v, p] : g[u]) {
			if (vis[v]) continue;
			auto f = factorize(p.second);
			auto f2 = factorize(p.first);
			for (auto [v, c] : f) m[v] += c;
			for (auto [v, c] : f2) m2[v] += c;
			go1(v);
			for (auto [v, c] : f) {
				lcm[v] = max(lcm[v], max(0, m[v] - m2[v]));
				m[v] -= c;
			}
			for (auto [v, c] : f2) {
				lcm[v] = max(lcm[v], max(0, m[v] - m2[v]));
				m2[v] -= c;
			}
		}
	};
	go1(0);
	mint lc = 1;
	for(auto [v, c] : lcm) lc *= mpow(mint(v), (ll)c);
	mint res = 0;
	vis.assign(n, 0);
	function<void(mint, mint, int)> go2 = [&](mint m, mint m2, int u) {
		if (vis[u]) return;
		vis[u] = true;
		res += lc / m * m2;
		for (auto [v, p] : g[u]) go2(m * p.second, m2 * p.first, v);
	};
	go2(1, 1, 0);
	cout << res << "\n";
}

signed main(){
	erat(200100);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}