#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, k;
		cin >> N >> k;
		for(int i = 1; i <= k - (N - k) - 1; ++i){
			cout << i << ' ';
		}
		for(int i = k - (N - k); i <= k; ++i){
			cout << k - (i - (k - (N - k))) << ' ';
		}
		cout << '\n';
	}
	return 0;
}