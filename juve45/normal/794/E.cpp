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
int n, a[N], mx[N], ans[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i + 1 <= n; i++) {
		int res = max(a[i], a[i + 1]);
		int l = 2;
		int r = 2 * min(i, n - i);
		mx[r] = max(mx[r], res);

		if(i > 1) {
			int res_2 = max(min(a[i], a[i + 1]), min(a[i], a[i - 1]));
			int ll = 3;
			int rr = 2 * min(i - 1, n - i) + 1;
			mx[rr] = max(mx[rr], res_2);
		}
	}
	mx[1] = *max_element(a + 1, a + n + 1);

	int tmp[] = {0, 0};
	dbg_v(mx, n + 1);


	for(int i = n; i > 0; i--) {
		tmp[i % 2] = max(tmp[i % 2], mx[i]);
		ans[i] = max(ans[i], tmp[i % 2]);
		cout << ans[i] << ' ';
	}
	// dbg_v(ans, n + 1);
}