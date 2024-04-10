#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> b(n + 1);
	array<int, 2> low{};
	for(auto i = 0; i < n; ++ i){
		b[i + 1] = b[i] + (s[i] == '(' ? 1 : -1);
		ctmin(low, array<int, 2>{b[i + 1], i + 1});
	}
	if(b[n]){
		cout << "0\n1 1\n";
		return 0;
	}
	b.pop_back();
	rotate(s.begin(), s.begin() + low[1], s.end());
	rotate(b.begin(), b.begin() + low[1], b.end());
	array<int, 3> res{};
	for(auto &x: b){
		x -= low[0];
		if(!x){
			++ res[0];
		}
	}
	int x = res[0];
	for(auto i = 0; i < n; ){
		int j = i + 1;
		while(j < n && b[j]){
			++ j;
		}
		int cnt1 = 0;
		for(auto k = i + 1; k < j; ++ k){
			if(b[k] == 1){
				++ cnt1;
			}
		}
		ctmax(res, array<int, 3>{cnt1, i, j - 1});
		for(auto l = i + 1; l < j - 1; ){
			int r = l + 1, cnt2 = 0;
			while(b[r] >= 2){
				if(b[r] == 2){
					++ cnt2;
				}
				++ r;
			}
			ctmax(res, array<int, 3>{x + cnt2, l, r - 1});
			l = r;
		}
		i = j;
	}
	cout << res[0] << "\n" << (res[1] + low[1]) % n + 1 << " " << (res[2] + low[1]) % n + 1 << "\n";
	return 0;
}

/*
6
((()))

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////