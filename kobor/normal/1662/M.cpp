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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		int mxa = 0;
		int mxb = 0;
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			mxa = std::max(mxa, a);
			mxb = std::max(mxb, b);
		}
		if(mxa + mxb > n){
			std::cout << "IMPOSSIBLE\n";
		}else{
			FOR(i, mxa) std::cout << "R";
			FOR(i, n - mxa) std::cout << "W";
			std::cout << "\n";
		}
	}

	return 0;
}