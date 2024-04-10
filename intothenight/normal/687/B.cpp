#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> factor;
	for(int p = 2; p * p <= k; p ++){
		if(k % p == 0){
			factor.push_back(1);
			while(k % p == 0){
				k /= p;
				factor.back() *= p;
			}
		}
	}
	if(k != 1){
		factor.push_back(k);
	}
	vector<bool> test(factor.size());
	while(n --){
		int c;
		cin >> c;
		for(int i = 0; i < factor.size(); i ++){
			if(c % factor[i] == 0){
				test[i] = true;
			}
		}
	}
	cout << (all_of(test.begin(), test.end(), [](bool x){return x;}) ? "Yes" : "No") << "\n";
	return 0;
}