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

const int N = 4401007;
const int M = 21;
// const int M = 4;
int n, a[N];
vector <int> dp[N];

void upd(vector <int> & dest, int x) {
	// dbg(x, dest);
	if(x == dest[0] || x == dest[1]) return;
	if(x > dest[0]) { dest[1] = dest[0]; dest[0] = x; }
	else if(x > dest[1]) dest[1] = x;
	// dbg(dest);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[a[i]].push_back(i);
	}

	for(int i = 1; i <= n; i++) {
		sort(dp[a[i]].begin(), dp[a[i]].end(), greater <int>());
		dp[a[i]].resize(2);
	}

	// dbg_v(dp, 10);

	for(int msk = (1 << M) - 1; msk >= 0; msk--) {
		dp[msk].resize(2);
		for(int i = 0; i < M; i++) 
			if((msk & (1 << i)) == 0)  {
				upd(dp[msk], dp[msk ^ (1 << i)][0]);
				upd(dp[msk], dp[msk ^ (1 << i)][1]);
			}
		// dbg(msk, dp[msk]);
	}

	dbg_ok;
	int comp = (1 << M) - 1, ans = 0;
	for(int i = 1; i + 2 <= n; i++) {
		int pre = 0;
		// dbg(a[i]);
		for(int j = M - 1; j >= 0; j--) {
			if((a[i] & (1 << j)) == 0) {
				// dbg(j, pre);
				if(dp[pre ^ (1 << j)].size() >= 2 && dp[pre ^ (1 << j)][1] > i)
					pre ^= (1 << j);
			}

		}
		// dbg(pre);
		ans = max(ans, pre ^ a[i]);
	}
	cout << ans << '\n';
}