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
int n;
double mn[N], mx[N], pr[N][2], sum[3];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> mx[i];
	for(int i = 1; i <= n; i++) cin >> mn[i];

	for(int i = n; i >= 0; i--) {
		mn[i] += mn[i + 1],
		mx[i] += mx[i + 1];
		double p = mn[i];
		double s = mx[i] + mn[i];
		double d = s * s - 4 * p;
		// dbg(i, s, p, d);
		// assert(d >= -1e-6);
		d = abs(d);
		double x = (-s + sqrt(d)) / (-2.);
		double y = s - x;
		// assert(x >= 0 && x <= 1);
		// assert(y >= 0 && y <= 1);
		pr[i][0] = x - sum[0];
		pr[i][1] = y - sum[1];
		sum[0] += pr[i][0];
		sum[1] += pr[i][1];
	}
	cout << fixed << setprecision(7);
	for(int i = 1; i <= n; i++) cout << pr[i][0] << ' ';
	cout << '\n';
	for(int i = 1; i <= n; i++) cout << pr[i][1] << ' ';
	cout << '\n';
}