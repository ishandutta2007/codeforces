#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

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

const int MX=1e6;
mint F[MX],IF[MX];
mint choose(int n,int k){
	if(k>n||k<0)return 0;
	return F[n]*IF[k]*IF[n-k];
}

// number of valid bracket sequences / unlabeled binary trees ...
mint catalan(int n){
	return F[2*n]*IF[n+1]*IF[n];
}

unordered_set<int> ls;

struct DSU{
	int cmp, n;
	vector<int>p, left, right, act; // -size if self, parent otherwise
	vector<mint> sum;
	DSU(int n):cmp(n),n(n),p(n,-1),sum(n), left(n), right(n), act(n){ iota(left.begin(), left.end(), 0); right = left;}
	int find(int u){return p[u]<0?u:p[u]=find(p[u]);}
	int size(int u){return -p[find(u)];}
	mint& getsum(int u) { return sum[find(u)]; }
	int getleft(int u) { return left[find(u)]; }
	int getright(int u) { return right[find(u)]; }
	bool same(int u,int v){return find(u)==find(v);}
	void activate(int u, mint sm) {
		act[u] = true;
		sum[u] = sm;
		ls.insert(u);
		if (u < n && act[u + 1]) uni(u, u + 1);
		if (u && act[u - 1]) uni(u - 1, u);
	}
	int comps(){return cmp;}
	void uni(int u,int v){
		u=find(u),v=find(v);
		if(u!=v){
			if(size(u)>size(v))swap(u,v);
			p[v]+=p[u];
			p[u]=v;
			sum[v] += sum[u];
			ls.erase(left[u]);
			ls.erase(left[v]);
			left[v] = min(left[u], left[v]);
			right[v] = max(right[u], right[v]);
			ls.insert(left[v]);
			--cmp;
		}
	}
};

void ProGamerMove() {
	int n; cin >> n, ++n;
	int mxr = 3 * n + 5;
	DSU dsu(MX);
	vector<int> a(n);
	for (int& v : a) cin >> v;
	a.push_back(0);
	++n;
	int mxn = 0;
	for (int i = 0; i < n; ++i) mxn = max(mxn, a[i] + i);
	while (mxn + 3 >= a.size()) a.push_back(0);
	n = a.size();
	vector<pair<int, int>> upds(n);
	for (int i = 0; i < n; ++i) {
		upds[i] = {a[i] + i, i};
	}
	sort(upds.rbegin(), upds.rend());
	mint totsm = 0, curmul = 1;
	function<void(int, int)> add = [&] (int myk, int myn) {
		totsm -= choose(myn, myk);
		dsu.activate(myk, choose(myn, myk));
	};
	for (int myn = 0; upds.size(); ++myn) {
		totsm += curmul;
		curmul *= 2;
		for (int v : ls) {
			int myl = dsu.getleft(v);
			int myr = dsu.getright(v);
			mint newsm = 2 * dsu.getsum(v) - choose(myn - 1, myr) + choose(myn - 1, myl - 1);
			dsu.getsum(v) = newsm;
			totsm -= newsm;
		}
		while (upds.size() && upds.back().first == myn) {
			add(upds.back().second, myn);
			upds.pop_back();
		}
	}
	cout << totsm << '\n';
}

signed main(){
	F[0]=IF[0]=IF[1]=1;
	for(int i=2;i<MX;++i)IF[i]=mod-int((mod/i)*IF[mod%i])%mod;
	for(int i=1;i<MX;++i)F[i]=i*F[i-1],IF[i]*=IF[i-1];
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}