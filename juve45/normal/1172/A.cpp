#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, deque <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n;

int f[N], a[N], b[N];
deque <int> dq;

int dist(int to, int from) {
	if(from >= to)
		return from - to;
	return n - to + from + 1;
}

int try1() {
	int ret = 0;
	while(dq.front() != 1) {
		// dbg_ok;
		if(f[dq.back() + 1] == 0) return 2 * n;
		f[dq.back() + 1]--;
		dq.push_back(dq.back() + 1);
		// dbg(dq.back(), ret);
		f[dq.front()]++;
		dq.pop_front();
		ret++;
	}
	// dbg(ret);
	return ret;
}

int try2() {
	int ret = 0;
	for(int i = 1; i <=n; i++)
		if(a[i])
			ret = max(ret, n + 1 - a[i]);
	for(int i = 1; i <=n; i++)
		if(b[i])
			ret = max(ret, i + n + 1 - b[i]);
	// dbg(ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], f[a[i]]++;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		dq.push_back(b[i]);
	}

	int ans = 2 * n;
	int last = n;
	while(b[last] != 1 && b[last] == b[last - 1] + 1) last--;
	// dbg(last);

	if(b[last] == 1)
		ans = try1();
	ans = min(ans, try2());

	cout << ans << '\n';
	return 0;
}