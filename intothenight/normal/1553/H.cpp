#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	const int inf = numeric_limits<int>::max() / 4;
	const int minf = numeric_limits<int>::min() / 4;
	const int len = 1 << k;
	vector<int> mindist(len << 1, inf);
	vector<int> minval(len << 1, inf);
	vector<int> maxval(len << 1, minf);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(minval[x + len] != inf){
			mindist[x + len] = 0;
		}
		minval[x + len] = maxval[x + len] = 0;
	}
	vector<array<int, 2>> child(len);
	for(auto u = 1; u < len; ++ u){
		child[u] = {u << 1, u << 1 | 1};
	}
	auto fix = [&](int u)->void{
		mindist[u] = min({mindist[child[u][0]], mindist[child[u][1]], minval[child[u][1]] + (1 << k - 1 - __lg(u)) - maxval[child[u][0]]});
		minval[u] = min(minval[child[u][0]], minval[child[u][1]] + (1 << k - 1 - __lg(u)));
		maxval[u] = max(maxval[child[u][0]], maxval[child[u][1]] + (1 << k - 1 - __lg(u)));
	};
	for(auto u = len - 1; u; -- u){
		fix(u);
	}
	vector<int> res(len);
	res[0] = mindist[1];
	for(auto i = 1, u = 0; i < len; ++ i){
		int h = __lg(i - 1 ^ i - 1 >> 1 ^ i ^ i >> 1);
		for(auto u = 1 << h; u < 1 << h + 1; ++ u){
			swap(child[u][0], child[u][1]);
		}
		for(auto u = (1 << h + 1) - 1; u; -- u){
			fix(u);
		}
		res[u ^= 1 << k - 1 - h] = mindist[1];
	}
	for(auto x: res){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////