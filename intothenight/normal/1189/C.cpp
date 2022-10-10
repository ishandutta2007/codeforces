#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> s(n);
	for(auto &x: s){
		cin >> x;
	}
	vector<int> bit(n + 1);
	for(int i = 0; i < n; i ++){
		int index = i + 1;
		while(index <= n){
			bit[index] += s[i];
			index += index & (-index);
		}
	}
	auto getsum = [&](int i){
		int index = i, res = 0;
		while(index > 0){
			res += bit[index];
			index -= index & (-index);
		}
		return res;
	};
	int qq;
	cin >> qq;
	while(qq --){
		int l, r;
		cin >> l >> r;
		cout << (getsum(r) - getsum(l - 1)) / 10 << "\n";
	}
	return 0;
}