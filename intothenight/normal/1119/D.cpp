#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<long long> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<long long> dif;
	for(auto i = 1; i < n; ++ i){
		dif.push_back(a[i] - a[i - 1]);
	}
	sort(dif.rbegin(), dif.rend());
	int qn;
	cin >> qn;
	vector<tuple<long long, long long, int>> q(qn);
	for(auto qi = 0; qi < qn; ++ qi){
		long long l, r;
		cin >> l >> r, ++ r;
		q[qi] = {r - l, l, qi};
	}
	sort(q.begin(), q.end());
	vector<long long> res(qn);
	long long delta = 0;
	for(auto [len, l, qi]: q){
		long long r = l + len;
		while(!dif.empty() && dif.back() <= len){
			delta += dif.back();
			dif.pop_back();
		}
		res[qi] = delta + len * ((int)dif.size() + 1);
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