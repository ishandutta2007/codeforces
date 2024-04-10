#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long T;
	cin >> T;
	while(T--){
		long long N; cin >> N;
		long long ans = 0;
		vector<long long> p(N + 1);
		vector<pair<long long, long long>> op;
		p[N] = N / 2;
		for(long long i = N / 2; i > 1; --i){
			p[i] = i - 1;
			ans += (N - i) * (N - i);
			op.push_back({i, N});
		}
		p[1] = N / 2 + 1;
		for(long long i = N / 2 + 1; i < N; ++i){
			p[i] = i + 1;
			ans += (i - 1) * (i - 1);
			op.push_back({i, 1});
		}
		ans += (N - 1) * (N - 1);
		op.push_back({1, N});
		cout << ans << '\n';
		for(long long i = 1; i <= N; ++i){
			cout << p[i] << ' ';
		}
		cout << '\n';
		cout << (long long)op.size() << '\n';
		for(auto&i:op){
			cout << i.first << ' ' << i.second << '\n';
		}
	}
	return 0;
}