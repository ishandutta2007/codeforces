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

const int PRIMES = 10;
const int VALMAX = 30;
int n, dp[111][1055][15], a[111], cheap[1223][33], ant[111][1055][15], res[111];

vector <int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29});
vector <int> big_pr({31, 37, 41, 43, 47, 53, 59, 61, 67});

int solve(int msk, int val) {
	vector <int> my;
	for(int i = 0; i < primes.size(); i++)
		if(msk & (1 << i))
			my.push_back(primes[i]);

	int ans = 100;
	for(int nr = 1; nr <= 2 * VALMAX; nr++) {
		int tmp = nr;
		for(auto i : my)
			while(tmp % i == 0) 
				tmp /= i;
		if(tmp == 1) {
			if(abs(nr - val) < abs(ans - val))
			ans = nr;
		}
	}
	return ans;
}

void pre() {
	for(int i = 0; i < (1 << PRIMES); i++)
		for(int j = 1; j <= VALMAX; j++)
			cheap[i][j] = solve(i, j);
}

int main() {
	ios_base::sync_with_stdio(false);

	pre();

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	memset(dp, 0x3f, sizeof dp);

	dp[0][0][0] = 0;

	for(int i = 1; i <= n; i++) {
		for(int msk = 0; msk < (1 << PRIMES); msk++) {
			for(int sub = msk; ; sub = (sub - 1) & msk) {

				for(int cnt = 0; cnt < 9; cnt++) {
					if(dp[i - 1][msk ^ sub][cnt] + abs(cheap[sub][a[i]] - a[i])< dp[i][msk][cnt]) {
						dp[i][msk][cnt] = dp[i - 1][msk ^ sub][cnt] + abs(cheap[sub][a[i]] - a[i]);
						ant[i][msk][cnt] = sub;
					}
					if(cnt && dp[i - 1][msk][cnt - 1] + big_pr[cnt - 1] - a[i] < dp[i][msk][cnt]) {
						dp[i][msk][cnt] = dp[i - 1][msk][cnt - 1] + big_pr[cnt - 1] - a[i];
						ant[i][msk][cnt] = -big_pr[cnt - 1];
					} 
				}
        if(sub == 0) break;
      }
		}
	}

	pair <int, int> ans = {0, 0};
	for(int msk = 0; msk < (1 << 10);msk++)
		for(int cnt = 0; cnt < 9; cnt++)
			if(dp[n][msk][cnt] < dp[n][ans.st][ans.nd])
				ans = {msk, cnt};
			// ans = min(ans, dp[n][msk][cnt]);

	dbg(ans);
	dbg(dp[n][ans.st][ans.nd]);
	// dbg(ant[n][ans.st][ans.nd]);
	for(int i = n; i > 0; i--) {
		if(ant[i][ans.st][ans.nd] < 0) {
			res[i] = -ant[i][ans.st][ans.nd];
			ans.nd--;
		} else {
			res[i] = cheap[ant[i][ans.st][ans.nd]][a[i]];
			ans.st ^= ant[i][ans.st][ans.nd];
		}
	}
	for(int i = 1; i <= n; i++) 
		cout << res[i] << ' ';
	cout << '\n';

}