#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n), zcnt{0};
	for(auto &x: a){
		cin >> x;
		zcnt.push_back(zcnt.back() + !x);
	}
	int resL = 0, resR = 0;
	for(int i = 0; i < n; i ++){
		int l = i, r = n;
		while(r - l > 1){
			int m = (l + r) >> 1;
			zcnt[m + 1] - zcnt[i] <= k ? l = m : r = m;
		}
		if(zcnt[r] - zcnt[l] > k){
			r --;
		}
		if(r - i > resR - resL){
			resL = i, resR = r;
		}
	}
	cout << resR - resL << "\n";
	for(int i = 0; i < n; i ++){
		cout << (i >= resL && i < resR ? 1 : a[i]) << " ";
	}
	return 0;
}