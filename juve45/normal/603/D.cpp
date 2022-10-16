#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(ll _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

#define st first
#define nd second

#define EPS 1e-9
const double PI = acos(-1);

using namespace std;
using ll = long long;

const ll N = 2018;
ll n, k, use[N][N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << ": ";
	for(auto e : v) out << e << ' ';
	return out;
}

struct frac {
	ll x, y;

	frac() {
		x = y = 0;
	}

	frac(ll _x, ll _y) {
		x = _x;
		y = _y;
		red();
	}

	void red() {
		ll g = __gcd(x, y);
		if(g) {
			x /= g;
			y /= g;
		}
		if(y < 0)
			x = -x, y = -y;
		if(y == 0) x = 1;
	}

	frac operator-(frac f) {
		frac ans;
		ans.y = y * f.y;
		ans.x = x * f.y - f.x * y;
		ans.red();
		return ans;
	}
	
	frac operator/(frac f) {
		frac ans;
		ans.x = x * f.y;
		ans.y = y * f.x;
		ans.red();
		return ans;
	}

	bool operator<(const frac &f) const {
		if(y == 0)
			return false;
		if(f.y == 0)
			return true;
		return x * f.y < f.x * y;
	}

	bool operator==(const frac &f) const {\
		if(*this < f || f < *this)
			return false;
		return true;
	}

	double eval() {
		if(y == 0)
			return 88150.454501;
		return (double) x / y;
	}

};

struct poll {
	frac x, y;

	poll(frac _a, frac _b) {
		x = _a;
		y = _b;
	}

	bool operator==(poll p) {
		if(p.x == x && p.y == y)
			return true;
		return false;
	}
};

ostream& operator<<(ostream& out, frac &f) {
	return out << f.x << '/' << f.y; 
}
ostream& operator<<(ostream& out, poll &f) {
	return out << '(' << f.x << ' ' << f.y << ')'; 
}
double a, b, c;

poll get_ll(ll a, ll b, ll c) {
	return poll(frac(- a * c, a * a + b * b), frac(- b * c, a * a + b * b));
}

vector <poll> v;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(ll i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		v.push_back(get_ll(a, b, c));
	}

	// dbg(v);

	ll ans = 0;
	for(ll i = 0; i < v.size(); i++) {
		vector <double> vv;
		for(ll j = i + 1; j < v.size(); j++) {
			
			if(v[i] == v[j]) {
				ans += n - i - 2;
				continue;
			}

			frac dy = v[i].y - v[j].y;
			frac dx = v[j].x - v[i].x;
			frac m = dy / dx;
			m.red();
			vv.push_back(m.eval());
		}
			
		sort(vv.begin(), vv.end());
		for(int ii = 0; ii < vv.size();) {
			long long nr = 1;
			while(ii + nr < vv.size() && fabs(vv[ii+nr] - vv[ii]) < 1e-11)
				nr++;
			ii += nr;
			ans += nr*(nr - 1) / 2;
		}
		// dbg(ans);
	}

	cout << ans << '\n';
}