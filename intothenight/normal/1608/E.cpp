#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for(auto &[x, y, c]: a){
		cin >> x >> y >> c, -- c;
	}
	int res = numeric_limits<int>::min();
	for(auto _: ranges::iota_view(0, 4)){
		vector<int> xorder(n), yorder(n);
		iota(begin(xorder), end(xorder), 0);
		ranges::sort(xorder, [&](int u, int v){ return a[u][0] < a[v][0]; });
		iota(begin(yorder), end(yorder), 0);
		ranges::sort(yorder, [&](int u, int v){ return a[u][1] < a[v][1]; });
		auto check = [&](int amount)->bool{
			array<int, 3> color{0, 1, 2};
			do{
				int xl = [&]()->int{
					int i = 0, cnt = 0;
					while(cnt < amount){
						cnt += a[xorder[i]][2] == color[0];
						++ i;
					}
					return a[xorder[i - 1]][0] + 1;
				}();
				{ // vertical split
					int xr = [&]()->int{
						int j = 0, cnt = 0;
						while(j < n && cnt < amount){
							cnt += xl <= a[xorder[j]][0] && a[xorder[j]][2] == color[1];
							++ j;
						}
						return cnt == amount ? a[xorder[j - 1]][0] + 1 : numeric_limits<int>::min();
					}();
					if(xr != numeric_limits<int>::min() && amount <= ranges::count_if(a, [&](auto s){ return xr <= s[0] && s[2] == color[2]; })){
						return true;
					}
				}
				{ // horizontal split
					int yl = [&]()->int{
						int j = 0, cnt = 0;
						while(j < n && cnt < amount){
							cnt += xl <= a[yorder[j]][0] && a[yorder[j]][2] == color[1];
							++ j;
						}
						return cnt == amount ? a[yorder[j - 1]][1] + 1 : numeric_limits<int>::min();
					}();
					if(yl != numeric_limits<int>::min() && amount <= ranges::count_if(a, [&](auto s){ return xl <= s[0] && yl <= s[1] && s[2] == color[2]; })){
						return true;
					}
				}
			}while(ranges::next_permutation(color).found);
			return false;
		};
		ctmax(res, *ranges::partition_point(ranges::iota_view(1, n / 3 + 1), check) - 1);
		for(auto &[x, y, c]: a){
			tie(x, y) = pair{-y, x};
		}
	}
	cout << res * 3 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////