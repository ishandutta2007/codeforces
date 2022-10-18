#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto& i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
using ll = long long;
using PII = std::pair<int, int>;
using VI = std::vector<int>;

int tab[205][205];
ll pref[205][205];
ll dp[205][205];
int par[205][205];
int n;

ll sum(int l, int r, int d, int u){
	if(l > r) return 0ll;
	if(d > u) return 0ll;
	return pref[r][u] - pref[r][d-1] - pref[l-1][u] + pref[l-1][d-1];
}

ll get(int a, int b){
	if(a > b) return 0ll;
	return sum(1, a-1, a, b) + sum(b+1, n, a, b);
}

constexpr ll INF = 1000000555ll*1000000555ll;

int pp[205];

void rec(int a, int b, int pr=0){
	if(a > b) return;
	int md = par[a][b];
	pp[md] = pr;
	if(a == b) return;
	rec(a, md-1, md);
	rec(md+1, b, md);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	FOR(i, n){
		FOR(j, n){
			std::cin >> tab[i+1][j+1];
		}
	}

	FOR(i, n){
		FOR(j, n){
			pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + tab[i+1][j+1];
		}
	}

	FOR(i, 205) FOR(j, 205) dp[i][j] = INF, par[i][j] = -1;
	FOR(i, 205) FOR(j, 205) if(i >= j) dp[i][j] = 0;
	FOR(i, 205) par[i][i] = i;

	REP(len, 2, n+1){
		REP(l, 1, n+1){
			int r = l + len - 1;
			if(r > n) break;

			REP(mid, l, r+1){
				ll cand = dp[l][mid-1] + dp[mid+1][r] + get(l, mid-1) + get(mid+1, r);
				if(cand < dp[l][r]){
					dp[l][r] = cand;
					par[l][r] = mid;
				}
			}
		}
	}

	std::cerr << "VAL: " << dp[1][n] << "\n";

	rec(1, n);
	REP(i, 1, n+1) std::cout << pp[i] << " ";
	std::cout << "\n";

	return 0;
}