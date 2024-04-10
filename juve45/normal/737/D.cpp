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

const int N = 4004;
const int D = 90;
const int INF = 1e9 + 100;
int n, a[N];

int dp[N / 2 + D][2 * D][D + 1][2];
// map <pair<int, int>, long long> dp[N][2];

long long sum(int x, int y) {
	return a[y] - a[x - 1];
}

int get(int f, int b, int move, int p) {
	// dbg(f, b, move, p);
	int rem = b - 1 - f;
	// dbg(f, b, move, rem, p);
	if(move > rem) return 0;
	int dif = f - (n + 1 - b);
	dif += 90;
	if(dif < 0) dbg(dif);
	assert(dif >= 0);
	assert(move < 90);
	if(dp[f][dif][move][p] == -INF) {
		
		long long nr2 = -INF, nr1 = -INF;
		if(p) {
			nr1 = sum(f + 1, f + move) - get(f + move, b, move, 1 - p);
			if(move + 1 <= rem)
				nr2 = sum(f + 1, f + move + 1) - get(f + move + 1, b, move + 1, 1 - p);
		} else {
			nr1 = sum(b - move, b - 1) - get(f, b - move, move, 1 - p);
			if(move + 1 <= rem)
				nr2 = sum(b - move - 1, b - 1) - get(f, b - move - 1, move + 1, 1 - p);
			// dbg(f, b, move, nr1, nr2);
		}
		dp[f][dif][move][p] = max(nr1, nr2);		
	}
	return dp[f][dif][move][p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < N / 2 + D; i++)
		for(int j= 0; j <= 2 * D; j++)
			for(int k = 0; k <= D; k++)
				dp[i][j][k][0] = dp[i][j][k][1] = -INF;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	cout << get(0, n + 1, 1, 1) << '\n';
}