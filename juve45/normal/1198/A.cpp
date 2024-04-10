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

const int N = 400100;
int n, m, a[N], b[N], c[N], s[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	m *= 8;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n+ 1);

	int j = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == b[j])
			c[j]++;
		else 
			b[++j] = a[i], c[j] = 1;

	int max = m / n;

	if(max < 22)
		max = (1 << max);
	else return cout << 0 << '\n', 0;
	if(max > j) max = j;
	
	// dbg(max);

	for(int i = j; i > 0; i--)
		s[i] = s[i + 1] + c[i];

	int sum = 0, ans = n;
	for(int l = 1; l + max - 1 <= j; l++) {
		// dbg(l, sum, s[l + max]);
		ans = min(ans, sum + s[l + max]);
		sum += c[l];
	}
	cout << ans << '\n';

	// dbg_v(a, n + 1);
	// dbg_v(b, j + 1);
	// dbg_v(s, j + 1);
}