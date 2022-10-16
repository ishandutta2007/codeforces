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

const int N = 300100;
int n, x[N], y[N];

multiset <int> xs, ys;

int calc(int x1, int y1, int x2, int y2) {
	return 2 * abs(x1 - x2) + 2 * abs(y1 - y2);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		xs.insert(x[i]);
		ys.insert(y[i]);
	}

	int ans = (*xs.rbegin() - *xs.begin()) * 2 + 2 * (*ys.rbegin() - *ys.begin());

	int ans2 = 0;
	for(int i = 1; i <= n; i++) {
		xs.erase(xs.find(x[i]));
		ys.erase(ys.find(y[i]));

		ans2 = max(ans2, calc(x[i], y[i], *xs.begin(), *ys.begin()));
		ans2 = max(ans2, calc(x[i], y[i], *xs.begin(), *ys.rbegin()));
		ans2 = max(ans2, calc(x[i], y[i], *xs.rbegin(), *ys.begin()));
		ans2 = max(ans2, calc(x[i], y[i], *xs.rbegin(), *ys.rbegin()));

		xs.insert(x[i]);
		ys.insert(y[i]);
	}
	cout << ans2 << ' ';
	for(int i = 4; i <= n; i++) cout << ans << ' ';
	cout << '\n';
}