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
int n, dp[N], a[N], s, l;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> l;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int last = 1;
	dp[0] = 0;
	deque <int> dmin, dmax, dq;
	dq.push_front(0);
	for(int i = 1; i <= n; i++) {
		while(!dmin.empty() && a[dmin.back()] > a[i]) dmin.pop_back();
		dmin.push_back(i);
		while(!dmax.empty() && a[dmax.back()] < a[i]) dmax.pop_back();
		dmax.push_back(i);

		// dbg(last + l - 1, i);
		while(a[dmax.front()] - a[dmin.front()] > s && last + l -1 < i) {
			if(dmax.front() == last) dmax.pop_front();
			if(dmin.front() == last) dmin.pop_front();
			last++;
		}
		while(dq.front() + 1 < last) dq.pop_front();

		// dbg(last, i, dq.front());
		// for(auto i : dq) dbg(dp[i]);
		
		if(dq.empty() || a[dmax.front()] - a[dmin.front()] > s || last + l - 1 > i)
			dp[i] = 1000000000;
		else 
			dp[i] = dp[dq.front()] + 1;

		if(i >= l)
		while(!dq.empty() && dp[dq.back()] > dp[i - l + 1]) dq.pop_back();
		dq.push_back(i - l + 1);
	}

	// dbg_v(dp, n + 1);
	
	if(dp[n] > n + 1) dp[n] = -1;
	cout << dp[n] << '\n';
}