#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> cnt(k);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		cnt[x - 1] ++;
	}
	int res = 0;
	int rem = 0;
	for(auto x: cnt){
		res += x / 2 * 2;
		rem += x % 2;
	}
	cout << res + (rem + 1) / 2;
	return 0;
}