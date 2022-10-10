#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	auto sum = [&](int l, int r)->long long{
		return pref[r] - pref[l];
	};
	multiset<long long, greater<>> value_set;
	map<int, tuple<long long, int, int>> set_by_pos;
	value_set.insert(sum(0, n));
	set_by_pos.insert({n, {sum(0, n), 0, n}});
	for(auto rep = 0; rep < n; ++ rep){
		int i;
		cin >> i, -- i;
		auto [s, l, r] = set_by_pos.upper_bound(i)->second;
		value_set.erase(value_set.find(s));
		set_by_pos.erase(r);
		value_set.insert(sum(l, i)), value_set.insert(sum(i + 1, r));
		set_by_pos.insert({i, {sum(l, i), l, i}}), set_by_pos.insert({r, {sum(i + 1, r), i + 1, r}});
		cout << *value_set.begin() << "\n";
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