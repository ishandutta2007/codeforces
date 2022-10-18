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
using VI = std::vector<int>;
using PII = std::pair<int, int>;

constexpr int INF = 2000000666;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	VI B(m);
	FOR(i, m) std::cin >> B[i];
	B.push_back(-INF);
	B.push_back(INF);
	std::sort(B.begin(), B.end());

	auto przed = [&](int x){
		auto it = std::lower_bound(B.begin(), B.end(), x);
		--it;
		return *it;
	};
	auto po = [&](int x){
		return *std::upper_bound(B.begin(), B.end(), x);
	};


	auto bad = [&](int l, int r){
		if(l == -1) return true;
		if(l > r) return false;
		ll pr = r * 100;
		ll pl = l * 100;
		ll prev = przed(pr+1);
		ll next = po(pl-1);
		if(prev >= pl) return true;
		ll most = pl + (pl - prev) - 1;
		ll least = pr - (next - pr) - 1;
		if(least <= most) return false;
		return true;
	};

	ll ans = 0;

	int l = -1;
	ll sum = 0;
	FOR(r, n){
		sum += A[r];
		while(bad(l, r)){
			if(l != -1) sum -= A[l];
			++l;
		}
		ans = std::max(ans, sum);
	}

	std::cout << ans << "\n";


	return 0;
}