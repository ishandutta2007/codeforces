#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto query = [&](const vector<int> &a)->int{
		cout << "? ";
		for(auto x: a){
			cout << x << " ";
		}
		cout << endl;
		int ind;
		cin >> ind, -- ind;
		return ind;
	};
	vector<int> next, prev;
	for(auto x = 2; x <= n; ++ x){
		vector<int> a(n, 1);
		a.back() = x;
		int i = query(a);
		if(!~i){
			break;
		}
		next.push_back(i);
	}
	for(auto x = n - 1; x > 0; -- x){
		vector<int> a(n, n);
		a.back() = x;
		int i = query(a);
		if(!~i){
			break;
		}
		prev.push_back(i);
	}
	vector<int> order = prev;
	reverse(order.begin(), order.end());
	order.push_back(n - 1);
	order.insert(order.end(), next.begin(), next.end());
	vector<int> val(n);
	for(auto x = 0; x < n; ++ x){
		val[order[x]] = x + 1;
	}
	cout << "! ";
	for(auto x: val){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*
1 2 3 4
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////