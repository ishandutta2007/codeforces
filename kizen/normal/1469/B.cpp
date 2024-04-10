#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N;
		vector<int> a(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i];
		}
		cin >> M;
		vector<int> b(M);
		for(int i = 0; i < M; ++i){
			cin >> b[i];
		}
		int sum = 0, ans = 0, big = 0;
		for(int i = 0; i < N; ++i){
			sum += a[i];
			big = max(big, sum);
		}
		ans += big;
		sum = big = 0;
		for(int i = 0; i < M; ++i){
			sum += b[i];
			big = max(big, sum);
		}
		ans += big;
		cout << ans << '\n';
	}
	return 0;
}