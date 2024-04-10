#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, w, h, nr, total;
map<long long, long long> ch, cw;
map<pair<long long, long long>, long long > c;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

bool check(long long wc, long long hc) {
	for(auto i : cw) if(i.nd % wc != 0) return false;
	for(auto i : ch) if(i.nd % hc != 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> w >> h >> nr;
		c[{w, h}] += nr;
		ch[h] += nr;
		cw[w] += nr;
		total += nr;
	}

	long long gh = 0, gw = 0;
	w = 0, h = 0;
	for(auto i : ch) gh = __gcd(gh, i.nd);
	for(auto i : cw) gw = __gcd(gw, i.nd);

	// dbg_ok;
	// for(auto i : ch) dbg(i.nd);
	// dbg_ok;
	// for(auto i : cw) dbg(i.nd);

	for(auto &i : ch) h += i.nd / gh, i.nd /= gh;
	for(auto &i : cw) w += i.nd / gw, i.nd /= gw;

	dbg(gh);
	dbg(gw);

	long long base = h * w;
	dbg(total);
	dbg(base);

	if(total % base != 0)
		return cout << "0", 0;
	total /= base;

	for(auto i : c) 
		if(i.nd % total != 0)
			return cout << "0\n", 0;
		else i.nd /= total;

	long long W = c.begin()->st.st;
	long long H = c.begin()->st.nd;
	long long cW = cw[W], cH = ch[H];

	for(auto i : c) {
		// pe un rand de latime w -> c(W, i.st.nd), c(i.st.st, i.st.nd)
		if(i.nd % cw[i.st.st] != 0 || c[{W, i.st.nd}] % cW != 0 || i.nd / cw[i.st.st] != c[{W, i.st.nd}] / cW)
			return cout << 0 << '\n', 0;
	}

	long long ans = 0;
	for(long long i = 1; i * i <= total; i++)
		if(total % i == 0) {
			// if(check(i, total / i))
				ans++;
			if(i * i != total)
				// if(check(total / i, i))
					ans++;
		}
	cout << ans << '\n';
}