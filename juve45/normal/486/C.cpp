#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, a[N], p, ret, ret2, b[N], nr;
string s;

int dif(char a, char b) {
	return min(abs(a - b), 26 - abs(a - b));
}

void err(int *a, int p, int & nr) {
	if(a[p]) nr -= 2;
	a[p] = a[n - p - 1] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> p;
	p--;
	cin >> s;
	
	for(int i = 0; i < s.size() / 2; i++)
		a[i] = a[n - 1 - i] = dif(s[i], s[n - 1 - i]);

	for(int i = 0; i < n; i++)
		b[i] = a[i], nr += (a[i] != 0), ret += a[i];

	ret /= 2;
	ret2 = ret;
	// dbg(ret);
	// dbg_v(a, n);
	int pp = p;
	int nnr = nr;
	int ans = ret;

	if(nr == 0) return cout << "0\n", 0;

	while(nr) {
		err(a, p, nr);
		p = (p + 1) % n;
		ret++;
		err(a, p, nr);
	}

	for(int i = 0; i < n; i++)
		a[i] = b[i];
	p = pp;

	// dbg_v(b,n);
	// dbg(pp);
	while(nnr) {
		err(b, pp, nnr);
		pp = (n + pp - 1) % n;
		ret2++;
		err(b, pp, nnr);
		// dbg(pp, nnr);
	}

	if(p >= n / 2) p = n - p - 1;
	int mn = n, mx = 0;

	// dbg_v(a, n);
	for(int i = 0; i < n / 2; i++)
		if(a[i])
			mn = min(i, mn), mx = max(i, mx);
	// dbg(mn, mx, p);
	ans += mx - mn + min(abs(mx - p), abs(p - mn));

	cout << min({ret, ret2, ans});
}