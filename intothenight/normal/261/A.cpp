#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int m;
	cin >> m;
	int q = numeric_limits<int>::max();
	for(auto i = 0; i < m; ++ i){
		int x;
		cin >> x;
		q = min(q, x);
	}
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	ranges::sort(a);
	int res = 0;
	while(!a.empty()){
		if((int)a.size() >= q + 2){
			res += accumulate(a.end() - q, a.end(), 0);
			a.resize(a.size() - q - 2);
		}
		else if((int)a.size() <= q){
			res += accumulate(a.begin(), a.end(), 0);
			a.clear();
		}
		else{
			res += accumulate(a.end() - q, a.end(), 0);
			a.clear();
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////