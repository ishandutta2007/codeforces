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
int n, dp[N];
string s;
vector <pair<int, int> > v;

int dist(int a, int b) {
	return abs(v[a].st - v[b].st) + abs(v[a].nd - v[b].nd);
}

int cb(int pos) {

	int l = 0, r = pos - 1;
	while(l != r) {
		int mid = (l + r) / 2;
		if(dist(mid, pos) == pos - mid) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> s;
	int x = 0, y = 0;

	v.push_back({x, y});

	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') x--;
		if(s[i] == 'R') x++;
		if(s[i] == 'U') y++;
		if(s[i] == 'D') y--;
		v.push_back({x, y});
	}

	// dbg(v);

	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int last = cb(i);
		dp[i] = dp[last] + 1;
	}
	cout << dp[n];
}