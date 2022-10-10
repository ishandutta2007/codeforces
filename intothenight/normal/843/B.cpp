#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, start, x;
	cin >> n >> start >> x, -- start;
	int qcnt = 0;
	auto query = [&](int i){
		++ qcnt;
		if(qcnt == 1997) while(true) cout << endl;
		cout << "? " << i + 1 << endl;
		int x, j;
		cin >> x >> j;
		if(!~x) exit(0);
		if(j >= 0) -- j;
		return array{x, j};
	};
	auto answer = [&](int ans){
		cout << "! " << ans << endl;
		exit(0);
	};
	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	vector<int> t;
	sample(ind.begin(), ind.end(), back_inserter(t), 1500, rng);
	if(!binary_search(t.begin(), t.end(), start)){
		t.push_back(start);
	}
	int sz = (int)t.size();
	vector<array<int, 2>> a(sz);
	for(auto i = 0; i < sz; ++ i){
		a[i] = query(t[i]);
	}
	sort(a.begin(), a.end());
	if(a[0][0] >= x) answer(a[0][0]);
	int p = 0;
	while(p < sz - 1 && a[p + 1][0] < x) ++ p;
	for(auto i = a[p][1]; ~i; ){
		auto [y, j] = query(i);
		if(x <= y){
			answer(y);
		}
		i = j;
	}
	answer(-1);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////