#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> a(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i];
		}
		vector<int> dp(N);
		for(int i = N - 1; i >= 0; --i){
			dp[i] = a[i];
			if(i + a[i] < N){
				dp[i] += dp[i + a[i]];
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}