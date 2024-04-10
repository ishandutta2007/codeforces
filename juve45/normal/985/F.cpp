#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 200100;
const long long MOD = 1e9 + 7;
const long long BASE = 37;


long long n, k, x, y, len, m;
long long pb[N];
string s;

long long pow(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;

	long long aux = pow(base, exp / 2);
	aux *= aux;
	aux %= MOD;
	if(exp % 2) 
		return (aux * base) % MOD;
	return aux;
}

long long inv(long long k) {
	return pow(k, MOD - 2);
}

struct hsh {
	unsigned long long v[30];

	hsh() {
		memset(v, 0, sizeof v);
	}

	hsh operator/(long long d) {
		long long id = inv(d);
		hsh ans;
		for(long long i = 0; i < 30; i++)
			ans.v[i] = (v[i] * id) % MOD;
		return ans;
	}

	hsh operator-(hsh d) {
		hsh ans;
		for(long long i = 0; i < 30; i++)
			ans.v[i] = (MOD + v[i] - d.v[i]) % MOD;
		return ans;
	}

	bool operator==(hsh a) {
		long long va[33];
		long long vb[33];
		long long nr = 'z' - 'a';
		for(long long i = 0; i <= nr; i++)
			va[i] = v[i],
			vb[i] = a.v[i];
		sort(va, va + nr + 1);
		sort(vb, vb + nr + 1);
		// dbg_v(va, nr + 1);
		// dbg_v(vb, nr + 1);
		for(long long i = 0; i <= nr; i++) 
			if(va[i] != vb[i]) 
				return 0;
		return 1;
	}

} h[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


void genH() {

	pb[0] = 1;
	for(long long i = 1; i < N; i++)
		pb[i] = (pb[i - 1] * BASE) % MOD;

	for(long long i = 0; i < s.size(); i++) {
		if(i)
			h[i] = h[i - 1];
		h[i].v[s[i] - 'a'] += pb[i];
		h[i].v[s[i] - 'a'] %= MOD;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;

		// dbg_v(h[0].v, 30);
		// dbg_v(h[1].v, 30);
		// dbg_v(h[2].v, 30);
	genH();
	dbg_v(pb, 15);
	for(long long i = 1; i <= m; i++) {
		cin >> x >> y >> len;
		x--;
		y--;
		hsh A = h[x + len - 1];
		if(x > 0)
			A = A - h[x - 1];
		dbg_v(A.v, 30);
		hsh B = h[y + len - 1];
		dbg_v(B.v, 30);
		dbg_v(h[y - 1].v, 30);
		if(y > 0)
			B = B - h[y - 1];

		dbg_v(B.v, 30);
		A = A/pb[x];
		B = B/pb[y];
		// dbg(pb[y]);
		// dbg(inv(pb[y]));

		dbg_v(A.v, 30);
		dbg_v(B.v, 30);
		if(A == B) cout << "YES\n";
		else cout << "NO\n";

	}

}