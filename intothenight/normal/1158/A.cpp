#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> b(n), g(m);
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	for(auto j = 0; j < m; ++ j){
		cin >> g[j];
	}
	if(*max_element(b.begin(), b.end()) > *min_element(g.begin(), g.end())){
		cout << "-1\n";
		return 0;
	}
	int mxb = *max_element(b.begin(), b.end());
	long long res = accumulate(b.begin(), b.end(), 0LL) * m + accumulate(g.begin(), g.end(), 0LL);
	b.erase(find(b.begin(), b.end(), mxb));
	res -= 1LL * mxb * (m - 1);
	if(any_of(g.begin(), g.end(), [&](int x){ return x == mxb; })){
		res -= mxb;
	}
	else{
		res -= *max_element(b.begin(), b.end());
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