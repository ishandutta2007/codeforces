#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string y;
	cin >> n >> y;
	if(y == string(n, '0')){
		cout << n << "\n";
		return 0;
	}
	if(n == 1){
		cout  << "0\n";
		return 0;
	}
	vector<vector<int>> cnt(n);
	vector<int> divisor;
	for(int d = 1; d * d <= n; d ++){
		if(!(n % d)){
			divisor.push_back(d);
			for(int rem = 0; rem < d; rem ++){
				cnt[d].push_back(0);
				for(int q = 0; q < n / d; q ++){
					cnt[d][rem] += y[(rem + q * d) % n] - '0';
				}
			}
		}
	}
	vector<int> divisor2;
	for(auto it = divisor.rbegin(); *it != 1; it ++){
		int d = n / *it;
		if(d == *it){
			continue;
		}
		divisor2.push_back(d);
		for(int rem = 0; rem < d; rem ++){
			cnt[d].push_back(0);
			for(int q = 0; q < n / d; q ++){
				cnt[d][rem] += y[(rem + q * d) % n] - '0';
			}
		}
	}
	vector<bool> test(n);
	for(auto d: divisor){
		test[d] = all_of(cnt[d].begin(), cnt[d].end(), [](int x){return !(x & 1);});
	};
	for(auto d: divisor2){
		test[d] = all_of(cnt[d].begin(), cnt[d].end(), [](int x){return !(x & 1);});
	};
	function<int(int, int)> gcd = [&](int x, int y){
		if(!y){
			return x;
		}
		return gcd(y, x % y);
	};
	int res = 0;
	for(int k = 1; k < n; k ++){
		int g = gcd(n, k);
		res += test[g];
	}
	cout << res << "\n";
	return 0;
}