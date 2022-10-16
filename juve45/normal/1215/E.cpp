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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 400100;
const long long M = 20;
long long n, cost[22][22], a[N], delta[N], sz[(1 << M)], dp[(1 << M)];
vector <long long> v[22];


void pre() {
	long long tmp[N];
	for(long long i = 0; i < 20; i++) {
		memset(tmp, 0, sizeof tmp);
		for(auto k : v[i]) tmp[k] = 1;

		for(long long j = 1; j <= n; j++)
			tmp[j] += tmp[j - 1];
		// dbg_v(tmp, 10);

		for(long long j = 0; j < 20; j++) {
			if(i == j) continue;
			for(auto k : v[j])
				cost[i][j] += v[i].size() - tmp[k];
		}
	}


}

long long cst(long long x, long long msk) {
	long long ret = 0;
	for(long long i = 0; i < M; i++)
		if(msk & (1 << i)) ;
		else ret += cost[x][i];
	// dbg(x, msk, ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]--;
		v[a[i]].push_back(i);
	}

	for(long long i = 0; i < (1 << M); i++) {
		for(long long j = 0; j < M; j++)
			if(i & (1 << j))
				sz[i] += v[j].size();
	}

	pre();
	// dbg(cost[0][1]);

	// dbg_v(cost[0], n);
	// dbg_v(cost[1], n);
	// dbg_v(cost[2], n);
	// dbg_v(cost[3], n);
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;

	for(long long i = 1; i < (1 << M); i++) {
		for(long long j = 0; j < M; j++)
			if(i & (1 << j)) {
				dp[i] = min(dp[i], dp[i ^ (1 << j)] + cst(j, i));
			}
	}
	// dbg_v(dp, 16);
	cout << dp[(1 << M) - 1] << '\n';
}