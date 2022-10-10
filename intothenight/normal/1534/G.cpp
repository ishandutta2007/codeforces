#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto &[x, y]: a){
		cin >> x >> y;
		swap(x, y);
		x += y;
	}
	sort(a.begin(), a.end());
	pair<int, long long> left{-1, a[0][1]};
	multiset<int> neg{a[0][1]}, pos{a[0][1]};
	int shift = 0;
	for(auto i = 1; i < n; ++ i){
		static int prev = a[0][0];
		auto [sum, x] = a[i];
		shift += sum - prev;
		prev = sum;
		-- left.first;
		left.second += x;
		if(x <= *neg.rbegin()){
			pos.insert(*neg.rbegin() - shift);
			neg.erase(std::prev(neg.end()));
			neg.insert({x, x});
		}
		else if(x >= *pos.begin() + shift){
			neg.insert(*pos.begin() + shift);
			pos.erase(pos.begin());
			pos.insert({x - shift, x - shift});
		}
		else{
			neg.insert(x);
			pos.insert(x - shift);
		}
	}
	while(!neg.empty()){
		++ left.first;
		left.second -= *neg.begin();
		neg.erase(neg.begin());
	}
	assert(!left.first);
	cout << left.second << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////