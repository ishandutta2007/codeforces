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

struct P {
	ll s, d, c;
};

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

ll last(P a) { return a.s + a.d * (a.c - 1); }

void ProGamerMove() {
	P B, C;
	cin >> B.s >> B.d >> B.c;
	cin >> C.s >> C.d >> C.c;
	if (C.d % B.d || (C.s - B.s) % B.d || B.s > C.s || last(C) > last(B)) { cout << "0\n"; return; }
	vector<ll> cands;
	for (ll i = 1; i * i <= C.d; ++i) {
		if (C.d % i == 0) {
			if (lcm(i, B.d) == C.d) cands.push_back(i);
			if (i * i != C.d && lcm(C.d / i, B.d) == C.d) cands.push_back(C.d / i);
		}
	}
	mint res = 0;
	for (ll d : cands) {
		res += C.d / d * C.d / d;
	}
	if (cands.size() && C.s - C.d < B.s || last(B) < last(C) + C.d) cout << "-1\n";
	else cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}