#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int m, n;
	cin >> m >> n;
	vector<int> a(m);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int sum = 0, upper = 0;
	for(auto i = 0; i < n; ++ i){
		sum += a[i];
		upper += 2 * m - 2 - 2 * i;
		if(sum > upper){
			cout << "no\n";
			return 0;
		}
	}
	if(sum + a[n - 1] * (m - n) < m * (m - 1)){
		cout << "no\n";
		return 0;
	}
	int rem = m * (m - 1) - sum;
	for(auto i = n; i < m; ++ i){
		upper += 2 * m - 2 - 2 * i;
		a[i] = min({a[i - 1], rem, upper - sum});
		rem -= a[i];
		sum += a[i];
	}
	vector<string> res(m, string(m, 'X'));
	vector<int> order(m);
	iota(order.begin(), order.end(), 0);
	for(auto rep = 0; rep < m; ++ rep){
		int i = (int)order.size() - 1;
		for(; i >= (int)order.size() - a[order[0]] / 2; -- i){
			res[order[0]][order[i]] = 'W';
			res[order[i]][order[0]] = 'L';
		}
		if(a[order[0]] & 1){
			res[order[0]][order[i]] = res[order[i]][order[0]] = 'D';
			-- a[order[i]];
			-- i;
		}
		for(; i >= 1; -- i){
			res[order[0]][order[i]] = 'L';
			res[order[i]][order[0]] = 'W';
			a[order[i]] -= 2;
		}
		order.erase(order.begin());
		sort(order.begin(), order.end(), [&](int i, int j){ return a[i] > a[j]; });
	}
	cout << "yes\n";
	for(auto s: res){
		cout << s << "\n";
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