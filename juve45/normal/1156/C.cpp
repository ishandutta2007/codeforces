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

const int N = 200100;
int n, a[N], z;

bool ok(int k) {
	for(int i = 1; i <= k; i++)
		if(a[n - k + i] - a[i] < z)
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> z;
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);

	int l = 0, r = n / 2;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
}