#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


typedef tuple<int, int, int, int> tpl;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int a, b, c;
		cin >> a >> b >> c;
		tpl res{int(2e9), 0, 0, 0};
		for(int A = 1; A <= 10000; ++ A){
			for(int B = A; B <= 20000; B += A){
				int C;
				C = max(c / B * B, B);
				ctmin(res, tpl{abs(a - A) + abs(b - B) + abs(c - C), A, B, C});
				C += B;
				ctmin(res, tpl{abs(a - A) + abs(b - B) + abs(c - C), A, B, C});
			}
		}
		auto [dif, A, B, C] = res;
		cout << dif << "\n" << A << " " << B << " " << C << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////